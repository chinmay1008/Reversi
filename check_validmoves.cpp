#include "check_validmoves.h"
using namespace std;

// function to check if the move entered is valid or not
int check1(int p, int q, int u, int v, int player, vector< vector<int> > &a)
{
    int flag1=1,i,j,check,run,opp1=0,opp2=0;

    //Setting the check to opposite player's value
    if(player==1)
        check=4;
    else if(player==-1)
        check=2;

    //If the inital and final coordinates have the same row
    if(p==u)
    {
        opp1=0;
        //Checking atleast 1 opponent move
        for(i=min(q,v)+1;i<max(q,v);i++)
        {
            if(a[p][i]==check)
                opp1=1;
        }
        run=0;
        //Checking every in between column value
        for(i=min(q,v)+1;i<max(q,v);i++)
        {
            run=1;
            //if(a[p][i]!=check)
            if(a[p][i]==0 || opp1==0)
            {
                flag1=0;
                return flag1;
            }
        }
        if(run==0)
            flag1=0;
        return flag1;
    }

    //If initial and final coordinates have the same column
    else if(q==v)
    {
        opp2=0;
        //Checking atleast 1 opponent move
        for(i=min(p,u)+1;i<max(p,u);i++)
        {
            if(a[i][q]==check)
                opp2=1;
        }
        run=0;
        //Checking every in between row value
        for(i=min(p,u)+1;i<max(p,u);i++)
        {
            run=1;
            //if(a[i][q]!=check)
            if(a[i][q]==0 || opp2==0)
            {
                flag1=0;
                return flag1;
            }
        }
        if(run==0)
            flag1=0;
        return flag1;
    }

    //If nothing is in common
    else
    {
        flag1=0;
        return flag1;
    }
    
}
