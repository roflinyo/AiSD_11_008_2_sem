#include <iostream>   
#include <math.h>

using namespace std;       

int power(int a, int b)
{
    int cntr = 1;
    for (int i = 0; i < b; i++){
        cntr = cntr * a;
        
    }

    return cntr;
}

int main()                        
{  
    int num;
    int deg;
    cin >> num >> deg;
    int a = power(num, deg);
    cout << a;
}                              


