#include <iostream>   
#include <math.h>

using namespace std;       

int main()                        
{          
    int a;
    cin >> a;
    int iter = 0;
    while (a > 1){

        a = a / 2;
        iter ++;

    }
    cout << iter;
    return 0;                       
}                              
