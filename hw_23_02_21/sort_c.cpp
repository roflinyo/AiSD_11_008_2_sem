#include <iostream>   
#include <math.h>

using namespace std;       

int sort(int * p, int size)
{
    int sz = size;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < sz - 1; j++)
        {
            if (*(p+j) > *(p+j+1))
            {

                int t = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = t;
            }
        }
        
        sz = sz - 1;
        for (int j = sz - 1; j > 0; j--)
        {
            if (*(p + j) < *(p+j-1))
            {
            
                int t = *(p + j);
                *(p + j) = *(p + j - 1);
                *(p + j - 1) = t;

            }

        }
        sz = sz - 1;
        }

    for (int i = 0;i < size; i ++ )
    {
        cout << *(p + i) << " ";
    }
    return 0;
}


int main()                        
{  
    const int n_1 = 10;
    int mas[n_1] = { 4, 43, 6, 1, 5,23,6,3,2,100 };
    int * p = mas;
    int a = sort(p, n_1);
    return 0;
}       