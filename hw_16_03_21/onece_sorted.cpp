#include <iostream>   
#include <math.h>

using namespace std;

struct  Node
{
    int item;
    Node * next = 0;
    Node * prev = 0;
};

struct SortedList
{
    Node * pHead = 0;
    Node * pAss = 0;

    void Push(int item){
        Node * fr = pHead;
        int i = 0;
        
        
        if (!pHead){
            Node * node = new Node;
            node->item = item;
            node->next = 0;
            node->prev = 0;
            pHead = node;
            pAss = node;
        }
        else if (item < fr->item){
                Node * node = new Node;
                node->item = item;
                fr->prev = node;
                node->next = fr;
                pHead = node;
            }
 
        else{
            while (fr){

                if (item == fr->item){
                    break;
                }
                else{

                if (item < fr->item){
                    Node * node = new Node;
                    node->item = item;
                    node->next = fr;
                    node->prev = fr->prev;
                    fr->prev->next = node;
                    fr->prev = node;
                    break;
                }

                if (fr->next){
                    fr = fr->next;
                }
                else{
                    Node * node = new Node;
                    node->item = item;
                    fr->next = node;
                    node->prev = fr;
                    pAss = node;
                    break;
                }

                }

               



            }
        }
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
        cout << endl;
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

int Union(SortedList * a, SortedList * b){



    return 0;
};



int main()                        
{  

    SortedList * a = new SortedList;
    SortedList * b = new SortedList;

    a->Push(10);
    b->Push(10);
    a->Push(20);
    b->Push(20);
    a->Push(30);
    b->Push(30);
    //stack->Push(20);
    a->PrntAll();
    b->PrntAll();
    //int a = stack->get(2);
    //cout << a << endl;
    //stack->removeAt(3);
    //stack->PrntAll();
    //int b = stack->size();
    //cout << b;

    //cout << stack->Pop() << endl;
    
    delete a;
    return 0;

}                              
