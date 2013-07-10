#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int max(int a, int b);
int min(int a, int b);
int is_prime(int n);

int main(int argc, char const* argv[])
{
    int n,p;
    while (cin >> n >> p) 
    {
        if ( n==-1 && p==-1 ) { break; }
        vector<int> arr;

        //素数列を格納
        int count=0;
        int i=n+1;
        while ( count <  p ) 
        {
            if ( is_prime(i) ) 
            {
                //cout << "i = " << i << endl;
                arr.push_back(i);    
                count++;
            }
            i++;
        }

        //
        //for (int i = 0; i < p; i++) 
        //{
        //    cout << arr[i] << endl;
        //}

        //足した素数を格納
        vector<int> sum;
        for (int i = 0; i < p; i++) 
        {
            for (int j = i; j < p; j++) 
            {
                sum.push_back( arr[i] + arr[j] );
            }
        }
        sort(sum.begin(), sum.end());
        cout << sum[p-1] << endl;    
    }
    return 0;
}

int is_prime(int n)
{
    if (n ==1 || n== 0) 
    {
        return 0;
    }
    for (int i = 2; i*i <= n; i++) 
    {
        if (n % i == 0) 
        {
            return 0;
        }
    }
    return 1;

}


int max(int a, int b)
{
    if (a > b) 
    {
        return a;
    }
    else{
        return b;
    }
}
int min(int a, int b)
{
    if (a > b) 
    {
        return b;
    }
    else{
        return a;
    }
}
