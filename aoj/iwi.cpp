#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int is_iwi(string s);

map<char, char> my_map;

int main(int argc, char const* argv[])
{
    string s;
    cin >> s;

my_map['i'] = 'i';
my_map['w'] = 'w';
my_map[' '] = ' ';
my_map['('] = ')';
my_map[')'] = '(';

    //char dir[5];
    //dir[0] = 'i';
    //dir[1] = 'w';
    //dir[2] = ' ';
    //dir[3] = ')';
    //dir[4] = '(';

    //if (is_iwi(s)) 
    //{
    //    cout << 0 << endl;
    //    return 0;
    //}

    int count=0; 
    int size=s.size();
    for (int i = 0; i < size / 2; i++) 
    {
        if ( my_map[s[i]] != s[size -1 -i] ) 
        {
            //i番目が対称で無かったら、カウント
            count++;
        }
    }
    if (size % 2 == 1) 
    {
        if (s[size/2] == 'i' || s[size/2] == 'w' || s[size/2] == ' ') 
        {
            
        }else{
            count++;
        }
    }
    cout << count << endl;
    return 0;

    //my_map<string, int> my_map;

    //queue<int> q;
    //while ( !q.empty() ) 
    //{
    //    //string::iterator ite=s.begin();
    //    //for (ite = s.begin(); ite < s.end(); ite++) 
    //    //{
    //    //    ite
    //    //}
    //    for (int i = 0; i < size / 2; i++) 
    //    {
    //        if ( my_map[s[i]] != s[size -1 -i] ) 
    //        {
    //            //i番目が対称で無かったら、順番に試す
    //            for (int j = 0; j < 5; j++) 
    //            {
    //                
    //            } 
    //        }
    //    }
    //}
}

int is_iwi(string s)
{
    int size = s.size();
    for (int i = 0; i < size / 2; i++) 
    {
        if ( my_map[s[i]] != s[size -1 -i] ) {return 0;}
    }
    return 0;
}



