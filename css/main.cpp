#include <iostream>
#include <string.h>
using namespace std;
#define li "\n"
template<class T>
class St
{
private:
    struct nod
    {
        T val;
        nod* ptr;
    };
    nod* top;
public:
    St():top(NULL)
    {};
    void Push(T val)
    {
        nod *newnod=new nod;
        newnod->val=val;
        newnod->ptr=top;
        top=newnod;
    }
    bool isEmpty()
    {
        return (top==NULL);
    }
    void Pop(T&StTop)
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<li;
            return;
        }
        StTop=top->val;
        nod *temp=new nod;
        temp=top;
        top=top->ptr;
        temp=temp->ptr=NULL;
        delete(temp);
    }
    void getTop(T&StTop)
    {
        if(isEmpty())
        {
            cout<<"Stack is empty";
            return;
        }
        StTop=top->val;
    }
    void display()
    {
        while(!isEmpty())
        {
            cout<<top->val<<' ';
            nod *temp=new nod;
            temp=top;
            top=top->ptr;
            temp=temp->ptr=NULL;
            delete(temp);
        }
    }
};
int main()
{
    St<int> st;
    st.Push(1);
    st.Push(2);
    cout<<"Top";
    int Top;
    st.getTop(Top);
    cout<<Top;
    cout<<li;
    st.Push(3);
    st.Push(4);
    st.Pop(Top);
    st.getTop(Top);
    cout<<"TOP"<<Top<<li;
    st.Push(5);
    st.display();
    return 0;
}
