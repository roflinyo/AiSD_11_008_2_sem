#include <iostream>   
#include <math.h>

using namespace std;       

int main()                        
{  
    int k;
    cin >> k;

    int exes[1000][3];
    int prog[1000];
    int prog_day = 5;
    for (int l = 0; l < prog_day;l++)
    {
        prog[l] = 0;
    }

    int a,b,c;
 

    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c;

        exes[i][0] = a;
        exes[i][1] = b;
        exes[i][2] = c;
        
    }
    //пусть этот массив будет отсортирован по стоимости: Сначала дорогие, потом дешевле.
    //Долго эту сортировку писать


    int loop;
    bool flag;

    for (int j = 0; j < k; j ++)
    {

        if (exes[j][2] <= prog_day)
        {
            if (!prog[exes[j][2]])
            {
                prog[exes[j][2]] = exes[j][0];
            }
            else
            {
                flag = true;
                loop = exes[j][2];
                while (flag)
                {
                    loop = loop - 1;
                    if (!prog[loop])
                    {
                        prog[loop] = exes[j][0];
                        flag = false;
                    }

                }
            }

        }
        
    }
    for (int per = 0;per < prog_day;per++)
    {
        cout << prog[per] << endl;
    }

    
    return 0;

}                              
