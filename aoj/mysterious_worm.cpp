#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
using namespace std;

char jump(char c1, char c2);
void bfs(string worm);
int main(int argc, char const* argv[])
{
    string worm;
    cin >> worm;
    while ( worm != "0" ) {
        bfs(worm);
        cin >> worm;
    }
        return 0;
}

void bfs(string worm){
    queue<string> q;
    queue<int> q_time;
    string str;
    int is_stabled=1;
    int i=0;
    q.push(worm); 
    q_time.push(0);

    while ( q.size() != 0 ) 
    {
        str = q.front(); q.pop();
        int time = q_time.front(); q_time.pop();
        //cout<<"worm:" << worm<< endl;
        //cout<<"str:" << str << endl;
        //cout<<"time:" << time << endl;
        //全色同じかチェック
        for (int j=0; j<str.size(); j++){
            if(str[j] == str[j+1]) {
                continue;
            } else {
                is_stabled =0;
                break;
            }
        }
        //全色同じだったらtimeを出力&return0
        //cout<<"is_stabled"<<is_stabled<<endl;
        if(is_stabled == 1) {cout << time <<endl; return;}

        //最初の形とおなじかどうか未実装
            

        //色が違ったらpush
           puts("ok"); 
        for(int j=0; j<str.size(); j++){
            if( str[j] != str[j+1] )
            {
                //cout<< "j" << j<<endl;
                str[j] = jump(str[j],str[j+1]);
                str[j+1] = jump(str[j],str[j+1]);
                q.push(str);
                q_time.push(time++);
            }
        }
    }
    cout << "NA" << endl;
}

char jump(char c1, char c2){
    if(c1 != 'r' && c2 != 'r')
    {
        return 'r';
    }
    else if(c1 != 'g' && c2 != 'g')
    {
        return 'g';
    }
    else if(c1 != 'b' && c2 != 'b')
    {
        return 'b';
    }
}

