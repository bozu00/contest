#include <iostream>
using namespace std;

int rec(int map[20][20],int w,int h, int start_x, int start_y, int dir_i);
int rec_s(int map[20][20],int w,int h, int start_x, int start_y, int dir_i);


int map[20][20]={0};
int w,h;

int main()
{
    int start_x,start_y;

    for (;;) 
    {
        cin >> w >> h;
        for (int i = 0; i < h; i++) 
        {
            for (int j = 0; j < w; j++) 
            {
                cin >> map[i][j];
                if(map[i][j] == 2)
                {
                    start_x=j;
                    start_y=i;
                }
            }
        }
        int a = rec_s(map,w,h, start_x, start_y, 0);
        int b = rec_s(map,w,h, start_x, start_y, 1);
        int c = rec_s(map,w,h, start_x, start_y, 2);
        int d = rec_s(map,w,h, start_x, start_y, 3);
        cout << min(min(a, b) , min( c, d) ) <<endl;
    }
    return 0;
}

int rec(int map[20][20],int w,int h, int start_x, int start_y, int dir_i)
{
    for (int i = 0; i < 3; i++) 
    {
        return rec_s(map,w,h,start_x,start_y,i);
    }
}

int rec_s(int map[20][20],int w,int h, int start_x, int start_y, int dir_i)
{
    int dx[4] ={0,1,0,-1};
    int dy[4] ={1,0,-1,0};
    cout << start_x << start_y << endl;

    //dir_iの方向に止まるまで( 障害物かゴール ) 
    while (map[start_y + dy[dir_i] ][ start_x + dx[dir_i] ] != 1 ||
            map[start_y + dy[dir_i] ][ start_x + dx[dir_i] ] != 2  ) 
    {
        //壁の前ならそこでストップ
        if(dir_i == 0 && start_y == 0)
        {
            return  1+ rec(map, w, h,  start_x, start_y, dir_i);
        }
        if(dir_i == 1 && start_x == w-1)
        {
            return 1 + rec(map, w, h,  start_x, start_y, dir_i);
        }
        if(dir_i == 2 && start_y == h-1)
        {
            return 1 + rec(map, w, h,  start_x, start_y, dir_i);
        }
        if(dir_i == 3 && start_x == 0)
        {
            return 1 + rec(map, w, h,  start_x, start_y, dir_i);
        }
        //途中ゴールがあったらゴール
        if (map[start_y][start_x]== 3) 
        {
            return 1;
        }
        //一マスづつ
        start_x += dx[dir_i];
        start_y += dy[dir_i];
    }//止まったらそこからrec
    map[start_y][start_x] = 0;
    int a = rec_s(map,w,h, start_x, start_y, 0);
    int b = rec_s(map,w,h, start_x, start_y, 1);
    int c = rec_s(map,w,h, start_x, start_y, 2);
    int d = rec_s(map,w,h, start_x, start_y, 3);
    map[start_y][start_x] = 1;
    return min(min(a, b) , min( c, d) );
    //return rec(map, w, h,  start_x, start_y, dir_i);
    
}
//int rec(int map[20][20], int start_x, int start_y)
//{
//    int dx=[0,1,0,-1];
//    int dy=[1,0,-1,0];
//
//    int count = 0;
//    //4方向に移動する
//    for (i = 0; i < 3; i++) 
//    {
//        //止まるまで( 障害物かゴール ) 
//        while (map[start_y + dy[i] ][ start_x + dx[i] ] != 1 ) 
//        {
//            //途中ゴールがあったらゴール
//            if (map[start_y][start_x]== 3) 
//            {
//                return count;
//            }
//            //一マスづつ
//            start_x += dx[i];
//            start_y += dy[i];
//            count++;
//        }//止まったらそこからrec
//        return rec(map, start_x, start_y) + count;
//    }
//}

