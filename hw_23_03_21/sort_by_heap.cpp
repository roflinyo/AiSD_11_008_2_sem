#include <iostream>   
#include <math.h>


using namespace std;      
 
struct MaxHeap
{
    int size;
    int maxSize;
    int * array;

    MaxHeap(int maxSize){
        this->maxSize = maxSize;
        size = -1;
        array = new int [maxSize];
    }

     
    void Insert(int p)
    {
       
        if (size < maxSize-1){
            size++;
            array[size] = p;
            //cout << array[size] << "qwerty";
            SiftUp(size);
        }
        else{
            //cout << "bbbbbbbb"<< endl;
            size++;
            new_mass(p);
        }
        // size++;
        // array[size] = p;
        // SiftUp(size)
    }

     
    void SiftUp(int i)
    {
        while (i > 0 && array[i] > array[Parent(i)]){
            int t = array[i];
            array[i] = array[Parent(i)];
            array[Parent(i)] = t;
            i = Parent(i);
        }
        //    поменять местами родителя и ребёнка
        //    i = Parent(i)
    }

     
    void SiftDown(int i)
    {
        int maxIndex = i;
        if (array[LeftChild(i)] > array[i] && LeftChild(i) <= size && array[LeftChild(i)] > array[RightChild(i)]){
            int t = array[i];
            array[i] = array[LeftChild(i)];
            array[LeftChild(i)] = t;
            maxIndex = LeftChild(i);
            SiftDown(maxIndex);
        }
        else if (array[RightChild(i)] > array[i] && RightChild(i) <= size){
            int t = array[i];
            array[i] = array[RightChild(i)];
            array[RightChild(i)] = t;
            maxIndex = RightChild(i);
            SiftDown(maxIndex);
        }
        // Если в LeftChild(i) значение больше, чем в i, то maxIndex=LeftChild(i)
        // Если в RightChild(i) значение больше, чем в i, то maxIndex=RightChild(i)
        // Если maxIndex != i, то: поменять их значения местами, вызвать SiftDown(maxIndex)
    }

     
    int ExtractMax()
    {
        int result = array[0];
        int t = array[0];
        array[0] = array[size];
        array[size] = t;
        size--;
        
        SiftDown(0);
        return result;
    }


    void new_mass(int p){
        //cout << p;
        int * array_n = new int [maxSize * 2];
        for (int i = 0; i < maxSize;i++){
            array_n[i] = array[i];
        }
        array_n[size] = p;
        maxSize = maxSize * 2;
        array = array_n;
        delete array_n;
        SiftUp(size);



    }



     
    int Parent(int i) { return (i - 1) / 2; }
    int LeftChild(int i) { return 2 * i + 1; }
    int RightChild(int i) { return 2 * i + 2; }
    void printAll(){
        
        for (int i = 0;i <= size;i++){
            cout << array[i] << endl;
        }
        cout << "_____________"<< endl;
    }


};

int two_deg(int num){
    int iter = 0;
    while (num > 1){

        num = num / 2;
        iter ++;

    }
    
    return iter + 1;            

};

int power(int a, int b)
{
    int cntr = 1;
    for (int i = 0; i < b; i++){
        cntr = cntr * a;
        
    }

    return cntr;
};

int * HeapSort(int * array, int size) {

    MaxHeap * heap = new MaxHeap(power(2,two_deg(size)));
    int * help_ar = new int[15];
    for (int i = 0;i<size;i++){
        heap->Insert(array[i]);
    }
    for (int i = 0;i<size;i++){
        help_ar[i] = heap->ExtractMax();
    }
    
    return help_ar;
};





int main()                        
{  
    int size = 15;
    int * array = new int [size]{15,12,9,10,14,6,8,1,3,4,11,2,13,5,7};

    int * array_n = HeapSort(array,size);
   
    for (int i = 0;i < size;i++){
        cout << array_n[i] << endl;
    }

    return 0;

}                              
