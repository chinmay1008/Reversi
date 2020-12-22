//REVERSI by Chinmay Toshniwal and Hardik Narang
#include "main.h"
#define SPADE "\xE2\x99\xA0"
#define DIAMOND "\xE2\x99\xA6"

// declaring global variables
int player=-1,v,count1=0;
int size1=8,size2=8;
vector<int> vect;
vector<vector<int> > a(size1, vector<int> (size2, 0));
char c[20],b[20];

// implementation of main
int main()
{
    srand(time(NULL));
    int k,u,i,j,p,flag,flag1,q,en;
    a[3][3]=2;
    a[3][4]=4;
    a[4][3]=4;
    a[4][4]=2;

   cout<<"*********************************REVERSI*********************************\n";
   cout<<"\nTo view the rules press 0, to continue press 1: ";
   cin>>i;
   switch(i)
   {
        case 0:
            cout<<"\nRules of the game:"<<endl;
            cout<<"\nObjective: To have maximum occupied tiles.";
            cout<<"\n\nEach player gets 25 chances each to create a majority of his/her tiles\non the board.";
            cout<<"\n\nOnly horizontal and vertical moves are allowed.";
            cout<<"\n\nRules for valid initial co-ordinates:-";
            cout<<"\n\n1) The tile whose initial co-ordinate is entered should already be occupied by the current player.";
            cout<<"\n\nRules for valid final co-ordinates:-";
            cout<<"\n\n1) The tile whose co-ordinate is entered should be an empty tile.";
            cout<<"\n\n2) There should atleast be one opponent's tile and no empty tiles between the initial and final co-ordinates.";
            cout<<"\n\nThe player whose, tiles comprise the majority of the board at the end of 25\nmoves or earlier (incase of unavailability of moves for the other player, wins\nthe game).";
            cout<<"\n\nThe player who wins the toss will go first";
            cout<<"\n\nThe player can forfeit the game by entering 0 0 as the initial co-ordinates";
            cout<<"\n\nGOOD LUCK to both the players!";
	        break;

	    case 1: 
            break;
    }
    cout<<"\nWelcome!"<<endl;
    cout<<"Player 1 enter your name: ";
    cin>>c;
    cout<<"Player 2 enter your name: ";
    cin>>b;
    cout<<endl<<endl;
    cout<<c<<" will play spade- "<<SPADE<<"\n\n";
    cout<<b<<" will play diamond- "<<DIAMOND<<endl<<endl;

    while (count1!=50)
    {
        k=1;
        cout<<endl;
        cout<<"*********************************REVERSI*********************************\n";
        cout<<"**********************************BOARD**********************************\n";
        for(i=0;i<a.size();i++)
            cout<<"	"<<(i+1);
        for(i=0;i<a.size();i++)
        {

            cout<<"\n	_________________________________________________________________\n";
            cout<<(k++)<<"       |";
            for(j=0;j<a[i].size();j++)
            {
                if(a[i][j]==0)
                    cout<<" "<<"	|";
                else
                {
                    if(a[i][j]==2)
                        cout<<SPADE<<"      |";
                    else
                        cout<<DIAMOND<<"      |";

                }
            }
        }
        cout<<"\n	_________________________________________________________________";
        winner();
        // ***********Game Begins******************
        player=player*-1;

        // to decide which player would go first using random number generator to conduct TOSS
        int firstmove=rand()%2;
        if(count1==0)
        {
            if(firstmove==0)
            {
                player=1;
                cout<<endl;
                cout<<"Player "<<c<<" wins the toss and will start first"<<endl;
            }
            else
            {
                player=-1;
                cout<<endl;
                cout<<"Player "<<b<<" wins the toss and will start first"<<endl;
            }
        }
        if(player==1)
            cout<<endl<<c<<" Enter the co-ordinates of initial position "<<SPADE<<"  : ";
        else
            cout<<endl<<b<<" Enter the co-ordinates of initial position "<<DIAMOND<<"  : ";
        cin>>p>>q;
        if(p==0 && q==0)
        {
            count1=51;
            if(player==1)
                vect.push_back(-5);
            else if(player==-1)
                vect.push_back(-6);
            forfeit();
        }
        vect.push_back(p);
        vect.push_back(q);
        p--; q--;
        if(player==1)
        {
            if(a[p][q]==2)
            {
                cout<<endl<<c<<" Enter the co-ordinates of final position "<<SPADE<<"  : ";
                cin>>u>>v;
                vect.push_back(u);
                vect.push_back(v);
                u--;v--;
                if(a[u][v]==0)
                {
                    flag1=check1(p,q,u,v,player,a);
                    if(flag1==1)
                    {
                        update(p,q,u,v,player,a);
                        vect.push_back(-1);
                        count1++;
                        a[u][v]=2;
                    }
                    else if(flag1==0)
                    {
                        vect.push_back(-3);
                        count1++;
                        cout<<"\nPlayer "<<c<<" loses a turn because of an invalid move!"<<endl<<endl;
                        fflush(stdin);   
                    }
                }
                else
                {
                    vect.push_back(-3);
                    count1++;
                    cout<<"\nPlayer "<<c<<" loses a turn because of an invalid move!"<<endl<<endl;
                    fflush(stdin);   
                }
            }
            else if(a[p][q]!=2)
            {
                vect.push_back(-3);
                count1++;
                cout<<"\nPlayer "<<c<<" loses a turn because of an invalid move!"<<endl<<endl;
                fflush(stdin);
            }
        }
        else if(player==-1)
        {
            if(a[p][q]==4)
            {
                cout<<endl<<b<<" Enter the co-ordinates of final position "<<DIAMOND<<"  : ";
                cin>>u>>v; 
                vect.push_back(u);
                vect.push_back(v);
                u--;v--;
                if(a[u][v]==0)
                {
                    flag1=check1(p,q,u,v,player,a);
                    if(flag1==1)
                    {
                        update(p,q,u,v,player,a);
                        vect.push_back(-2);
                        count1++;
                        a[u][v]=4;
                    }
                    else if(flag1==0)
                    {
                        vect.push_back(-4);
                        count1++;
                        cout<<"\nPlayer "<<b<<" loses a turn because of an invalid move!"<<endl<<endl;
                        fflush(stdin);
                    }
                }
                else
                {
                    vect.push_back(-4);
                    count1++;
                    cout<<"\nPlayer "<<b<<" loses a turn because of an invalid move!"<<endl<<endl;
                    fflush(stdin);
                }
            }
            else if (a[p][q]!=4)
            {
                vect.push_back(-4);
                count1++;
                cout<<"\nPlayer "<<b<<" loses a turn because of an invalid move!"<<endl<<endl;
                fflush(stdin);
            }
        } 
    } //while loop ends
    a.erase(a.begin(), a.end());
    return 0;

}

