#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "../headers/passenger.h"

void printPassenger(Passenger* passenger){
        printf("%-8s %-8s %-4s %-8d %-8d %-8s %-8s %-8d %-8d\n",
               passenger->name,
               passenger->surname,
               passenger->initials,
               passenger->luggageAmount,
               passenger->totalWeight,
               passenger->destination,
               passenger->boardTime,
               passenger->hasTransitions,
               passenger->childrenAmount);
}

int main(int argc, char* argv[]){
    int printFile = 0;
    int isNextPValue = 0;
    int p = -1;
    char *path;
    for (int i = 0; i < argc; ++i){
        if (!strcmp(argv[i], "-f")){
            printFile = 1;
            continue;
        }

        if (!strcmp(argv[i], "-p") && p == -1){
            isNextPValue = 1;
            continue;
        }

        if (isNextPValue){
            isNextPValue = 0;
            p = atoi(argv[i]);
            continue;
        }

        path = argv[i];
    }

    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Can't open file (%s)\n", path);
        return 0;
    }

    int bagsAmount = 0;
    int peopleCount = 0;
    Passenger passenger;
    int empty_table = 1;
    while (fread(&passenger, sizeof passenger, 1, file) == 1){
        if (printFile){
            if (empty_table) {
                empty_table = 0;
                printf("%-8s %-8s %-4s %-8s %-8s %-8s %-8s %-8s %-8s\n", "Name", "Surname", "Init", "Luggage", "Weight", "Dest", "Board", "Trans", "Children");     
            }
            printPassenger(&passenger);
        }
        bagsAmount += passenger.luggageAmount;
        peopleCount++;

    }
    printf("\n");
    if (peopleCount == 0){
        printf("No items in file. Closing...\n");
        return 0;
    }

    fseek(file, 0, SEEK_SET);
    double middle_luggage = (double)(bagsAmount) / (double)(peopleCount);

    int nothing_found_flag = 1;
    while (fread(&passenger, sizeof passenger, 1, file) == 1){
        if (passenger.luggageAmount > middle_luggage + p){
            if (nothing_found_flag){
                printf("Query result (middle luggage = %f):\n", middle_luggage);
                nothing_found_flag = 0;
            }
            printf("\t");
            printPassenger(&passenger);
        }
    }
    if (nothing_found_flag) {
        printf("Not a single passenger is suitable (middle luggage = %f)", middle_luggage);
    }

    fclose(file);
    return 0;
}
