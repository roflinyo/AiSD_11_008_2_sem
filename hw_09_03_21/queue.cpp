#include <iostream>   
#include <math.h>

using namespace std;       

struct  Node
{
    int item;
    Node * next = 0;
    Node * prev = 0;
};

struct Stack
{
    Node * pHead = 0;
    Node * pAss = 0;

    void enqueue (int item){
        Node * fr = pHead;
        if (!pHead)
        {
            Node * node = new Node;
            node->item = item;
            node->next = 0;
            node->prev = 0;
            pHead = node;
            pAss = node;
        }
        else{
            Node * node = new Node;
            node->item = item;
            node->next = fr;
            node->prev = 0;
            fr->prev = node;
            pHead = node;
                
            }
        }
    

    int dequeue(){
        Node * fr = pHead;
        int element;
        while (fr){
            if (fr->next)
                {
                    fr = fr->next;               
                }
            else
                {
                    element = fr->item;
                    pAss = fr->prev; 
                    fr->prev->next = 0;
                    delete fr;
                    break;
                }

        }
        

        return element;
    }
    
    void PrntAll(){
        Node * fr = pHead;
        while(fr){
            cout << fr->item << " ";
            if (fr->next){
                fr = fr->next;
            }
            else{
                break;

            }
        }
    }
   


};





int main()                        
{  
    Stack * stack = new Stack;


    stack->enqueue(10);
    stack->enqueue(20);
    stack->enqueue(30);
    stack->enqueue(40);
    stack->enqueue(50);
    //stack->Push(20);
    
    //int a = stack->size();
    //cout << a;
    stack->PrntAll();
    cout << endl;
    int a = stack->dequeue();
    cout << a << endl;
    stack->PrntAll();
    stack->enqueue(60);
    a = stack->dequeue();
    cout << a << endl;
    stack->PrntAll();
    //stack->walk();
    //cout << stack->Pop() << endl;
    
    delete stack;
    return 0;

}                              
