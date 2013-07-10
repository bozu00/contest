#include <iostream>
using namespace std;

int main()
{
    for (;;) 
    {
        int n,m =0;
        cin >> n >> m;
        if (n==0 &&m ==0) 
        {
            break;
        }
        int arr[n+m];
        for (int i = 0; i < n + m;  i++) 
        {
            cin >> arr[i];
        }

        int result_sum = 1000;
        int result_n=0;
        int result_m=0;
        for (int k = 0; k < n; k++) 
        {
            for (int l = n; l < m + n ; l++) 
            {
                int sum_n =0;
                int sum_m =0;
                int tmp = arr[k];
                arr[k] = arr[l];
                arr[l] = tmp;

                //set sum_m sum_n
                for (int i = 0; i < n; i++) 
                {
                    sum_n += arr[i];
                }
                for (int i = n; i < n+m; i++) 
                {
                    sum_m += arr[i];
                }
                if (sum_m == sum_n) 
                {
                    if ( arr[k] + arr[l] < result_sum) 
                    {
                        result_sum = arr[k] + arr[l];
                        result_m = arr[k];
                        result_n = arr[l];
                    }
                }
                tmp = arr[l];
                arr[l] = arr[k];
                arr[k] = tmp;
                //tmp = arr[k];
                //arr[k] = arr[l];
                //arr[l] = tmp;
            }
        }
        if (result_m ==0 && result_n == 0) 
        {
            cout << -1<< endl;
        }else{
        cout << result_n << " " << result_m << endl;
        }
    }
    return 0;
}
