#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    int p_array[50];
    int p,n;
    int wan;
    while (1) 
    {
        int max_index=0;
        int max_p= 0;
        int k=0,l=0;
        cin >> n >> p;
        wan = p;
        if (n == 0 && p==0) 
        {
            break;
        }

        //init p_array
        for (int j = 0; j < n; j++) 
        {
            p_array[j] = 0;
        }
        while (max_p != p) 
        {
            if (wan != 0) 
            {
                wan--;
                p_array[k]++;
            }
            else if(wan == 0)
            {
                wan = p_array[k];
                p_array[k] = 0;
            }
            //search max_p
            for (l = 0; l < n; l++) 
            {
                if (max_p < p_array[l]) 
                {
                     max_p = p_array[l];
                     max_index = l;
                }
            }
            //for (int m = 0; m < n; m++) 
            //{
            //    cout << p_array[m] << " ";
            //}
            //cout << "max_index= " << max_index;
            //cout << endl;
            k++;
            k = k % n;
        }
        cout << max_index << endl;
    }
    return 0;
}
