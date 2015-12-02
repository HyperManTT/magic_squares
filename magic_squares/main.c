//
//  main.c
//  magic_squares
//
//  Created by Randy Ram on 02/12/2015.
//  Copyright © 2015 Randy Ram. All rights reserved.
//

#include <stdio.h>

void printMagicSquare(int size, int magic[][size])
{
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            printf("%d ", magic[i][j]);
        }
        printf("\n");
    }
}

void gen_odd(int size)
{
    int squares_filled = 1;
    int magic[size][size];
    for(int i = 0;i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            magic[i][j] = -1;
        }
    }
    int i = 0;
    int j = size/2;
    magic[0][j] = 1;
    while(squares_filled <= size * size)
    {
        i = i - 1; //Go one row up
        j = j + 1; //Go one column across
        //Check if we have gone off the top leftmost edge
        if (i < 0 && j > size - 1)
        {
            i = 1;
            j = size - 1;
        }
        //Off the top
        else if (i < 0)
        {
            i = size - 1;
        }
        //Off the right
        else if (j > size - 1)
        {
            j = 0;
        }
        //Occupied position already
        else if(magic[i][j] != -1)
        {
            i = i + 2;
            j = j - 1;
        }
        magic[i][j] = squares_filled + 1;
        squares_filled++;
    }
    
    printMagicSquare(size, magic);
}


void gen_doubly_even(size)
{
    int magic[size][size];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            magic[i][j] = -1;
        }
    }
    
    int dim1 = size / 2;
    int dim2 = size / 4;
    int row = 0;
    int col = dim2;
    //First rectangle
    while (row < dim2)
    {
        for(int i = col; i < dim1 + dim2; i++)
        {
            magic[row][i] = 0;
        }
        row++;
    }
    
    //Second Rectangle
    row = size - 2;
    col = dim2;
    while (row < size)
    {
        for(int i = col; i < dim1 + dim2; i++)
        {
            magic[row][i] = 0;
        }
        row++;
    }
    
    //3rd Rectangle
    row = dim2;
    col = 0;
    int k = 0;
    while(k < dim1)
    {
        for(int i = col; i < dim2; i++)
        {
            magic[row][i] = 0;
        }
        row++;
        k++;
    }
    
    //4th Rectangle
    row = dim2;
    col = size - dim2;
    k = 0;
    while(k < dim1)
    {
        for(int i = col; i < size; i++)
        {
            magic[row][i] = 0;
        }
        row++;
        k++;
    }
    
    int count = 1;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(magic[i][j] == 0)
            {
                magic[i][j] = count;
            }
            count++;
        }
    }
    
    count = size * size;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(magic[i][j] == -1)
            {
                magic[i][j] = count;
            }
            count--;
        }
    }
    printMagicSquare(size, magic);
}


int main(int argc, const char * argv[]) {
    int size;
    printf("Enter magic square size: ");
    scanf("%d", &size);
    if(size % 2 != 0)
    {
        gen_odd(size);
    }
    if (size % 4 == 0) {
        gen_doubly_even(size);
    }
    return 0;
}
