#include <iostream>   
#include <math.h>

using namespace std;       

struct  Node
{
    int item;
    Node * next = 0;
};

struct Stack
{
    Node * pHead = 0;

    void Push(int item){
        Node * fr = pHead;
        int a;
        if (!pHead){
            Node * node = new Node;
            node->item = item;
            node->next = 0;
            pHead = node;
        }
        else{
            while (fr){
                //cout << "1";
                if (fr->next){
                    fr = fr->next;
                }
                else{
                    //cout << 0 << "qwerty";
                    Node * node = new Node;
                    node->item = item;
                    node->next = 0;
                    fr->next = node;
                    break;
                }
            }
        }
    }

    int size(){
        Node * fr = pHead;
        int size = 0;
        while (fr){
            size += 1; 
            if (fr->next)
                {
                    fr = fr->next;               
                }
            else{
                break;
            }

        }

        return size;
    }

    int get(int ind){
        int elem;
        int el = 0;
        Node * fr = pHead;
        while (fr){
            el += 1; 
            if (el == ind){
                elem = fr->item;
                break;

            }
            if (fr->next)
                {
                    fr = fr->next;               
                }

        }
        

        return elem;
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


    stack->Push(10);
    stack->Push(20);
    stack->Push(30);
    stack->Push(40);
    //stack->Push(20);
    stack->PrntAll();

    //cout << stack->Pop() << endl;
    
    delete stack;
    return 0;

}                              
