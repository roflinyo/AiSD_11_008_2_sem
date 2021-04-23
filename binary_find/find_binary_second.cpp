#include <iostream>   
#include <math.h>

using namespace std;   


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
    const int a = 4;
    const int b = 4;
    int ary[a][b] {{1,3,5,7}, {8,10,12,14}, {16,18,20,22}, {45,67,68,70}};
    
    int bord_0 = 0;
    int bord_1 = a - 1;
    int mid;
    int labels_1 = two(a);
    int labels_2 = two(b);
    int needed = 21;
    int key = 0;
    if (ary[bord_0][0] == needed || ary[bord_1][0] == needed)
    {
        cout << "In";
    }
    else
    {
         for (int  i = 0; i < labels_1; i ++)
        {
            mid = (bord_0 + bord_1) / 2;
            if (ary[mid][0] == needed)
            {
                key = mid;
                break;

            }
            else if(ary[mid][0] < needed)
            {
                bord_0 = mid;
            }
            else
            {
                bord_1 = mid;
            }
        }
    }
    int bord_0_1 = 0;
    int bord_1_1 = b -1; 
    for (int j = 0;j < labels_2; j++)
    {
        mid = (bord_0_1 + bord_1_1) / 2;
        if (ary[bord_0][mid] == needed)
        {
            key = mid;
            break;

        }
        else if(ary[bord_0][mid] < needed)
        {
            bord_0_1 = mid;
        }
        else
        {
            bord_1_1 = mid;
        }
        
    }

    if (ary[bord_0][bord_0_1] == needed || ary[bord_0][bord_1_1] == needed){
        key = needed;
    }


    if (key) cout << "in";
    else cout << "not in";
    
    //cout << a[4];
    //cout << a[bord_1_h] << endl;
    return 0;

}               