// function to assess the winner of the game
void winner()
{
    int i,j,flag=0,p;
    int bl=0;// variable to calculate the number of tiles occupied by player 1
    int wh=0;// variable to calculate the number of tiles occupied by player 2
    for(i=0;i<a.size();i++)
    {
	for(j=0;j<a[i].size();j++)
        {
	 	if(a[i][j]==2)
		        bl++;
	        if(a[i][j]==4)
		        wh++;
        }
    }
    if(bl==0 || wh==0)
    {
	if (bl!=0)
        {
	    cout<<endl<<endl<<"Player "<<c<<" wins the game!";
            sgame(c);
        }
        else
        {
	    cout<<endl<<endl<<"Player "<<b<<" wins the game!";
            sgame(b);
        }
        cout<<endl<<endl<<"Game Over"<<endl<<endl;
        cout<<"Thank you!"<<endl;
        exit(0);
    }
    else
    {
        if(count1>=50)
        {
            if(bl>wh)
            {
                cout<<endl<<"Player "<<c<<" wins the game"<<endl;
                sgame(c);
            }
            else if (bl<wh)
            {
                cout<<endl<<"Player "<<b<<" wins the game"<<endl;
                sgame(b);
            }
            else if(bl==wh)
            {
                cout<<endl<<"Its a draw!"<<endl;
                char x[20]="None";
                sgame(x);
            }
            cout<<"Thank You!";
            exit(0);
        }
    }
}
// function to save the moves of the game in a text file
void sgame(char winner[20])
{
    struct stat st;
    if (stat("savedgames",&st) == 0)
        ;
    else
        system("mkdir \"savedgames\" ");
    char ch;
    string file1="savedgames/",file;
    int i,j,pos=0,k=1,count;
    bool flag=false;
    cout<<endl<<endl<<"Do you want to save the moves of current game? (Y/N): - ";
    cin>>ch;
    if(ch=='Y')
    {
        cout<<endl<<"Enter the file name with which you want to save: - ";
        cin>>file;
        cout<<"Your file has been saved under the 'savedgames' folder"<<endl;
        file1+=file;
        file1+=".txt";
        ofstream output(file1.c_str(),ios::app);
        for(i=0;i<vect.size();i++)
        {
            if(vect[i]==-1)
            {
                flag=false;
                count=0;
                output<<"Move "<<k<<" by Player "<<c<<" : - "<<endl;
                output<<"Initial Position: ";
                for(j=pos;j<i;j++)
                {
                    count++;
                    if(count==3)
                    {
                        flag=true;
                        output<<endl;
                        output<<"Final Position: ";
                    }
                    output<<vect[j]<<" ";
                }
                if(flag==false)
                    output<<"(Invalid Move)";
                output<<endl<<endl;
                pos=i+1;
                k+=1;
            }
            else if(vect[i]==-2)
            {
                flag=false;
                count=0;
                output<<"Move "<<k<<" by Player "<<b<<" : - "<<endl;
                output<<"Initial Position: ";
                for(j=pos;j<i;j++)
                {
                    count++;
                    if(count==3)
                    {
                        flag=true;
                        output<<endl;
                        output<<"Final Position: ";
                    }
                    output<<vect[j]<<" ";
                }
                if(flag==false)
                    output<<"(Invalid Move)";
                output<<endl<<endl;
                pos=i+1;
                k+=1;
            }
            else if(vect[i]==-3)
            {
                count=0;
                output<<"Move "<<k<<" by Player "<<c<<" : - "<<endl;
                output<<"Initial Position: ";
                for(j=pos;j<i;j++)
                {
                    count++;
                    if(count==3)
                    {
                        flag=true;
                        output<<endl;
                        output<<"Final Position: ";
                    }
                    output<<vect[j]<<" ";
                }
                output<<"(Invalid Move)";
                output<<endl<<endl;
                pos=i+1;
                k+=1;
            }
            else if(vect[i]==-4)
            {
                count=0;
                output<<"Move "<<k<<" by Player "<<b<<" : - "<<endl;
                output<<"Initial Position: ";
                for(j=pos;j<i;j++)
                {
                    count++;
                    if(count==3)
                    {
                        flag=true;
                        output<<endl;
                        output<<"Final Position: ";
                    }
                    output<<vect[j]<<" ";
                }
                output<<"(Invalid Move)";
                output<<endl<<endl;
                pos=i+1;
                k+=1;
            }
            else if(vect[i]==-5)
            {
                output<<"Move "<<k<<" by Player "<<c<<" : - "<<endl;
                output<<"Player "<<c<<" forfeited the game!"<<endl<<endl;
            }
            else if(vect[i]==-6)
            {
                output<<"Move "<<k<<" by Player "<<b<<" : - "<<endl;
                output<<"Player "<<b<<" forfeited the game!"<<endl<<endl;
            }
        }
        output<<"Winner: - "<<winner;
        //cout<<endl<<"Thank You!"<<endl;
        output.close();
        return;
    }
    else
    {
        cout<<endl<<"GAME OVER"<<endl;
        cout<<endl<<"Thank You!"<<endl;
        exit(0);
    }
}

// function to forfeit the game 
void forfeit()
{
    //winner();
    int p=player,i,j;
    if(p==1)
        cout<<endl<<endl<<"Player "<<c<<" forfeits the game!"<<endl;
    else if(p==-1)
        cout<<endl<<endl<<"Player "<<b<<" forfeits the game!"<<endl;
    p*=-1;
    if(p==1)
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
                a[i][j]=2;
        }
        winner();
    }
    else if (p==-1)
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
                a[i][j]=4;
        }
        winner();
    }
    cout<<"Thank You!"<<endl<<endl;
}

//REVERSI by Chinmay Toshniwal and Hardik Narang


