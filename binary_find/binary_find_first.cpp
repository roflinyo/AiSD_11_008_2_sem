#include <iostream>   
#include <math.h>

using namespace std;   

void print(int num){
    cout << num << endl;
}

int two(int num)                        
{          
    int iter = 0;
    while (num > 1){

        num = num / 2;
        iter ++;

    }

    return iter;                       
};    




int main()                        
{  
    int a[] {0,0,0,0,1,1,1,1,1, 1,1,1,2,2,2,2,3,5,5, 5,5,6,9,9,9,9,9,9};
    //       1,2,3,4,5,6,7,8,9, 0,1,2,3,4,5,6,7,8,9, 0,1,2,3,4,5,6,7,8
    int len = 27;
    int needed = 9;
    int labels = two(28);
    int bord_0 = 0;
    int bord_1 = len;
    int bord_0_h = (bord_1 + bord_0) / 2;
    int bord_1_h = (bord_1 + bord_0) / 2;
    int mid;
    int mid_1;
    int mid_2;
    int coof;

    int b;

    for (int i = 0; i < labels; i++)
    {
        if (bord_0_h == bord_1_h)
        {
            mid = (bord_1 + bord_0) / 2;
            if (a[mid] == needed)
            {
                coof = (bord_0_h + bord_0) / 2;
                if (a[coof] == needed)
                {
                    bord_0_h = coof;
                }
                else
                {
                    bord_0 = coof;
                }
                coof = (bord_1_h + bord_1) / 2;
                if (a[coof] == needed)
                {
                    bord_1_h = coof;
                }
                else
                {
                    bord_1 = coof;
                }

            }
            else if(a[mid] > needed)
            {
                bord_1 = mid;
                bord_0_h = (bord_1 + bord_0) / 2;
                bord_1_h = (bord_1 + bord_0) / 2;
            }
            else
            {
                bord_0 = mid;
                bord_0_h = (bord_1 + bord_0) / 2;
                bord_1_h = (bord_1 + bord_0) / 2;
            }
        }
        else
        {
            mid_1 = (bord_0_h + bord_0) / 2;
            if (a[mid_1] == needed)
            {
                bord_0_h = mid_1;
            }
            else
            {
                bord_0 = mid_1;
            }
            mid_2 = (bord_1_h + bord_1) / 2;
            if (a[mid_2] == needed)
            {
                bord_1_h = mid_2;
            }
            else
            {
                bord_1 = mid_2;
            }
        }
    
    }

    if (a[bord_0] != needed) bord_0 = bord_0_h;
    if (a[bord_1] != needed) bord_1 = bord_1_h;
    cout << bord_0 << endl;
    cout << bord_1 << endl;
    //cout << a[4];
    //cout << a[bord_1_h] << endl;
    return 0;

}               