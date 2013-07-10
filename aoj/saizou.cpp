#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;

int max(int a, int b);
int min(int a, int b);

int main(int argc, char const* argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) 
    {
        int n;
        cin >> n;
        int min_num=0;
        int max_num=0;
        int pre=0;
        int next=0;
        cin >> pre;
        for (int j = 0; j < n-1; j++) 
        {
            next = pre;
            cin >> pre;
            max_num = max( max_num, next-pre);
            min_num = min( min_num, next-pre);
        }
        //cout << max_num << " " << -1 * min_num << endl;
        cout << -1 * min_num << " " << max_num << endl;
    }
    return 0;
}

int max(int a, int b)
{
    if (a > b) 
    {
        return a;
    }
    else{
        return b;
    }
}
int min(int a, int b)
{
    if (a > b) 
    {
        return b;
    }
    else{
        return a;
    }
}
