#include <iostream>       
using namespace std;       
int main()                        
{          
    int iter;
    cin >> iter;    
    int num;
    int sum = 0;
    for (int i = 0; i < iter; i++){
        cin >> num;
        sum += num;
    }
    cout << sum + 1;
    //cout << "Hello World!"<< age;   
    return 0;                       
}                              