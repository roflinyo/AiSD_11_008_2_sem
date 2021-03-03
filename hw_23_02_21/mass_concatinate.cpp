#include <iostream>   
#include <math.h>

using namespace std;       



int main()                        
{  
    int n_1 = 4;
    int n_2 = 5;
    int *mas_1 = new int[n_1]{ 1, 2, 3, 4 };
    int *mas_2 = new int[n_2]{ 5, 6, 7, 8, 9};
    int *mas_3 = new int[n_2 + n_1]();

    
    int *ford_1 = mas_1;
    int *ford_2 = mas_2;
    for (int i = 0; i < n_1; i++)
    {
        int * p = &mas_1[i];
        mas_3[i] = *p;
    }
    for (int i = 0; i < n_2; i++){

        int * p = &mas_2[i];
        mas_3[i + n_1] = *p;

    }
    for(int j = 0; j < n_2 + n_1; j++){

        cout << mas_3[j] << " ";
    }
    return 0;
}                              
