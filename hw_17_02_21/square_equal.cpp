#include <iostream>   
#include <math.h>

using namespace std;       

int main() 

{        
    int a;
    int b;
    int c;
    cin >> a >> b >> c;

    float d = b*b - 4 * a * c;
    if (d < 0){
        cout << "answer.net";
    }
    else if (d == 0){
        float x = -b/2*a;
        cout << x;
    }
    else{
        float disrk = sqrt(d);
        float x1 = (-b + disrk) / 2*a;
        float x2 = (-b - disrk) / 2*a;
        cout << x1 << x2;
    }   
    return 0;                       
}                              
