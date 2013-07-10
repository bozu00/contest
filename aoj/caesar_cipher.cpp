#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

int main(int argc, char const* argv[])
{
    int table_count=0;
    map<char, char> map;
    char key,value;
    for (int i = 3; i < 26 ; i++) 
    {
        key = 'A' + i;
        value = 'A' + i - 3;
        map[key] = value;
        //
        //cout << key << " " << value << endl;
    }
    map['A'] = 'X';
    map['B'] = 'Y';
    map['C'] = 'Z';
    
    char input; 
    char ch;
    //while (( ch = getchar() ) != EOF) {
    //    cout << map[ch];
    //}
    string readline;
    cin >> readline;
    ///basic_string<char>::iterator ite = s.begin();
    basic_string<char>::iterator ite = readline.begin();

    for (ite = readline.begin(); ite < readline.end(); ite++) 
    {
        cout << map[*ite];
    }
    //
    //    cout << map[ch];


    cout << endl;
    return 0;
}

