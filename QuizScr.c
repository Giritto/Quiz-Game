#include <stdio.h>
#include <ctype.h>

int playGame() {
    char questions[][250] = {"1. What year was Ruby conceived?: ",
                             "2. Who invented the C language?: ",
                             "3. What is the last name of the person who invented Linux?: ",
                             "4. What language is known as C with classes?: ",
                             "5. Which programming language has a crab called Ferris as a mascot?: "};

    char options[][100] = {"A. 1993", "B. 1990", "C. 1992", "D. 1995",
                           "A. Linus Torvalds", "B. Bjarne Stroustrup", "C. Dennis Ritchie", "D. Graydon Hoare",
                           "A. Newell", "B. Brin", "C. Page", "D. Torvalds",
                           "A. Java", "B. Python", "C. Objective C", "D. C++",
                           "A. Python", "B. Rust", "C. Kotlin", "D. Perl"};

    char answers[5] = {'A', 'C', 'D', 'D', 'B'};
    int numberOfQuestions = sizeof(questions) / sizeof(questions[0]);

    char guess;
    int score = 0;

    printf ("QUIZ TIME!\n\n");

    for (int i = 0; i < numberOfQuestions; i++)
    {
        printf ("*********************\n");
        printf ("%s\n", questions[i]);
        printf ("*********************\n");

        for (int j = 0; j < 4; j++)
        {
            printf ("%s\n", options[i * 4 + j]);
        }

        do {
            printf ("guess: ");
            scanf (" %c", &guess);
            scanf ("%*c"); //clear \n from input buffer
            guess = toupper(guess);

            if (guess != 'A' && guess != 'B' && guess != 'C' && guess != 'D') {
                printf("Invalid answer, try again.\n");
            }
        } while (guess != 'A' && guess != 'B' && guess != 'C' && guess != 'D');

        if (guess == answers[i])
        {
            printf ("\nCORRECT!\n");
            score++;
        }
        else
        {
            printf ("WRONG!\n");
        }
    }

    printf ("*********************\n");
    printf ("FINAL SCORE: %d/%d\n", score, numberOfQuestions);

    if (score <= 3)
    {
        printf("Better luck next time!\n");
    }
    else
    {
        printf("Congratulations!\n");
    }
    printf("*********************\n");

    char response;
    printf("Do you want to play again? (Y/N): ");
    do {
        response = getchar();
        response = toupper(response);
    } while (response != 'Y' && response != 'N');

    return (response == 'Y'); // Return 1 if 'Y' is pressed, 0 if 'N' is pressed
}

int main() {
    int playAgain = 1; // Set to 1 to start the game

    while (playAgain) {
        playAgain = playGame(); // Call playGame function

        if (playAgain) {
            printf("*********************\n");
            printf("Let's play again!\n\n");
        } else {
            printf("\nThanks for playing. Goodbye!\n");
        }
    }

    return 0;
}
