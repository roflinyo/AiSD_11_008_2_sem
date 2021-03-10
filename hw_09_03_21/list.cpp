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

    void Push(int item){
        Node * fr = pHead;
        int a;
        if (!pHead){
            Node * node = new Node;
            node->item = item;
            node->next = 0;
            node->prev = 0;
            pHead = node;
            pAss = node;
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
                    node->prev = pAss;
                    fr->next = node;
                    pAss = node;
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

    void insertAt(int item, int id){
            Node * fr = pHead;
            int x = 0;
            if (id == 0)
            {
                Node * node = new Node;
                node->item = item;
                node->next = fr;
                pHead = node;
                fr->prev = node;
            }
            else{
            while (fr){
                x += 1;
                cout << x << endl;
                if (id == x)
                {   
                        Node * node = new Node;
                        node->item = item;
                        node->next = fr->next;
                        node->prev = fr;
                        fr->next->prev = node;
                        fr->next = node;
                        break;
                }
                
                if (fr->next)
                {
                    fr = fr->next;
                }
                else
                {
                    cout << "ffff" << endl;
                    Node * node = new Node;
                    node->item = item;
                    node->prev = fr;
                    fr->next = node;
                    break;
                }
                
            }
        }

    }
    void removeAt(int ind){
        Node * fr = pHead;
        int x = 0;
        while (fr){
            x += 1; 
            if (x == ind)
              {
                if (fr->prev)
                {
                    if (fr->next)
                    {
                        fr->prev->next = fr->next;
                        fr->next->prev = fr->prev;
                        delete fr;

                    }
                    else
                    {
                        delete fr;
                    }
                }
                else
                {
                    pHead = fr->next;
                    delete fr;
                }
                break;

            }
            if (fr->next)
                {
                    fr = fr->next;               
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
    stack->Push(50);
    //stack->Push(20);
    
    //int a = stack->size();
    //cout << a;
    stack->PrntAll();
    cout << endl;
    stack->removeAt(1);
    stack->PrntAll();

    //stack->walk();
    //cout << stack->Pop() << endl;
    
    delete stack;
    return 0;

}                              
