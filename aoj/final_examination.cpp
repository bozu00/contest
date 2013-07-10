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
    int n;
    while (cin >> n ,n) 
    {
        //if ( n==-1 && p==-1 ) { break; }
        vector<int> arr(5);
        vector<int> sum(n);
        int min_num = 0;
        int max_num = 0;
        for (int t = 0; t < n; t++) 
        {
            for (int i = 0; i < 5; i++) 
            {
                cin >> arr[i];
                sum[t] += arr[i];
            }
        }
        sort( sum.begin(), sum.end() );
        min_num = sum[0];
        max_num = sum[n-1];
        cout << max_num << " " << min_num << endl;
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
