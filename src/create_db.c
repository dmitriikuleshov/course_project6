#include <stdio.h>
#include "../headers/passenger.h"


int main(int argc, char* argv[]){
    if (argc != 3){
        printf("%d", argc);
        return 0;
    }

    FILE* fileToRead = fopen(argv[1], "r");
    if (!fileToRead){
        printf("Can't open file %s. Returning", argv[1]);
        return 0;
    }

    FILE* fileToWrite = fopen(argv[2], "w");
    if (!fileToWrite){
        printf("Can't open file %s. Returning", argv[2]);
        return 0;
    }

    Passenger p;
    while (fscanf(fileToRead, "%s %s %d %d %s %s %d %d", p.name, p.surname, &p.luggageAmount, &p.totalWeight, p.destination, p.boardTime, &p.hasTransitions, &p.childrenAmount) == 8 ) {
        snprintf(p.initials, INITIALS_MAX_LENGTH, "%c. %c.", p.name[0], p.surname[0]);
        fwrite(&p, sizeof p, 1, fileToWrite);
    }

    fclose(fileToRead);
    fclose(fileToWrite);
    return 0;
}
