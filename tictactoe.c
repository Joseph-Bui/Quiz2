#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void restartGame();
void printBoard();
int checkSpace();
void playersMove();
void computersMove();
char checkWinner();
void printWinnter(char);

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

int main()
{
    char winner = ' ';

    //prompt user to choose game mode
    printf("======================\n");
    printf("WELCOME TO TIC TAC TOE!\n");
    printf("1 -- person vs. person\n");
    printf("2 -- person vs. random computer\n");
    printf("Enter your choice (1 or 2)\n");
    printf("======================\n");

    //print the board and prompt user to play. 
    resetGame();
    while(winner == ' ' && checkSpace() != 0)
    {
        printBoard();

        playersMove();
        winner = checkWinner();
        if(winner != ' ' || checkSpace == 0)
        {
            break;
        }

        computersMove();
        winner = checkWinner();
        if(winner != ' ' || checkSpace == 0)
        {
            break;
        }
    }

    //repeat until there is a winner or draw.
    printBoard();
    printWinner(winner);

    return 0;
}

void restartGame()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    printf("The current status is:\n");
    printf("+-----------+\n");
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n+-----------+\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[2][2]);
    printf("+-----------+\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n+-----------+\n");
}
int checkSpace()
{
    int spaces = 9;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                spaces--;
            }
        }
    }
    return spaces;
}

void playersMove()
{
    int row, column;

    printf("Player 1: make your move");
    scanf("%d", &row);
    row--;
    scanf("%d", &column);
    column--;

    do
    {
        if(board[row][column] != ' ')
        {
        printf("Position occupied.\n");
        }
    
        else
        {
        board[row][column] = PLAYER;
        printf("Good!\n");
        break;
        }
    } 
    while (board[row][column] != ' ');

}
void computersMove()
{
    srand(time(0));
    int row, column;

    if(boardStatus() > 0)
    {
        do
        {
            row = rand() % 3;
            column = rand() % 3;
        } while (board[row][column] != ' ');
        
        board[row][column] = COMPUTER;
    }

    else
    {
        printWinner(' ');
    }
}
char checkWinner()
{
    //checking the rows for three in a row
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    //checking the columns for three in a row
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    //checking for diagonal win conditions
     if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }
     if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return board[0][2];
        }
    
    return ' ';
}
void printWinner(char winner)
{
    if(checkWinner == PLAYER)
    {
        printf("Player wins!");
    }

    else if(checkWinner == COMPUTER)
    {
        printf("Computer wins!");
    }

    else
    {
        printf("draw");
    }
}