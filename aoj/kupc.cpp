#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const* argv[])
{
    string s;
    cin >> s;
    string::iterator ite=s.begin();
    vector<int> a(4);

    for (ite = s.begin(); ite < s.end(); ite++) 
    {
        if (*ite == 'K') {a[0]++;}
        if (*ite == 'U') {a[1]++;}
        if (*ite == 'P') {a[2]++;}
        if (*ite == 'C') {a[3]++;}
    }
    int min;
    sort( a.begin(), a.end());
    min = a[0];
    cout << min << endl;
    return 0;
}

