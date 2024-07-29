

//This Game Three Senario.
//1 . P1 or P2 Wins.
//2 . Game Playing.
//3 . Game Draw.
  
  
#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn ='X';
int row,column;
bool draw=false;
void display_board(){
	system("cls");
	cout<<"	       \t\t-->T I C    T A C   T O E   G A M E<--\n\n"<<endl;
    cout<<"				PLAYER1  [X]"<<endl;
    cout<<"				PLAYER2  [0]\n"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t     |     |     "<<endl;
    cout<<"\t\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"\t\t\t\t_____|_____|_____"<<endl;
    cout<<"\t\t\t\t     |     |     "<<endl;
    cout<<"\t\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"\t\t\t\t_____|_____|_____"<<endl;
    cout<<"\t\t\t\t     |     |     "<<endl;
    cout<<"\t\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"\t\t\t\t     |     |     "<<endl;
    cout<<endl<<endl;
}
void player_turn(){
	int choice;
	if(turn=='X')
		cout<<"\t\t\t\tPLAYER1  [X]  TURN:";
	if(turn=='0')
		cout<<"\t\t\t\tPLAYER2  [0]  TURN:";
    cin>>choice;
	switch(choice){
    	case 1: row=0,column=0; break;
    	case 2: row=0,column=1; break;
    	case 3: row=0,column=2; break;
    	case 4:	row=1,column=0;	break;
    	case 5:	row=1,column=1;	break;
    	case 6: row=1,column=2; break;
    	case 7: row=2,column=0;	break;
    	case 8:	row=2,column=1;	break;
    	case 9:	row=2,column=2;	break;
    	default: cout<<"Invalid choice"; break;
	}
	if(turn=='X' && board[row][column]!='X' && board[row][column]!='0'){
		board[row][column]='X';
		turn='0';
	}
	else if(turn=='0' && board[row][column]!='X' && board[row][column]!='0'){
		board[row][column]='0';
		turn='X';
	}
else{
	cout<<"Box Already filled!\nPlease Try again\n\n";
	player_turn();
}
display_board();
}
bool GameOver(){
	//Check Win the Game.
	for(int i=0; i<3; i++){
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return false;
	}
	
	
	
	//Diaglonaly Game win.
	if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
		return false;
		
		
		
	//if there is any box not filled.
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j]!='X' && board[i][j]!='0')
				return true;
		}
	}
	
	
	
	//Game Draw.
	draw = true;
	return false;
}
int main(){
	while(GameOver()){
		display_board();
		player_turn();
		GameOver();
	}
	if(turn=='X' && draw==false)
		cout<<"Player2[0] Wins!  Congratulations\n\n";
	else if(turn=='0' && draw==false)
		cout<<"Player1[X] Wins!  Congratulations\n\n";
	else 
		cout<<"GAME DRAW !! "<<endl;
    return 0;
}
