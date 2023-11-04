#include <iostream>
#include <string.h>
using namespace std;
#define li "\n"

//Q with linked list
template<class t>
class Q
{
    int Size = 0;
    struct nod
    {
        nod* rear;
        t val;
    };
    nod* Front = NULL;
    nod* rear = NULL;
public:

    void enqueue(t n)
    {
        Size++;
        nod* newnod = new nod;
        newnod->val = n;
        newnod->rear = NULL;
        if (isEmpty())
        {
            Front = newnod;
            rear = newnod;
            return;
        }
        rear->rear = newnod;
        rear = newnod;
    }

    bool isEmpty()
    {
        return(Front == NULL && rear == NULL);
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Q is empty" << li;
            return;
        }
        Size--;
        nod* temp = Front->rear;
        delete(Front);
        Front = temp;
    }
    void getFront(t& fron)
    {
        if (isEmpty())
        {
            cout << "Q is empty" << li;
            return;
        }
        fron = Front->val;
    }

    int getSize()
    {
        return Size;
    }

    void getRear(t& Rear)
    {
        if (isEmpty())
        {
            cout << "Q is empty" << li;
            return;
        }
        Rear = rear->val;
    }

    void display()
    {
        nod* temp = Front->rear;
        while (!isEmpty())
        {
            cout << Front->val << ' ';
            delete(Front);
            Front = temp;
            temp = temp->rear;
        }
    }

};
int main()
{
    Q<int>q;
    return 0;
}
