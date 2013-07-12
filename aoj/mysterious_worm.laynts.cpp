#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

//(文字列, 回数)
typedef pair<string, int> P;

//文字列wormを受け取り最短の回数を返す
int bfs(string worm){
	queue<P> que;
	que.push(P(worm, 0));

    //最短の回数を格納するテーブル
    //d["文字列"] = 最短の回数
	map<string, int> d;
	
	while(!que.empty()){
		P p = que.front(); que.pop();

		//重複パターンはcontinue
		if(d[p.first]) continue;

		string str = p.first;

		//全色同じかどうかのチェック 同じならflag = false; 
		bool flag = false; 
		for(int i=0;i<str.size()-1;i++)
        {
			if(str[i] != str[i+1])
            {
				flag = true;
				break;
			}
		}
		//同じなら、その回数をreturn
		if(!flag) return p.second;

		//重複パターン判別用にテーブルに格納する
		d[p.first] = p.second;

		for(int i=0;i<str.size()-1;i++)
        {
			//隣り合わせで色が異なるとき
			if(str[i] != str[i+1])
            {
				char temp;
				string next;

				//tempに含まれない一色を代入
				if(str[i] != 'b' && str[i+1] != 'b')
                {
					temp = 'b';
				}else if(str[i] != 'g' && str[i+1] != 'g')
                {
					temp = 'g';
				}else
                {
					temp = 'r';
				}

				//変化後の順番をnextに詰め込む
				next = str;
				next[i] = next[i+1] = temp;

				//キューにプッシュ
				que.push(P(next, p.second+1));
			}
		}
	}
	return -1;
}

int main(){
	string worm;
	while(cin >> worm && worm != "0")
    {
		int ret = bfs(worm);
		if(ret>=0) cout << ret << endl;
		else cout << "NA" << endl;
	}
}
