#include <stdio.h>
#include <string.h>
//------------------------------------------//
//------------checking rows----------------//
char check_rows(char user_name[][30],char  array[3][3]){
    char a;
    int counter=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            a=array[i][0];

            if (array[i][j]==a){
                counter+=1;
            }

        }
        if (counter==3){
            if (a=='X'){
                return 'X';
            }

            else if (a=='O')
            {
                return 'O';
            }
        }
        counter=0;

    }
    return 'N';
}
//-------------------------------------------//
//---------------checking columns------------//
char  check_columns(char user_name[][30],char array[3][3]){
    char a;
    int counter=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            a=array[0][i];
            if (array[j][i]==a){
                counter+=1;
            }}

        if (counter==3){
                 if (a=='X'){
                return 'X';
            }

            else if(a=='O')
            {
                return 'O';
            }
        }
        counter=0;

    }
    return 'N';
}
//-----------------------------------------------//
//---------------left diagonal check------------//
char  check_leftdiagonal(char user_name[][30],char array[3][3]){
    int b=0;
    char c;
    int counter=0;
    for (int i=0;i<3;i++){
        c=array[0][0];
        if (array[i][b]==c){
            counter+=1;
        }
        b+=1;}
    if (counter==3){
         if (c=='X'){
                return 'X';
            }

            else if (c=='O')
            {
                return 'O';
            }
    }
    else
    return 'N';
}

//-------------------------------------------------//
//-------------right diagonal check-----------------//
char check_rightdiagonal(char user_name[][30],char array[3][3]){
    int b=2;
    char c;
    int counter=0;
    for (int i=0;i<3;i++){
        c=array[0][2];
        if (array[i][b]==c){
            counter+=1;
        }
        b-=1;}

    if (counter==3){
         if (c=='X'){
                return 'X';
            }

            else if (c=='O')
            {return 'O';}

    }
    else
    return 'N';
}
//------------------------------------------------------//
//--------------full board checking function------------//
int full_board_check(char  arr[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (arr[i][j]==' '){
                return 0;
        }
    }
}
    return 1;}
//-------------------------------------------------//
//----------------checking game status-------------//
char  game_check(char user_name[][30],char array[3][3]){
    //for rows
    if (check_rows(user_name,array)=='X'){
        return 'X';
    }
    else if (check_rows(user_name,array)=='O'){
        return 'O';
    }
    //for columns
    else if (check_columns(user_name,array)=='X'){
        return 'X';
    }
    else if (check_columns(user_name,array)=='O'){
        return 'O';
    }
    //for right diagonal
    else if (check_rightdiagonal(user_name,array)=='X'){
        return 'X';
    }
    else if (check_rightdiagonal(user_name,array)=='O'){
        return 'O';
    }
    //for left diagonal
    else if (check_leftdiagonal(user_name,array)=='X'){
        return 'X';
    }
    else if (check_leftdiagonal(user_name,array)=='O'){
        return 'O';
    }
    else if (full_board_check(array)==1){
        return 'F';
    }
    else{
        return 'N';
    }

}
//--------------------------------------------------------//
//-----------------row number input-----------------------//
int row_input(){
    int row;
    printf("\nEnter a row number: ");
    scanf("%d",&row);
    while (row<1 || row>3){
        printf("Enter the valid row number: ");
        scanf("%d",&row);
    }
    return row-1;
}
//-----------------------------------------------------------//
//-----------------column number input-----------------------//
int column_input(){
    int column;
    printf("Enter a column number: ");
    scanf("%d",&column);
    while (column<1 || column>3){
        printf("Enter the valid row number: ");
        scanf("%d",&column);
    }
    return column-1;
}
//--------------------------------------------------------------------------//
//----------final user input calling row and column input functions---------//
void input_from_user(char user_name[30],char mark,char array[3][3]){
    int row,column;
    printf("\n%s your mark is \"%c\"",user_name,mark);
    row=row_input();
    column=column_input();
    if (array[row][column]==' '){
        array[row][column]=mark;
    }
    else{
         while (array[row][column]!=' '){
        printf("Sorry! space is occupied! Try again!\n");
        row=row_input();
        column=column_input();
        if (array[row][column]==' '){
            array[row][column]=mark;
            break;
        }
    }}
    int end=' ';
}
//-----------------------------------------------------------------------//
//-----------------------printing board function ------------------------//
void printing_board(char array[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (j<2){
            printf("%c |",array[i][j]);
        }
        else if(j==2){
            printf("%c",array[i][j]);
        }}
    if (i<(3-1)){
        printf("\n");
        printf("--------");
        printf("\n");
    }
    else{
        break;
    }
}}
//---------------------------------------------------------------------//
//--------------------printing menu function---------------------------//
void print_menu(){
        printf("*******************Menu***********************\n");
        printf("           Press 1 to play the game\n");
        printf("Press any number other than 1 to quit the game\n");
        printf("           Enter your option\n");
        }
