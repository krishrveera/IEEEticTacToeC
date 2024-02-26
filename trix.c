#include <stdio.h>
	int row,col,a,victory;
	char block[3][3] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
	char rematch;
void display();
void cleargame();
int checkgame();
int main(){
	int turn =0;
	int error=0;
	victory=0;
	printf("Welcome to Tic Tac Toe!!!\n");
	display(); 
	do{
			do { 
				if ((turn%2==0) && (victory==0)){
				printf("Player 1 turn\nWhere do you want to position your X? Type row col\n");
					do{ 
						scanf(" %d %d", &row, &col);
						if(block[row-1][col-1]== '-'){
						block[row-1][col-1]= 'X';
						error =0;
						} else if ((block[row-1][col-1]== 'O')||(block[row-1][col-1]== 'X')){
						error =1;
						printf("block already occupied, select different row and col number\n");
						} else if ((row>3)||(col>3)){
							error =1;
							printf("block number non valid, select different row and col number\n");
						}}while (error==1);
						display();
				}else if ((turn%2!=0) && (victory==0)){ 
					printf("Player 2 turn\nWhere do you want to position your O? Type row col\n");
					do{ 
						scanf(" %d %d", &row, &col);
						if(block[row-1][col-1]== '-'){
						block[row-1][col-1]= 'O';
						error=0;
						} else if ((block[row-1][col-1]== 'X')||(block[row-1][col-1]== 'O')) {
						error =1;
						printf("block already occupied, select different row and col number\n");
						}else if ((row>3)||(col>3)){
							error =1;
						printf("block number non valid, select different row and col number\n");
					}}while (error==1);
						display();
					}turn++;
					error=0;
			} while (checkgame() ==0);
					printf("would you like to play another game? type Y or N:\n");
					scanf(" %c", &rematch);
					char block[3][3] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
					victory=0;
				turn=0;
				cleargame();
		}while (rematch=='Y' || rematch =='y');
		
	return 0;
	}
	
void display(){
	int i,j;
	for (i=0;i<3;++i){
		printf("|");
		for (j=0;j<3;++j){
			printf(" %c |", block[i][j]);
		} printf("\n");
	} printf("\n");
}
void cleargame(){
	int i,j;
	for (i=0;i<3;++i){
		for (j=0;j<3;++j){
			block[i][j]='-';
		}
	} 
}
int checkgame(){
	if ((block[0][0]=='X'&&block[0][1]=='X'&&block[0][2]=='X')||(block[1][0] == 'X' && block[1][1] == 'X' && block[1][2] == 'X')||(block[2][0] == 'X' && block[2][1] == 'X' && block[2][2] == 'X')||(block[0][0] == 'X' && block[1][1] == 'X' && block[2][2] == 'X')||(block[0][0]=='X'&&block[1][0]=='X'&&block[2][0]=='X')||(block[2][0] == 'X' && block[2][1] == 'X' && block[2][2] == 'X')||(block[0][0] == 'X' && block[1][1] == 'X' && block[2][2] == 'X')||(block[0][1]=='X'&&block[1][1]=='X'&&block[2][1]=='X')||(block[2][0] == 'X' && block[2][1] == 'X' && block[2][2] == 'X')||(block[0][0] == 'X' && block[1][1] == 'X' && block[2][2] == 'X')||(block[0][2]=='X'&&block[1][2]=='X'&&block[2][2]=='X')){
		victory=1;
		printf("Player 1 won!!!\n");
	} else if((block[0][0]=='O'&&block[0][1]=='O'&&block[0][2]=='O')||(block[1][0] == 'O' && block[1][1] == 'O' && block[1][2] == 'O')||(block[2][0] == 'O' && block[2][1] == 'O' && block[2][2] == 'O')||(block[0][0] == 'O' && block[1][1] == 'O' && block[2][2] == 'O')||(block[0][0]=='O'&&block[1][0]=='O'&&block[2][0]=='O')||(block[2][0] == 'O' && block[2][1] == 'O' && block[2][2] == 'O')||(block[0][0] == 'O' && block[1][1] == 'O' && block[2][2] == 'O')||(block[0][1]=='O'&&block[1][1]=='O'&&block[2][1]=='O')||(block[2][0] == 'O' && block[2][1] == 'O' && block[2][2] == 'O')||(block[0][0] == 'O' && block[1][1] == 'O' && block[2][2] == 'O')||(block[0][2]=='O'&&block[1][2]=='O'&&block[2][2]=='O')){
		victory=1;
		printf("Player 2 won!!!\n");
	} else{
		victory=0;
	} 
	return (victory);
}	
