#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialiseGameEngine();
int generateRandomInRange(int, int);
int isUpperBoundValid(int, int);
int isGuessValid(int, int, int);
char generateGrade(int);

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
        printf("Please input an integer between %d - %d\n\n", lowerBound, upperBound);
        scanf("%d", &userInput);

        while (!isGuessValid(userInput, lowerBound, upperBound)) {
            printf("Invalid guess!\nGuess BETWEEN %d - %d\n\n", lowerBound, upperBound);
            scanf("%d", &userInput);
        }
        
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
    printf("Grade: %c\n", generateGrade(nGuess));

    return 0;
}

void initialiseGameEngine() {
    printf("Welcome to: Guess the Number!\n");

    printf("Please enter the LOWER boundary:\n");
    scanf("%d", &lowerBound);
    ORIGINAL_LOWER_BOUND = lowerBound;

    do {
        printf("Please enter the UPPER boundary:\n");
        scanf("%d", &upperBound);

        ORIGINAL_UPPER_BOUND = upperBound;
    } while (!isUpperBoundValid(lowerBound, upperBound));
}

int isUpperBoundValid(int lowerBound, int upperBound) {
    return upperBound > lowerBound + 1;
}

int isGuessValid(int guess, int lowerBound, int upperBound) {
    return guess > lowerBound && guess < upperBound;
}

int generateRandomInRange(int lowerBound, int upperBound) {
    srand(time(0));
    return (rand() % (lowerBound - upperBound + 1)) + lowerBound + 1;
}

char generateGrade(int nGuesses) {
    int counter = 0;
    int range = ORIGINAL_UPPER_BOUND - ORIGINAL_LOWER_BOUND;

    while (range != 0) {
        range /= 2;
        counter ++;
    }

    int deviation = nGuesses - counter;

    if (deviation <= 3) {
        return 'A';
    } else if (deviation <= 7) {
        return 'B';
    } else if (deviation <= 12) {
        return 'C';
    } else if (deviation <= 20) {
        return 'D';
    }

    return 'F';
}