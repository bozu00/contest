#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int i,j,tmp;
    
    //for (i = 0; i < 3; i++) 
    //{
    //    for (j = i+1; j < 3; j++) 
    //    {
    //        if (a[i] > a[j]) 
    //        {
    //            tmp = a[i];
    //            a[i] = a[j];
    //            a[j] = tmp; 
    //        }
    //    }
    //}
    sort(a, a+3,greater<int>() );

    cout << a[0] << " " << a[1] << " " << a[2]<< endl;
    return 0;
}
