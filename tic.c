# include <stdio.h>

void drawBoard();
void twoPlayers();
void getMove(char currentPlayer);
bool checkEmpty( int i, int j);
void setMove(char currentPlayer, int i, int j);
void saveMove(char currentPlayer);

//easier to evaluate valid & win positions tho it may be slower than just a 1d char array
//global because i'd be passing it to so many lil functions i think it's worth it
char board[3][3];


int main(void)
{
    //try maybe doing it w also just the 1d array from 1-9



    // drawBoard(board);

    printf("Welcome to Tic Tac Toe\n");
    printf("Are you playing with one or two players? (1/2)\n");

    //not a bool for simplicity of input
    int players;
    scanf("%d", &players);

    while(players != 1 && players != 2)
    {
        printf("Invalid option %d entered, please pick 1 or 2\n", players);

        scanf("%d", &players);
    }

    if (players == 1)
    {
        printf("One player selected, X (player) moves first: \n");

        //1player
    }
    else
    {
        printf("Two players selected, X moves first: \n");
        twoPlayers();
    }

    // int array[MAX];
    // display(array);
    return 0;
}


void drawBoard()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]  );
        }
        putchar('\n');
    }
}

void twoPlayers()
{
    printf("Invalid option entered, please pick 1 or 2\n");

    //didn't use a bool since char takes up the same amt of space in practice and i'd have to have an if operation to put the char in anyway
    char currentPlayer = 'X';

    while(!checkWin)
    {
        getMove(currentPlayer);
    }
    endGame();
}

void getMove(char currentPlayer)
{
    int i;
    int j;

    printf("%c's turn\n", currentPlayer);

    printf("Enter the row and column number you want to occupy separated by a space: \n");
    scanf("%d %d", &i, &j);

    if (checkEmpty(i, j))
    {
        setMove(currentPlayer, i, j)
    }

    if (currentPlayer == 'X')
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer == 'X'
    }
}

bool checkEmpty( int i, int j)
{
    if (board[i - 1][j - 1] == NULL || board[i - 1][j - 1] == '')
    {
        return true;
    }
    return false;
}

void setMove(char currentPlayer, int i, int j)
{
    if (currentPlayer)
    {
        board[i - 1][j - 1] = currentPlayer;
    }
    else
    {
        board[i - 1][j - 1] = currentPlayer;
    }
    saveMove(char currentPlayer, int i, int j);
}

void saveMove(char currentPlayer, int i, int j)
{
    int moves[9]; //max amount of moves in game

};

bool checkWin()
{
    //rows
    for (i = 0; i < 3; i++)
    {
        if (board[i], [1] == board[i], [0] && board[i], [1] == board[2])
        {
            return true;
        }
    }

    //columns
    for (j = 0; j < 3; j++)
    {
        if (board[1], [j] == board[0][j]
                && board[i], [1] == board[2][j])
        {
            return true;
        }
    }

    //i could be implementing some check on whether there are any moves left but
    //diagonals
    for (int i = 0; i < 3; ++i)
    {
        //some for loop nonsense cld have been done here but it's too much hassle
        if ((board[1][1] == board[0][0] && board[1][1] == board[2][2]) || (board[1][1] == board[2][0] && board[1][1] == board[0][2]))
        {
            return true
        }
    }

    return false;
}

void endGame(char winner)
{
    printf("%c Wins!\n", currentPlayer);
    printf("Play again? (y/n)\n");
    scanf("%c", char playAgain);

    if (playAgain == 'y')
    {
        main();
    }
    else
    {
        printf("Thanks for playing!\n");
        exit();
    }

}