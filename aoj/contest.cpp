#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


int main(int argc, char const* argv[])
{
    int tmp;
    vector<int> a(10);
    vector<int> b(10);
    for (int i = 0; i < 10; i++) 
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < 10; i++) 
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    sort( a.begin(),a.end(),greater<int>() );
    sort( b.begin(),b.end(),greater<int>() );
    int all_a=0;
    int all_b=0;
    for (int i = 0; i < 3; i++) 
    {
        all_a += a[i];
        all_b += b[i];
    }

    cout << all_a << " " << all_b << endl;
    return 0;
}

