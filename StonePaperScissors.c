#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char getChoice();
char randomChoice();
void displayChoice(char[],char[],char,char);
void printName(char);
int decideWin(char,char);
void printResult(int,int);

int main()
{
    printf("\nWELCOME TO STONE_PAPER_SCISSORS\n----------------------------------------------------\n");
    printf("ps: first to five wins the game.\n");

    int score1 = 0, score2 = 0;
    char player1[20] = "Computer", player2[20] = "Computer";
    // printf("\nEnter 1 for SinglePlayer");
    // printf("\nEnter 2 for MultiPlayer");
    // int x = scanf("%d",&x);
    printf("Enter your name:\t");
    scanf("\n%[^\n]s\n",player1);
    printf("\n\n----------------------------------------------------\n");

    while( score1 != 5 && score2 != 5){
        char a = getChoice();
        char b = randomChoice();
        displayChoice(player1,player2,a,b);
        int flag = decideWin(a,b);
        if( flag == 1 ) score1++;
        else if( flag == 2 ) score2++;
        printResult(score1,score2);
    }

    printf("\n%s is the winner!!!!\n", (score1 == 5)? player1 : player2 );
    printf("Final ");   printResult(score1,score2);

    return 0;   
}

char getChoice()
{
    printf("\n Stone      [1]\n Paper      [2]\n Scissors   [3]\n\nEnter your choice:     ");
    int n;  scanf("%d",&n);
    printf("\n");
    return (char) ( n + 64 );
}

char randomChoice()
{
    srand(time(0));
    return (char) ( rand()% 3 + 65);
}

void displayChoice(char name1[], char name2[], char x, char y)
{
    printf("\n%s played ",name1); printName(x);
    printf("\n%s played ",name2); printName(y);
     printf("\n----------------------------------------------------\n");
}

void printName(char x)
{
    if( x == 'A') printf("Stone");
    else if( x == 'B') printf("Paper");
    else printf("Scissors");
    return;
}

int decideWin(char x, char y)
{
    if( x == y) return 0;
    else if ( x == 'A' && y == 'C') return 1; 
    else if ( x == 'B' && y == 'A') return 1;
    else if ( x == 'C' && y == 'B') return 1;
    else return 2;
}

void printResult(int x, int y)
{
    printf("Score:\t%d ,\t%d\n",x,y);
    printf("\n----------------------------------------------------\n");
    return ;
}