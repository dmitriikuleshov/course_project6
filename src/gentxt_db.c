#include <stdio.h>
#include <stdlib.h>
#include <time.h> //srand()
#include <string.h>
#include <unistd.h>
#include "../headers/passenger.h"


void generate_random_string(char *str, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length - 1; ++i) {
        int index = rand() % (sizeof(charset) - 1);
        str[i] = charset[index];
    }
    str[length - 1] = '\0';
}


void generate_random_time(char *str) {
    int hours = rand() % 24;
    int minutes = rand() % 60;
    sprintf(str, "%02d:%02d", hours, minutes);
}


int generate_random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}


void generate_and_write_table(const char *filename, int num_passengers) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    // Generate random passenger data and write it to the file
    for (int i = 0; i < num_passengers; ++i) {
        Passenger passenger;

        generate_random_string(passenger.name, 10);
        generate_random_string(passenger.surname, 10);

        passenger.luggageAmount = generate_random_number(1, 5);
        passenger.totalWeight = generate_random_number(1, 50);

        generate_random_string(passenger.destination, 10);

        generate_random_time(passenger.boardTime);

        passenger.hasTransitions = rand() % 2;

        passenger.childrenAmount = generate_random_number(0, 3);

        fprintf(file, "%s %s %d %d %s %s %d %d\n", passenger.name, passenger.surname, passenger.luggageAmount, passenger.totalWeight, passenger.destination, passenger.boardTime, passenger.hasTransitions, passenger.childrenAmount);
    }

    fclose(file);

    printf("Table successfully written to file: %s\n", filename);
}

int main(int argc, char *argv[]) {
    char *filename = NULL;
    int num_passengers = -1;

    // Process command line arguments using getopt
    int opt;
    while ((opt = getopt(argc, argv, "f:p:")) != -1) {
        switch (opt) {
            case 'f':
                filename = optarg;
                break;
            case 'p':
                num_passengers = atoi(optarg);
                break;
            default: /* '?' */
                fprintf(stderr, "Usage: %s -f <filename> -p <number_of_passengers>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Check if all required arguments are provided
    if (filename == NULL || num_passengers == -1) {
        fprintf(stderr, "Usage: %s -f <filename> -p <number_of_passengers>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initialize the random number generator using the current time as the seed
    srand(time(NULL));

    // Call the function to generate and write a random table of data to the file
    generate_and_write_table(filename, num_passengers);

    return 0;
}