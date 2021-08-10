#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialiseGameEngine();
int generateRandomInRange(int, int);
char* generateGrade(int);

int ORIGINAL_LOWER_BOUND;
int ORIGINAL_UPPER_BOUND;
int lowerBound;
int upperBound;

int main() {
    initialiseGameEngine();

    int nGuess = 1;
    int answer = generateRandomInRange(lowerBound, upperBound);
    int userInput;

    do {
        printf("Please input an integer between %d - %d\n", lowerBound, upperBound);
        scanf("%d", &userInput);
        nGuess ++;

        if (userInput == answer) {
            printf("Wow sir you are how good !\n\n");
            break;
        }

        if (userInput < answer) {
            lowerBound = userInput;
        } else {
            upperBound = userInput;
        }

        printf("Hmm just a lil short from the actual answer!\n\n");
    } while(userInput != answer);

    printf("----- Game Review -----\n");
    printf("Answer: %d\n", answer);
    printf("No. guesses: %d\n", nGuess);
    printf("Grade: %s\n", generateGrade(nGuess));

    return 0;
}

void initialiseGameEngine() {
    printf("Welcome to: Guess the Number!\n");

    printf("Please enter the LOWER boundary:\n");
    scanf("%d", &lowerBound);
    ORIGINAL_LOWER_BOUND = lowerBound;

    printf("Please enter the UPPER boundary:\n");
    scanf("%d", &upperBound);
    ORIGINAL_UPPER_BOUND = upperBound;
}

int generateRandomInRange(int lowerBound, int upperBound) {
    srand(time(0));
    return (rand() % (lowerBound - upperBound + 1)) + lowerBound;
}

char* generateGrade(nGuesses) {
    int counter = 0;
    int range = ORIGINAL_UPPER_BOUND - ORIGINAL_LOWER_BOUND;

    while (range != 0) {
        range /= 2;
        counter ++;
    }

    if (nGuesses < counter) {
        return "A+";
    }

    switch (nGuesses - counter) {
        case 0 ... 3:
            return "A";
        case 4 ... 7:
            return "B";
        case 8 ... 12:
            return "C";
        case 13 ... 20:
            return "D";
        default:
            return "F";
    }
}