#include "updating_moves.h"
using namespace std;

// function to update the valid moves on the reversi board
void update(int p, int q, int u, int v, int player, vector< vector<int> > &a)
{
    int i,j,check;

    if(player==1)
        check=2;
    else if(player==-1)
        check=4;
    
    if(p==u)
    {
        for(i=min(q,v)+1;i<max(q,v);i++)
            a[p][i]=check;
    }
    else if(q==v)
    {
        for(i=min(p,u)+1;i<max(p,u);i++)
            a[i][q]=check;
    }
    return;
}
