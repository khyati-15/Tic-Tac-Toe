#include<iostream>
using	namespace	std;
void makeboard(char *square)
{
        system("clear");
        cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout<<endl;
    cout<<" "<<square[1]<<" | "<<square[2]<<" | "<<square[3]<<endl;
    cout<<"___|___|___"<<endl;
    cout<<" "<<square[4]<<" | "<<square[5]<<" | "<<square[6]<<endl;
    cout<<"___|___|___"<<endl;
    cout<<" "<<square[7]<<" | "<<square[8]<<" | "<<square[9]<<endl;
    cout<<endl;
}
int checkwin(char *board)
{
    if(board[1]==board[2] && board[2]==board[3])
        return  1;
    else if(board[4]==board[5] && board[5]==board[6])
        return  1;
    else if(board[7]==board[8] && board[8]==board[9])
        return  1;
    else if(board[1]==board[4] && board[4]==board[7])
        return  1;
    else if(board[2]==board[5] && board[5]==board[8])
        return  1;
    else if(board[3]==board[6] && board[6]==board[9])
        return  1;
    else if(board[1]==board[5] && board[5]==board[9])
        return  1;
    else if(board[3]==board[5] && board[5]==board[7])
        return  1;
    else
    {
        int res=1;
        for(char i=49;i<59;i++)
            if(board[i-48]==(char)i)
                res=0;
        if(res==0)
            return  -1;
        else
            return  0;
    }
    
}
int main()
{
    char board[10]={'0','1','2','3','4','5','6','7','8','9'};
    int player=1,choice,res;
    do
    {
        makeboard(board);
        player=(player%2)?1:2;
        
        cout<<"Player "<<player<<", Enter a number(1-9) :";
        cin>>choice;
        char    mark=(player==1)?'X':'O';
        while(choice<1 || choice>9){
            cout<<"INVALID CHOICE,Please enter a valid move"<<endl;
        cout<<"Player "<<player<<", Enter a number(1-9) :";
        }
	char	ptr[10];
	sprintf(ptr,"%d",choice);
        if(board[choice]==*ptr)
            board[choice]=mark;
        
        res=checkwin(board);
        player++;
    }while(res==-1);
        makeboard(board);
    if(res==1)
        cout<<"Player "<<--player<<"Wins"<<endl;
    else
        cout<<"GAME DRAW"<<endl;
    return 0;
}
