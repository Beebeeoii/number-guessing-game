#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HISTORY_SIZE 100

void initialiseGameEngine();
void endGame(int, int, int *, time_t, time_t);
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

    int nGuess = 0;
    int answer = generateRandomInRange(lowerBound, upperBound);
    int userInput;
    int history[HISTORY_SIZE];

    time_t start, end;
    float timeTaken;

    time(&start);

    do {
        if (nGuess == HISTORY_SIZE) {
            time(&end);
            printf("Wow sir you are very determined ! But unfortunately you have spent too much time on this and we should move on with life\n\n");
            break;
        }
        printf("Please input an integer between %d - %d\n\n", lowerBound, upperBound);
        scanf("%d", &userInput);

        while (!isGuessValid(userInput, lowerBound, upperBound)) {
            printf("Invalid guess!\nGuess BETWEEN %d - %d\n\n", lowerBound, upperBound);
            scanf("%d", &userInput);
        }
        
        history[nGuess] = userInput;
        nGuess ++;

        if (userInput == answer) {
            time(&end);
            history[nGuess] = -1;
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

    endGame(answer, nGuess, history, start, end);

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

void endGame(int answer, int nGuess, int *history, time_t start, time_t end) {
    printf("----- Game Review -----\n");
    printf("Answer: %d\n", answer);
    printf("No. guesses: %d\n", nGuess);
    printf("Your guesses:");
    for (int i = 0; i < HISTORY_SIZE; i++) {
        if (history[i] == -1) {
            printf("\n");
            break;
        }

        printf(" %d", history[i]);
    }

    printf("Time taken: %ds\n", (int) difftime(end, start));
    printf("Grade: %c\n", generateGrade(nGuess));
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

char generateGrade(int nGuess) {
    int counter = 0;
    int range = ORIGINAL_UPPER_BOUND - ORIGINAL_LOWER_BOUND;

    while (range != 0) {
        range /= 2;
        counter ++;
    }

    int deviation = nGuess - counter;

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