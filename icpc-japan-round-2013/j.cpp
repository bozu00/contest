#include <stdio.h>
#include <iostream>

using namespace std;
int main(int argc, char const* argv[])
{
    int tmp;
    int max=0;
    while (cin >> tmp && tmp != 0) 
    {
       if(max < tmp) max = tmp; 
    }
    cout << max << endl;
    return 0;
}
