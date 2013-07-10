#include <iostream>
#include <math.h>
using namespace std;

void rec(int x,int y);
char map[30][30];
bool isVisit[30][30];
int count=0;
//start_pos
int start_x;
int start_y;
int h,w;

int main()
{
    while (cin >> w >> h) 
    {
        count = 0;
        //start pos

        for (int i = 0; i < h; i++) 
        {
            for (int j = 0; j < w; j++) 
            {
                cin >> map[j][i];
                if (map[j][i] == '@') 
                {
                    start_x=j;
                    start_y=i;
                }
                //ついでにisVisit初期化
                isVisit[j][i]=false;
            }
        }
        rec(start_x,start_y);
        cout <<count<<endl;
    }

}

void rec(int x,int y)
{
    if ( y<0 || x<0 || h<=y || w<=x) {return;}
    if ( map[x][y] == '#') {return;}
    if (isVisit[x][y]) { return;}
    isVisit[x][y] = true;
    count++;

    rec(x, y-1);
    rec(x+1, y);
    rec(x, y+1);
    rec(x-1, y);

    return;
}

