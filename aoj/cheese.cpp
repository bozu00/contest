#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
using namespace std;
//from は残りのチーズ数
int bfs(int from);
//訪れたら1
int is_visit[1000][1000] = {0};
char map[1000][1000] = {0};
int cheese_count = 0;
queue<int> q_i;
queue<int> q_j;
queue<int> q_cheese_count;
queue<int> q_hp;
queue<int> q_dis;
int hp=1;

int h, w, n;
int start_i , start_j;
int dj[] = {0,1,0,-1 };
int di[] = {-1,0,1,0 };

int main(int argc, char const* argv[])
{
    cin >> h >> w >> n;
    cheese_count = n;
    //map配列初期化&start位置取得
    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++) 
        {
            cin >> map[i][j];
            if (map[i][j]== 'S') 
            {
                start_i = i;
                start_j = j;
            }
        }
    }
    q_i.push(start_i);
    q_j.push(start_j);
    q_cheese_count.push(n);
    q_hp.push(1);
    q_dis.push(-1);

    int result = 0;
    for (int i = 0; i < n; i++) 
    {
        result += bfs(i);
        printf("i=%d,%d\n", i,result);
        printf("stach_size()=%d\n",q_i.size());
    }
    printf("%d\n", result);
    return 0;
}



//チーズfromからfrom+1までの最短経路を返す関数
//start_indexを渡さないと行けない
int bfs(int from)
{
    //is_visit初期化
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++) {
            is_visit[i][j] = 0;
            if (map[i][j] == from) 
            {
                start_i = i;
                start_j = j;
            }
        }
    } 
    q_i.push(start_i);
    q_j.push(start_j);
    int now_dis = 0;
    while (q_i.size()) 
    {
        //情報の取り出し&削除
        int now_i= q_i.front();                         q_i.pop();
        int now_j = q_j.front();                        q_j.pop();
        int now_hp = q_hp.front();                      q_hp.pop();
        int now_dis = q_dis.front();                    q_dis.pop();

        //訪れた
        is_visit[now_i][now_j] = 1;
        //距離を++
        now_dis++;

        //チーズにあったとき
        if ( isdigit(map[now_i][now_j]) == 1 && (int)(map[now_i][now_j] - '0')  == from + 1 ) 
        {
            hp ++;
            printf("(%d, %d)\n", now_i, now_j);
            printf("i:%d ,now_dis:%d\n", from,  now_dis);
            //現在有るスタックを空にして
            //今の位置をスタックに入れて値を返す(関数の終了)
            while (q_i.size() != 0){
                q_i.pop();
                q_j.pop();
                q_hp.pop();
                q_dis.pop();
            }
            q_i.push(now_i);
            q_j.push(now_j);
            q_hp.push(now_hp);
            q_dis.push(now_dis);
            return now_dis;
        } else {
            //キューに入れる
            for (int i = 0; i < 3; i++) 
            {
                //次のマスno設定
                int next_i = now_i + di[i];
                int next_j = now_j + dj[i];
                //次のマスが範囲内
                //          障害物じゃない
                //          訪れていない
                //ならキューに入れる
                if ( -1 < next_i &&   next_i < h &&
                     -1 < next_j &&  next_j < w && 
                     map[next_i][next_j] != 'X'&&
                     is_visit[next_i][next_j] != 1) 
                {
                    printf("(%d, %d)\n", next_i, next_j);
                    q_i.push(next_i);
                    q_j.push(next_j);
                    q_hp.push(now_hp);
                    q_dis.push(now_dis);
                    is_visit[next_i][next_j] = 1;
                }
            }
        }
    }
}
