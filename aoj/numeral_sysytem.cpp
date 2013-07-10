#include <iostream>
#include <string>
using namespace std;

int main()
{
    for (;;) 
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) 
        {
            string x,y;
            cin >> x >> y;
            int a,b;
            
        }
    }
    return 0;
}

int toInt(string x)
{
    int num_size = x.size();
    string res;
    while(x.size() != 0)
    {
        if ( isdisit(x[0]) == true 
                && isalpha(x[1]) == true) 
        {
            res += x[0] * tbl(x[1]);
        }
        if ( isalpha(x[0]) == true
                && isalpha(x[1])== false) 
        {
            res +=  tbl(x[1]);
        }
    }
}
int tbl(char n)
{
    if(n == 'm')
    {
        return 1000;
    }if else(n == 'c'){
        return 100;
    }if else(n == 'x'){
        return 10;
    }if else(n == 'i'){
        return 1;
    }
}
