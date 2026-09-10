#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// function for medium level (array passed using [] notation, not pointer syntax)
void mediumLevel(char sentences[][100], int total) {
    char ch[512];
    int correct;

    for (int i = 0; i < total; i++) {
        correct = 0;
        while (!correct) {
            printf("\nType this: %s\n> ", sentences[i]);
            fgets(ch, sizeof(ch), stdin);
            ch[strcspn(ch, "\n")] = '\0';

            if (strcmp(ch, sentences[i]) == 0) {
                printf("Correct!\n");
                correct = 1;
            } else {
                printf("Wrong, try again.\n");
            }
        }
    }
}

// function for advanced level (same structure, separate function)
void advancedLevel(char sentences[][100], int total) {
    char ch[512];
    int correct;

    for (int i = 0; i < total; i++) {
        correct = 0;
        while (!correct) {
            printf("\nType this: %s\n> ", sentences[i]);
            fgets(ch, sizeof(ch), stdin);
            ch[strcspn(ch, "\n")] = '\0';

            if (strcmp(ch, sentences[i]) == 0) {
                printf("Correct!\n");
                correct = 1;
            } else {
                printf("Wrong, try again.\n");
            }
        }
    }
}

int main(void)
{
    int choice, i, round, correct;
    char ch[512];
    char randomLetters[10];

    char medium[5][100] = {
        "programming is fun and challenging",
        "practice makes a person perfect",
        "the weather is nice today",
        "i am learning how to type fast",
        "success comes from hard work and patience"
    };
    int totalMedium = 5;

    char advanced[5][100] = {
        "Hello, World! Welcome to C programming.",
        "My phone number is 987-654-3210.",
        "She said, I will be there by 5:00 PM.",
        "C is a powerful language, it teaches you the basics.",
        "Typing speed improves with regular practice, 10 minutes a day!"
    };
    int totalAdvanced = 5;

    srand(time(NULL)); // seed random generator once

    printf("==========================================\n");
    printf("   WELCOME TO THE TYPING PRACTICE PROGRAM\n");
    printf("==========================================\n\n");

    printf("HOW TO PLAY:\n");
    printf("1. A line of text will be shown to you on the screen.\n");
    printf("2. Type that exact same text using your keyboard.\n");
    printf("3. Press ENTER when you are done typing.\n");
    printf("4. If you typed it correctly, you move to the next line.\n");
    printf("5. If you made a mistake, you will be asked to try again.\n");
    printf("6. Keep practicing until you complete all the lines.\n\n");

    printf("Press ENTER to start...\n");
    getchar();

    printf("Choose your level\n");
    printf("1. Beginner (random letters)\n");
    printf("2. Medium (sentences)\n");
    printf("3. Advanced (tougher sentences)\n");
    scanf("%d", &choice);
    getchar(); // clear leftover newline from scanf

    switch (choice) {

        case 1: // Beginner - random letters, done inline, no function
            for (round = 0; round < 5; round++) {

                for (i = 0; i < 5; i++) {
                    randomLetters[i] = 'a' + (rand() % 26);
                }
                randomLetters[5] = '\0';

                correct = 0;
                while (!correct) {
                    printf("\nType this: %s\n> ", randomLetters);
                    fgets(ch, sizeof(ch), stdin);
                    ch[strcspn(ch, "\n")] = '\0';

                    if (strcmp(ch, randomLetters) == 0) {
                        printf("Correct!\n");
                        correct = 1;
                    } else {
                        printf("Wrong, try again.\n");
                    }
                }
            }
            break;

        case 2: // Medium - uses function
            mediumLevel(medium, totalMedium);
            break;

        case 3: // Advanced - uses function
            advancedLevel(advanced, totalAdvanced);
            break;

        default:
            printf("Invalid choice.\n");
    }

    printf("\nYou finished the level! Great job.\n");
    return 0;
}
