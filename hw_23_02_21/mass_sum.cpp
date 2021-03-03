#include <iostream>   
#include <math.h>

using namespace std;       

int sum(int * a, int size)
{   int summ = 0;
    for(int i = 0; i < size; i++){

        summ = summ + (*a + i);


    }

    return summ;
}

int main()                        
{  
    int numbers[4] = {1,2,3,4};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    int b;
    int *p;
    p = numbers;
    b = sum(p,size);
    cout << b;
}                              


