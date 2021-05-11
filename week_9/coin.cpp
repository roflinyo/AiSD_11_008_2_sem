#include <iostream>   
#include <math.h>

using namespace std;       

int main()                        
{  
    int x = 30;
    int f_c = 1;
    int s_c = 5;
    int t_c = 10;

    int a[3]{0,0,0};

    int per = 0;

    bool flag = true;
    while (flag)
    {
        if (per + t_c <= x)
        {
            a[2] += 1;
            per += t_c;
        }
        else if (per + s_c <= x)
        {
            a[1] += 1;
            per += s_c;
        }
        else if (per + f_c <= x)
        {
            a[0] += 1;
            per += f_c;
        }
        else
        {
            flag = false;
        }

    }
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << endl;
    }

    return 0;

}                              
