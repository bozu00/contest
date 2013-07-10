
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int is_sosuu(int n);
int main()
{
    int n;
    cin >> n;
    while ( n!=0 ) 
    {
        int count=0;
        for (int i = n+1; i <= 2*n; i++) 
        {
            if (is_sosuu(i) == 1) 
            {
                count++;
            } 
        }
        
        cout << count << endl;
        cin >> n;
    }
    return 0;
}
//nが素数なら1を返す
int is_sosuu(int n)
{
    if(n == 1)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt( (double)n ) ; i++) 
    {
        if( (n % i) == 0) 
        {
            return 0;
        }
    }
    return 1;
}
