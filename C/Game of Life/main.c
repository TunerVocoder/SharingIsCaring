#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char**        inputFile(char *fileName, char (*board)[40])
{
    printf("Processing %s.", fileName);
    return(board);
}

int         main(int argc, char **argv)
{
    char    board[20][40] = {{0}};
    
    if(argc > 20)
    {
        printf("Lines should not exceed 20. \n");
        return(1);
    }
    
    inputFile(argv[1], board);
    
    return(0);
}