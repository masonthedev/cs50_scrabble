#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculate_score(string player);
void win_or_draw(int player1score, int player2score);

int main(void)
{
    // Get player 1 and player 2 input.
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // determine word value (compute score of each word)
    int player1score = calculate_score(player1);
    int player2score = calculate_score(player2);
    
    // Print winner or tie
    win_or_draw(player1score, player2score);
}

// iterate over characters to calculate score of played word

int calculate_score(string player)
{
    int score = 0;
    for (int i = 0; i < strlen(player); i++)
    {
        switch (toupper(player[i]))
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'L':
            case 'N':
            case 'R':
            case 'S':
            case 'T':
                score += 1;
                break;

            case 'D':
            case 'G':
                score += 2;
                break;

            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score += 3;
                break;

            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                score += 4;
                break;

            case 'K':
                score += 5;
                break;

            case 'J':
            case 'X':
                score += 8;
                break;

            case 'Q':
            case 'Z':
                score += 10;
                break;
        }
    }
    return score;
}

// Determine winner of the game

void win_or_draw(int player1score, int player2score)
{
    if (player1score > player2score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1score < player2score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
