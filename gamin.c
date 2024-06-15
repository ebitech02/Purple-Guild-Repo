#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//Prototypes of my functions

void print_help();
int get_computer_choice();
const char* convert_choice_to_string(int choice);
int choose_winner(int user_choice, int computer_choice);


int main(void)
{
    char input[10];
    int user_choice;
    int computer_choice;
    int result;

    srand(time(NULL));

    printf("Welcome to Rock-Paper-Scissors! Type help for instructions on how to play.\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%s", input);

        if (strcmp(input, "help") == 0)
        {
            print_help();
            continue;
        } else if (strcmp(input, "quit") == 0)
        {
            break;
        } else if 
        (strcmp(input, "rock") == 0)
        {
            user_choice = 0;
        } else if (strcmp(input, "paper") == 0)
        {
            user_choice = 1;
        } else if (strcmp(input, "scissors") == 0)
        {
            user_choice = 2;
        } else {
            printf("Invalid choice - type help for more info about the game\n");
            continue;
        }


    computer_choice = get_computer_choice();
    printf("Computer chose: %s\n", convert_choice_to_string(computer_choice));

    result = choose_winner(user_choice, computer_choice);

    if (result == 0)
    {
        printf("It's a Tie :(\n");
    } else if (result == 1)
    {
        printf("Yay You Win :)\n");
    } else 
    {
        printf("Sorry, you lose :() \n");
    }
    }

    printf("Thank you for playing\n");
    return (0);
}

void print_help()
{
    printf("Rock-Paper-Scissors Game: \n");
    printf("Commands:\n");
    printf("   rock     - Choose Rock\n");
    printf("   paper    - Choose Paper\n");
    printf("   scissors - Choose Scissors\n");
    printf("   help     - Show help message\n");
    printf("   quit     - Exit the game\n");
    printf("Rules:\n");
    printf("   Rock beats Scissors\n");
    printf("   Scissors beat Paper\n");
    printf("   Paper beats Rock\n");

}

int get_computer_choice()
{
    // C is 0 index based so 0 for rock, 1 for paper, 2 for scissors
    return rand() % 3;
}

const char* convert_choice_to_string(int choice)
{
    switch (choice){
        case 0: return "rock";
        case 1: return "paper";
        case 2: return "scissors";
        default: return "-please type help then press enter for info about the game";
    }
}

int choose_winner(int user_choice, int computer_choice)
{
    if (user_choice == computer_choice)
    {
        return (0);
    } else if ((user_choice == 0 && computer_choice == 2) ||
    (user_choice == 1 && computer_choice == 0) ||
    (user_choice == 2 && computer_choice == 1))
    {
        //user wins
        return (1);
    } else {
        //computer wins
        return (-1);
    }
}