//--------------------------------------------------------------------//
//-----------------------MAIN function--------------------------------//
int main(){

    /*
    Initial step:
    input name from user 1
    input name from user 2
    assigning symbol to the users X for user 1 and O for user 2
    Steps
    Step 1:check rows
    step2:check columns
    step3:check diagonal
    step4:check win
    */

    //some declarations
    char user_1[30];
    char user_2[30];
    char  mark_1='X';
    char mark_2='O';

    //turn variable will help for the motion of game from one player to other
    int turn=1;
    //input variable will check whether users wants to play game again or not
    int input=1;
    //loop will be executed till user does not enters the number other than 1
    while(input==1)
    {   system("cls");
        //clearing buffer
        fflush(stdin);
        //taking input name from player 1 using gets function
        printf("Player 1 Enter your name: ");
        gets(user_1);
        //clearing buffer again
        fflush(stdin);
        //getting input from player 2
        printf("Player 2 Enter your name: ");
        gets(user_2);
        //clearing the buffer again
        fflush(stdin);

        // storing the names of the users in an array
        char usernames[2][30];
        /*strcpy stands for "string copy" is standard library function used
        to copy contents of one string to other*/
        strcpy(usernames[0], user_1);
        strcpy(usernames[1], user_2);

        //assigning users their marks
        printf("%s your mark is \"%c\"\n",user_1,mark_1);
        printf("%s your mark is \"%c\"\n",user_2,mark_2);
        //initializing the board as array of spaces
        char array[3][3];
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                array[i][j]=' ';

            }
        }
        //calling the printing_board function to print board
        printing_board(array);
        //loop will be executed till game gets the status of either win or draw
        while (game_check(usernames,array)=='N'){
            if (turn==1) //for player 1
                {
            input_from_user(usernames[0],mark_1,array);
            //system("cls") for screen clearance
            system("cls");
            printing_board(array);
            if (game_check(usernames,array)=='X'){
                printf("\n\n\"%s is the Winner!\"\n\n",usernames[0]);
                break;

            }
            else if (game_check(usernames,array)=='O'){
                printf("\n\n\"%s is the Winner!\"\n\n",usernames[1]);
                break;

            }
            else if (game_check(usernames,array)=='F'){
                printf("\n\n\"Draw\"\n\n");
                break;

            }
            turn +=1;
            }
            if (turn==2) //for player 2
            {
                input_from_user(usernames[1],mark_2,array);
                system("cls");
                printing_board(array);
                if (game_check(usernames,array)=='X'){
                printf("\n\n\"%s is the Winner!\"\n\n",usernames[0]);
                break;

            }
            else if (game_check(usernames,array)=='O'){
                printf("\n\n\"%s is the Winner!\"\n\n",usernames[1]);
                break;

            }
            else if (game_check(usernames,array)=='F'){
                printf("\n\n\"Draw\"\n\n");
                break;

            }
            turn-=1;

            }

        }
        //calling printing menu to print the menu for playing game again
        print_menu();
        //getting the option from user here
        scanf("%d",&input);

    }

}

