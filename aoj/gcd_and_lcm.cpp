#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    int gcd_num = gcd(a,b);
    return gcd_num * (a / gcd_num) * (b /gcd_num);
}
int main()
{
    int a,b;
    while(cin >> a >> b)
    {
        cout << gcd(a,b) << " " << lcm(a,b) << endl;
    }
    return 0;
}
