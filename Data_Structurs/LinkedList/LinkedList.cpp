#include <iostream>
#include <string.h>
using namespace std;
#define li "\n"
// Linked List
template<class var>
class linkedList
{
private:
    int length = 0;
    struct nod
    {
        var val;
        nod* next;
    };
    nod* first = NULL;
    nod* last = NULL;
public:
    void insertbegin(var n)
    {
        nod* newnod = new nod;
        newnod->val = n;
        newnod->next = NULL;
        if (first == NULL)
        {
            length++;
            first = last = newnod;
            return;
        }
        newnod->next = first;
        first = newnod;
        length++;
    }
    void insertEnd(var n)
    {
        nod* newnod = new nod;
        newnod->val = n;
        newnod->next = NULL;
        if (first == NULL)
        {
            length++;
            first = last = newnod;
            return;
        }
        last->next = newnod;
        last = newnod;
        length++;
    }
    void insertanyware(int indx, var n)//take range from 0 to n
    {
        if (indx<0 || indx>length)
        {
            return void(cout << "Out of range" << li);
        }
        if (indx == 0)
        {
            insertbegin(n);
            return;
        }
        if (indx == length)
        {
            insertEnd(n);
            return;
        }
        nod* newnod = new nod;
        newnod->val = n;
        nod* cur = first;
        indx--;
        while (--indx > 0)
        {
            cur = cur->next;
        }
        newnod->next = cur->next;
        cur->next = newnod;
        length++;
    }
    void deleteanyware(int indx)//take range of 1 to n
    {
        length--;
        nod* temp = first, * del;
        if (indx == 1)
        {
            first = first->next;
            delete(temp);
            return;
        }
        for (int i = 1; i < indx; i++)
        {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = temp->next->next;
        delete(del);
    }
    void revers()
    {
        if (length == 1)
            return;
        nod* cur = first, * prev = NULL;
        while (cur != NULL)
        {
            nod* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        swap(first, last);
    }
    void Search(var n)//O(n)
    {
        nod* temp = first;
        while (temp != NULL)
        {
            if (temp->val == n)
                return void(cout << "Found" << li);
            temp = temp->next;
        }
        return void(cout << "Not Found" << li);
    }
    int siz()
    {
        return length;
    }
    void display()
    {
        nod* temp = first;
        while (temp != NULL)
        {
            cout << temp->val << ' ';
            temp = temp->next;
        }
    }
};
int main()
{
    linkedList<int>l;
    l.insertEnd(4);
    l.insertEnd(6);
    l.revers();
    l.display(); cout << li;
    l.insertEnd(3);
    l.insertEnd(5);
    l.display(); cout << li;
    l.insertbegin(2);
    l.display(); cout << li;
    l.insertanyware(4, 8);
    l.insertanyware(8, 7);
    l.display(); cout << li;
    l.deleteanyware(1);
    l.display(); cout << li;
    l.revers();
    l.display(); cout << li;
    l.Search(10);
    return 0;
}
