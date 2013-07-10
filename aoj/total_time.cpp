#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>

using namespace std;


int main(int argc, char const* argv[])
{
    int time=0;
    int tmp;
    for (int i = 0; i < 4; i++) 
    {
        cin >> tmp;
        time += tmp;
    }
    cout << time / 60 << endl;
    cout << time % 60 << endl;
    return 0;
}

