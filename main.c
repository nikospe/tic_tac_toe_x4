#include <stdio.h>
#include <time.h>


char board[4][4] = {                        
                       {' ',' ',' ',' '},         
                       {' ',' ',' ',' '},          
                       {' ',' ',' ',' '},
                       {' ',' ',' ',' '}         
};


void print_board(){
     printf("\n\n");
     printf("  %c  |  %c  |  %c  | %c\n", board[0][0], board[0][1], board[0][2], board[0][3]);
     printf("-----+-----+-----+----\n");
     printf("  %c  |  %c  |  %c  | %c\n", board[1][0], board[1][1], board[1][2], board[1][3]);
     printf("-----+-----+-----+----\n");
     printf("  %c  |  %c  |  %c  | %c\n", board[2][0], board[2][1], board[2][2], board[2][3]);
     printf("-----+-----+-----+----\n");
     printf("  %c  |  %c  |  %c  | %c\n", board[3][0], board[3][1], board[3][2], board[3][3]);
}


int  main(int argc, char *argv[])
{
    int i, j, x, k, row, column, winner=0, counter_for_X=0, counter_for_O=0, pc_turn, counter_for_empties=0;                      
    int found=0;
    
    printf("To play first enter '1' else enter  '2': ");
    scanf("%d", &x);
    while(x!=1 && x!=2){
        printf("Wrong value...\nEnter correct value: ");
        scanf("%d", &x);
    }
    
    for(k=0;k<16;k++){
        print_board();
        if(x==1){

            do{
                printf("Give your choice:\n");        
                printf("Give row: ");
                scanf("%d", &row);
                printf("Give column: ");
                scanf("%d", &column);
                                   
                if (board[row][column] == 'X' || board[row][column] == 'O'){
                    printf("\n-----> This position is in use!\n");
                    found = 1;
                }
                else{
                    found = 0;
                    board[row][column] = 'X';                                
                }
            }
            while(row < 0 || row > 3 || column < 0 || column > 3 || found == 1);
        }  
        else{
            pc_turn=0;
            if(pc_turn==0){  
                for(i=0;i<4;i++){
                    if(pc_turn==1){
                        break;
                    }
                    counter_for_X=0;
                    counter_for_O=0;
                    for(j=0;j<4;j++){
                        if(board[i][j]=='X'){
                            counter_for_X++;
                        }
                        if(board[i][j]=='O'){
                            counter_for_O++;
                        }
                    }
                    if(counter_for_O==3 || counter_for_X==3){
                        for(j=0;j<4;j++){
                            if(board[i][j]!='X' && board[i][j]!='O'){
                                board[i][j]='O';
                                pc_turn=1;
                                printf("\nCom turns:\n");
                                break;
                            }
                        }
                    }    
                }
            }            
            if(pc_turn==0){
                for(j=0;j<4;j++){
                    if(pc_turn==1){
                        break;
                    }
                    counter_for_X=0;
                    counter_for_O=0;
                    for(i=0;i<4;i++){
                        if(board[i][j]=='X'){
                            counter_for_X++;
                        }
                        if(board[i][j]=='O'){
                            counter_for_O++;
                        }
                    }
                    if(counter_for_O==3 || counter_for_X==3){
                        for(i=0;i<4;i++){
                            if(board[i][j]!='X' && board[i][j]!='O'){
                                board[i][j]='O';
                                pc_turn=1;
                                printf("\nCom turns:\n");
                                break;
                            }
                        }
                    }
                }
            }            
            if(pc_turn==0){ 
                counter_for_X=0;
                counter_for_O=0;   
                for(i=0;i<4;i++){
                    if(pc_turn==1){
                        break;
                    }
                    for(j=0;j<4;j++){
                        if(i==j){
                            if(board[i][j]=='X'){
                                counter_for_X++;
                            }
                            if(board[i][j]=='O'){
                                counter_for_O++;
                            }
                        }
                    }
                }
                if(counter_for_X==3 || counter_for_O==3){
                    for(i=0;i<4;i++){
                        if(pc_turn==1){
                            break;
                        }
                        for(j=0;j<4;j++){
                            if(i==j){
                                if(board[i][j]!='X' && board[i][j]!='O'){
                                    board[i][j]='O';
                                    pc_turn=1;
                                    printf("\nCom turns:\n");
                                    break;
                                }
                            }
                        }
                    }  
                }
            }            
            if(pc_turn==0){
                counter_for_X=0;
                counter_for_O=0;
                for(i=0;i<4;i++){
                    if(pc_turn==1){
                            break;
                    }    
                    for(j=0;j<4;j++){
                        if( (i==3&&j==0)||(i==2&&j==1)||(i==1&&j==2)||(i==0&&j==3) ){
                            if(board[i][j]=='X'){
                                counter_for_X++;
                            }
                            if(board[i][j]=='O'){
                                counter_for_O++;
                            }
                        }
                    }
                }
                if(counter_for_X==3 || counter_for_O==3){
                    for(i=0;i<4;i++){
                        if(pc_turn==1){
                            break;
                        }
                        for(j=0;j<4;j++){
                            if( (i==3&&j==0)||(i==2&&j==1)||(i==1&&j==2)||(i==0&&j==3) ){
                                if(board[i][j]!='X' && board[i][j]!='O'){
                                    board[i][j]='O';
                                    pc_turn=1;
                                    printf("\nCom turns:\n");
                                    break;
                                }
                            }
                        }
                    }
                }                                                  
            }                                                   
            if(pc_turn==0){
                counter_for_empties=0;
                for(i=0;i<4;i++){
                    for(j=0;j<4;j++){
                        if(board[i][j]!='X'&&board[i][j]!='O'){
                            counter_for_empties++;
                        }
                    }
                }
                if(counter_for_empties<6){
                    for(i=0;i<4;i++){
                        if(pc_turn==1){
                            break;
                        }
                        for(j=0;j<4;j++){
                            if(board[i][j]!='X'&&board[i][j]!='O'){
                                board[i][j]='O';
                                printf("\nCom turns:\n");
                                pc_turn=1;
                                break;
                            }
                        }
                    }
                }
                else{
                    found=1;
                    while(found==1){
                        srand(time(NULL));
                        row=rand()%4;
                        srand(time(NULL));
                        column=rand()%4;
                        if (board[row][column] == 'X' || board[row][column] == 'O'){
                            found = 1;
                        }            
                        else{
                            found = 0;
                            board[row][column] = 'O';   
                            printf("\nCom turns:\n");                             
                        }
                    }
                }
            }                                           
        }                                    
        counter_for_X=0;
        counter_for_O=0;   
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(i==j){
                    if(board[i][j]=='X'){
                        counter_for_X++;
                    }
                    if(board[i][j]=='O'){
                        counter_for_O++;
                    }
                }
            }
        }
        if(counter_for_X==4 || counter_for_O==4){
            winner=x;
            break;
        }
        counter_for_X=0;
        counter_for_O=0;
        for(i=0;i<4;i++){    
            for(j=0;j<4;j++){
                if( (i==3&&j==0)||(i==2&&j==1)||(i==1&&j==2)||(i==0&&j==3) ){
                    if(board[i][j]=='X'){
                        counter_for_X++;
                    }
                    if(board[i][j]=='O'){
                        counter_for_O++;
                    }
                }
            }
        }
        if(counter_for_X==4 || counter_for_O==4){
            winner=x;
            break;
        }        
        counter_for_X=0;
        counter_for_O=0;
        for(i=0;i<4;i++){
            if(winner!=0){
                break;
            }
            counter_for_X=0;
            counter_for_O=0;
            for(j=0;j<4;j++){
                if(board[i][j]=='X'){
                    counter_for_X++;
                }
                if(board[i][j]=='O'){
                    counter_for_O++;
                }
            }
            if(counter_for_O==4 || counter_for_X==4){ 
                winner=x;
                break; 
            }
        }
        for(j=0;j<4;j++){
            if(winner!=0){
                break;
            }
            counter_for_X=0;
            counter_for_O=0;
            for(i=0;i<4;i++){
                if(board[i][j]=='X'){
                    counter_for_X++;
                }
                if(board[i][j]=='O'){
                    counter_for_O++;
                }
            }
            if(counter_for_O==4 || counter_for_X==4){
                winner=x;
                break;
            }
        } 
        if (winner != 0){
            break;
        }
        if(x==1){
            x=2;
        }
        else{
            x=1;
        }
    }          
    print_board();
      
    if(winner == 0){
        printf("Its a draw!!!\n");
        system("PAUSE");
        return 0;
    }   
    else{
        printf("The winner is: %d\n", winner);
        system("PAUSE");
        return 0;
    }
}
