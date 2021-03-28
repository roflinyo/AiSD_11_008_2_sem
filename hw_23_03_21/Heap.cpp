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
        if (array[LeftChild(i)] > array[i] && LeftChild(i) <= size){
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





int main()                        
{  
    MaxHeap * heap = new MaxHeap(4);

    heap->Insert(10);
    heap->Insert(20);
    heap->Insert(5);
    heap->Insert(40);
    heap->Insert(50);
    heap->printAll();
    return 0;

}                              
