#include <stdio.h>
#include <stdlib.h>

void        init(int board[50][50])
{
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    
    while(i < 50)
    {
        while(j < 50)
        {
            board[i][j] = 0;
            j++;
        }
        i++;
        j = 0;
    }
}

void        copy(int board[50][50], int cibleBoard[50][50])
{
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    
    while(i < 50)
    {
        while(j < 50)
        {
            cibleBoard[i][j] = board[i][j];
            j++;
        }
        i++;
        j = 0;
    }
}

void        display(int board[50][50])
{
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    
    while(i < 50)
    {
        while(j < 50)
        {
            if(board[i][j] == 1)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
            j++;
        }
        printf("\n");
        i++;
        j = 0;
    }
}

int         main()
{
    int     initBoard[50][50];
    int     nextBoard[50][50];
    int     i;
    int     j;
    int     sum;
    
    i = 1;
    j = 1;
    sum = 0;
    
    init(initBoard);
    init(nextBoard);
    
    initBoard[25][25] = 1;
    initBoard[25][26] = 1;
    initBoard[27][26] = 1;
    initBoard[26][28] = 1;
    initBoard[25][29] = 1;
    initBoard[25][30] = 1;
    initBoard[25][31] = 1;
    
    while(1)
    {
        while(i < 49)
        {
            while(j < 49)
            {
                sum = initBoard[i - 1][j - 1] + initBoard[i - 1][j] + initBoard[i - 1][j + 1] + initBoard[i][j - 1] + initBoard[i][j + 1] + initBoard[i + 1][j - 1] + initBoard[i + 1][j] + initBoard[i + 1][j + 1];
                nextBoard[i][j] = ((sum == 3) || (sum == 2 && initBoard[i][j] == 1));
                j++;
            }
            j = 1;
            i++;
        }
        i = 1;
        display(nextBoard);
        copy(nextBoard, initBoard);
        usleep(200000);
    }
}