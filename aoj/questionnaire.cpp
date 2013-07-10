#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
    int n,m;
    while (cin >> n >> m) 
    {
        //終端判断
        if (n == 0 && m==0){break;}
        //入力
        int arr[n][m];
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                cin >> arr[i][j];
            }
        }

        vector<int> order(m);
        vector<int> count(m);
        //初期化
        for (int t = 0; t < m; t++) 
        {
            count[t]=0;
            order[t] = t;
        }
        for (int j = 0; j < m; j++) 
        {
            for (int i = 0; i < n; i++) 
            {
                count[j] += arr[i][j];
            }
        }
        //
        //
        //for (int t = 0; t < m; t++) 
        //{
        //    cout << count[t] << " ";
        //}
        //cout << endl;
        //for (int i = 0; i < m-1; i++) 
        //{
        //    for (int j = i+1; j < m; j++) 
        //    {
        //        if (count[i] < count[j]) 
        //        {
        //            swap(order[i], order[j]);
        //        }
        //    }
        //}

        //sort
        for (int i = 0; i < m; i++) 
        {
            for (int j = m-1; i < j; j--) 
            {
                //cout << "order " << endl; 
                //for (int t = 0; t < m; t++) 
                //{
                //    cout << order[t];
                //}
                //cout << endl;
                //cout << "count " << endl;
                //for (int t = 0; t < m; t++) 
                //{
                //    cout << count[order[t]] << " ";
                //}
                //    cout << endl;
                if (count[order[j-1]] < count[order[j] ]) 
                {
                    //puts("swap");
                    //cout << j-1<< " " << j << endl;
                    swap(order[j-1], order[j]);
                }
            }
        }

        for (int t = 0; t < m-1; t++) 
        {
            cout << order[t] + 1 << " " ;
        }
        cout << order[m-1] + 1 << endl;
    }
    return 0;
}

