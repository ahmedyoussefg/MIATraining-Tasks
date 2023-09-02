#include <stdio.h>
#include <stdlib.h>

void printChars(int n, char ch);
void firstLine();
void secondLine();
void thirdLine();
void fourthLine();
void fifthLine();

int main()
{
    firstLine();
    secondLine();
    thirdLine();
    fourthLine();
    fifthLine();
    return 0;
}

void printChars(int n, char ch)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", ch);
    }
}

void firstLine()
{
    // * : 5 4 1 1
    //   : 3 4 4
    int indx_st[4] = {5,4,1,1};
    int indx_sp[3] = {3,4,4};
    for (int i = 0, j = 0, cnt = 0; cnt < 7; cnt ++)
    {
        if (cnt % 2 == 0)
        {
            printChars(indx_st[j++], '*');
        }
        else
        {
            printChars(indx_sp[i++], ' ');
        }
    }
    printf("\n");
}

void secondLine()
{
    // ' ' : {7,3,3,4}
    int indx[4] = {7,3,3,4};
    for (int i = 0, cnt = 0; cnt < 9; cnt ++)
    {
        if (cnt % 2 == 0)
        {
            printChars(1, '*');
        }
        else
        {
            printChars(indx[i++], ' ');
        }
    }
    printf("\n");

}
void thirdLine()
{
    // '*' : {1,2,4,1,1}
    // ' ' : {2,3,4,4};
    int indx_st[5] = {1,2,4,1,1};
    int indx_sp[4] = {2,3,4,4};
    for (int i = 0, j = 0, cnt = 0; cnt < 9; cnt ++)
    {
        if (cnt % 2 == 0)
        {
            printChars(indx_st[j++], '*');
        }
        else
        {
            printChars(indx_sp[i++], ' ');
        }
    }
    printf("\n");
}
void fourthLine()
{
    // * : 1
    // ' ' : 3x4 , 4
    int indx[5] = {3,3,3,3,4};
    for (int i = 0, cnt = 0; cnt < 11; cnt ++)
    {
        if (cnt % 2 == 0)
        {
            printChars(1, '*');
        }
        else
        {
            printChars(indx[i++], ' ');
        }
    }
    printf("\n");
}
void fifthLine()
{
    // * : 5,1,1,6
    //   : 3,4,2
    int indx_st[4] = {5,1,1,6};
    int indx_sp[3] = {3,4,2};
    for (int i = 0, j = 0, cnt = 0; cnt < 7; cnt ++)
    {
        if (cnt % 2 == 0)
        {
            printChars(indx_st[j++], '*');
        }
        else
        {
            printChars(indx_sp[i++], ' ');
        }
    }
}
