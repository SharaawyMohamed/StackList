#include <iostream>
#include <string.h>
using namespace std;
#define li "\n"
template<class T>
class doubleLinkeList
{
private:
    struct nod
    {
        T val;
        nod* left;
        nod* right;
    };
    int length = 0;
    nod* first = NULL;
    nod* last = NULL;
public:
    void addfirst(T n)
    {
        nod* newnod = new nod;
        newnod->val = n;
        newnod->left = NULL;
        newnod->right = NULL;
        if (length == 0)
        {
            first = newnod;
            last = newnod;
            length++;
            return;
        }
        newnod->right = first;
        first->left = newnod;
        first = newnod;
        length++;
    }
    void addlast(T n)
    {
        nod* newnod = new nod;
        newnod->val = n;
        newnod->left = NULL;
        newnod->right = NULL;
        if (length == 0)
        {
            first = newnod;
            last = newnod;
            length++;
            return;
        }
        newnod->left = last;
        last->right = newnod;
        last = newnod;
        length++;
    }
    void addanyware(int indx, T n) // indx --->zero based
    {
        if (indx<0 || indx>siz())
        {
            cout << "Out of range" << li;
            return;
        }
        if (indx == 0)
        {
            addfirst(n);
            return;
        }
        if (indx == siz())
        {
            addlast(n);
            return;
        }
        length++;
        nod* newnod = new nod, * temp = first;
        newnod->val = n;
        newnod->left = NULL;
        newnod->right = NULL;

        for (int i = 1; i < indx; i++)
        {
            temp = temp->right;
        }
        newnod->right = temp->right;
        temp->right->left = newnod;
        newnod->left = temp;
        temp->right = newnod;
    }
    void delet(int indx)    // Work As One Based
    {
        nod* temp;
        if (indx <= 0 || indx > length)
        {
            cout << "Out of range" << li;
            return;
        }
        if (indx == 1)
        {
            temp = first->right;
            first->right->left = NULL;
            delete(first);
            first = temp;
            length--;
            return;
        }
        if (indx == length)
        {
            temp = last->left;
            last->left->right = NULL;
            delete(last);
            last = temp;
            length--;
            return;
        }
        length--;
        nod* cur = first;
        for (int i = 1; i < indx; i++)
        {
            cur = cur->right;
        }
        temp = cur->left;
        temp->right = cur->right;
        temp->right->left = temp;
        delete(cur);
    }
    int siz()
    {
        return length;
    }
    void print()
    {
        nod* temp = first;
        while (temp != NULL)
        {
            cout << temp->val << ' ';
            temp = temp->right;
        }
    }
    void printreverse()
    {
        nod* temp = last;
        while (temp != NULL)
        {
            cout << temp->val << ' ';
            temp = temp->left;
        }
    }
    ~doubleLinkeList() {};
};
int main()
{
    doubleLinkeList<int>dl;
    dl.addfirst(5);
    dl.addlast(6);
    dl.addfirst(4);
    dl.addlast(7);
    dl.addfirst(3);
    dl.addlast(8);
    dl.addanyware(5, 15);// take index as zero based
    dl.print();
    cout << li;
    dl.delet(6);// work as one based;
    dl.print();
    cout << li;
    dl.printreverse();
    return 0;
}
