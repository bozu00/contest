#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n; 
    string s[100000];
    for (int i = 0; i < n; i++) 
    {
        cin >> s[i];
    }
    int min;
    min = 0;
    for (int i = 0; i < n ; i++) 
    {
        if( s[i] < s[min])
        {
            min = i;
        }
    }
    

    cout << s[min] << endl;
    return 0;
}
