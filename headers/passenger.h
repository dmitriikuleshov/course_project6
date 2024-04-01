#ifndef PASSENGER_H
#define PASSENGER_H

#define MAX_NAME_LENGTH 100
#define MAX_SURNAME_LENGTH 100
#define INITIALS_MAX_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_SURNAME_LENGTH];
    char initials[INITIALS_MAX_LENGTH];
    int luggageAmount;
    int totalWeight;
    char destination[50];
    char boardTime[6];
    int hasTransitions;
    int childrenAmount;
} Passenger;

#endif //PASSENGER_H