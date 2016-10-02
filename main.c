#include <stdio.h>
#include <cstdlib>
#include <time.h>

/*dilwsa katholika ton pinaka gia na xreisimopoieitai kai sti sunartisi*/
char board[4][4] = {                        
                       {' ',' ',' ',' '},         
                       {' ',' ',' ',' '},          
                       {' ',' ',' ',' '},
                       {' ',' ',' ',' '}         
};

/*einai i sunartisi pou emfanizei ton pinaka ka8ws kai tis allages pou eginan*/
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
    /*dilwsa mia metabliti found gia na mou leei an to keli tou pinaka xreisimopoieitai*/                     
    int found=0;
    
    /*o player 1 einai o xristis kai o player 2 einai o upologistis*/
    printf("Ean 8elete na pai3ete prwtos pieste '1' alliws pieste '2': ");
    /*se periptwsi pou o xristis patisei 2 8a pai3ei prwtos o upologistis*/
    scanf("%d", &x);
    /*ginetai elegxos dedomenwn me tin while*/
    while(x!=1 && x!=2){
        printf("La8os koumpi...\nPieste 3ana: ");
        scanf("%d", &x);
    }
    /*o xristis exei to 'X' kai o upologistis to 'O'*/
    
    for(k=0;k<16;k++){
        print_board();
        /*edw arxizei i seira tou xristi*/
        if(x==1){
            /*to do...while einai i seira tou xristi*/
            do{
                printf("Parakalw dwste epilogi:\n");
                /*to prwto stoixeio kathe grammis kai stulis einai to 0*/
                printf("dwste grammi: ");
                scanf("%d", &row);
                printf("dwste stuli: ");
                scanf("%d", &column);
            
                /*apothikevoume ton arithmo pou dinei o xristis gia na kanoume elegxo an to keli auto exei paixtei idi*/         
                if (board[row][column] == 'X' || board[row][column] == 'O'){
                    printf("\n-----> H thesi ayti exei paixtei !\n");
                    found = 1;
                }
                else{
                    found = 0;
                    board[row][column] = 'X';                                
                }
            }
            while(row < 0 || row > 3 || column < 0 || column > 3 || found == 1);
        }  
        /*edw einai i seira tou upologisti... an einai i prwti tou fora 8a pai3ei
        stin tuxi. alliws tha koita3ei an mporei na balei kapou gia na kerdisei
        i na stamatisei ton xristi na nikisei...*/
        else{
            pc_turn=0;
            if(pc_turn==0){  
                /*8a psa3oume olo ton pinaka gia na doume an prepei o upologistis
                na stamatisei ti niki tou paixti i na nikisei o idios*/
                    
                /*edw ginetai orizontios elegxos*/
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
                                printf("\nSeira tou com :\n");
                                break;
                            }
                        }
                    }    
                }
            }
            /*edw ginetai katakorufos elegxos*/
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
                                printf("\nSeira tou com :\n");
                                break;
                            }
                        }
                    }
                }
            }
            /*edw ginetai diagwnios elegxos gia ti mia apo tis 2 diagwnious*/
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
                                    printf("\nSeira tou com :\n");
                                    break;
                                }
                            }
                        }
                    }  
                }
            }
            /*edw ginete elegxos gia tin alli diagwnios*/
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
                                    printf("\nSeira tou com :\n");
                                    break;
                                }
                            }
                        }
                    }
                }                                                  
            }
                         
            /*an den kinduneuei na xasei i an den mporei na nikisei ekeini tin stigmi tha pai3ei stin tuxi*/                
            if(pc_turn==0){
                /*edw tha kanoume enan elegxo gia na doume an uparxoun liga koutia
                kai an nai, na balei sto prwto adei giati i srand argei polu otan exoun minei liga
                koutia kena.....*/
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
                                printf("\nSeira tou com :\n");
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
                            printf("\nSeira tou com :\n");                             
                        }
                    }
                }
            }
        
                                   
        }                        
        /*elexoume ena exei ginei triliza prota se kapoia diagonio*/             
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
        /*gia tin alli diagwnios twra...*/
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
        /*edw tha ginei elegxos gia orizontia triliza*/
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
        /*edw tha ginei elegxos gia katakorufi triliza*/
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
        /*edw teleiwsan oi elgxoi gia to an exei ginei kapoia triliza kai koitame
        an uparxei nikitis i oxi... */
        if (winner != 0){
            break;
        }
        if(x==1){
            x=2;
        }
        else{
            x=1;
        }
        /*an de uparxei kapoios nikitis tote paizei o epomenos paixties...*/
    }         
    /*emfanisi tou pinaka me ta apotelesmeta */  
    print_board();

    /*elexos an iparxei nikitis kai an nai poios einai*/   
    if(winner == 0){
        printf("Den iparxei nikitis\n");
        system("PAUSE");
        return 0;
    }   
    else{
        printf("Nikitis einai o paiktis: %d\n", winner);
        system("PAUSE");
        return 0;
    }
}
