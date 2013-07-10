#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    vector<string> data;
    vector<string>::iterator p;
    for (int i = 0; i < n; i++) 
    {
        cin >> s; 
        if ( find(data.begin(), data.end() , s) != data.end() ) 
        {
            if (i % 2  ==  1) 
            {
                cout << "WIN" << endl;
                return 0;
            }
            else if (i % 2  == 0)
            {
                cout << "LOSE" << endl;
                return 0;
            }
        }
        if( i != 0 && *( data[i-1].end() -1 ) != *( s.begin() ) )
        {
            //クンのターン中に規則が守られていない
            if (i % 2  ==  1) 
            {
                cout << "WIN" << endl;
                return 0;
            }
            //君のターン中に規則が守られていない
            else if (i % 2  == 0)
            {
                cout << "LOSE" << endl;
                return 0;
            }
        }
        data.push_back(s);
    }
    cout<< "DRAW" << endl;
    return 0;
}
