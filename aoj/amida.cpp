#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;

class Border {
    public:
        int h;
        int p;
        int q;
};

int main(int argc, char const* argv[])
{
    int n,m,a;
    //縦線の本数，横線の本数，調べる縦線の番号
    int now_h=0;
    while (cin >> n >> m >> a) 
    {
        int ret = a;
        if (n == 0 && m == 0 && a == 0) {break;}
        vector<Border> b(m);

        //横線の取得
        for (int i = 0; i < m; i++) 
        {
            cin >> b[i].h;
            cin >> b[i].p;
            cin >> b[i].q;
        }
        

        //now_hの取得
        for (int i = 0; i <m ; i++) 
        {
            now_h = max(b[i].h, now_h);
        }

            //
            //cout << "now_h" << now_h << endl;
            //cout << "m" << m<< endl;
        //一番したまで降りる
        while (now_h >= 0) 
        {
            //
            //cout << "now_h" << now_h << endl;
            //
            //int test;
            //cin >> test;
            //適合する横棒を探す
            for (int i = 0; i < m; i++) 
            {
                //適合する横棒が存在したら、移動して下に降りる
                if (b[i].h == now_h ) 
                {
                    if (b[i].p == ret ) 
                    {
                        ret = b[i].q;
                        break;
                    }
                    else if (b[i].q == ret ) 
                    {
                        ret = b[i].p;
                        break;
                    }
                }
                //適合する横棒が存在しなかったら,移動せずに下に降りる
                else 
                {
                    continue;
                }
            }
            now_h--;
        }
        cout << ret << endl;
    }
    return 0;
}
