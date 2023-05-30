#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
    int data;
    struct Node *next;
};

class l_list
{
private:
    Node *head;
    int l;

public:
    l_list()
    {
        head = NULL;
        l = 0;
    }
    int size()
    {
        return l;
    }
    void traverse()
    {
        Node *p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    void insert_begin(int n)
    {
        Node *p = new Node();
        p->next = head;
        p->data = n;
        head = p;
        l++;
    }
    void insert_between(int index, int n)
    {
        Node *ptr = new Node();
        Node *p = head;
        int i = 0;
        while (i != index - 1)
        {
            p = p->next;
            i++;
            if (p->next == NULL && i < index - 1)
            {
                cout << "index doesn't exist\n";
                return;
            }
        }
        ptr->data = n;
        ptr->next = p->next;
        p->next = ptr;
        l++;
    }
    void insert_end(int n)
    {
        Node *ptr = new Node();
        Node *p = head;
        ptr->data = n;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
        l++;
    }
    void insert_afternode(Node *prenode, int n)
    {
        Node *ptr = new Node();
        ptr->data = n;
        ptr->next = prenode->next;
        prenode->next = ptr;
        l++;
    }
    Node *index_node(int x)
    {
        Node *p = head;
        for (int i = 1; i < x; i++)
        {
            p = p->next;
        }
        return p;
    }
    void de_begin()
    {
        if (head == NULL)
        {
            cout << "list already empty\n";
            return;
        }
        Node *ptr = head;
        head = head->next;
        delete ptr;
        l--;
    }
    void de_between(int index)
    {
        if (index - 1 > l)
        {
            cout << "index doesn't exist\n";
            return;
        }
        Node *p = head;
        Node *q = p->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        delete q;
        l--;
    }
    void de_last()
    {
        Node *p = head;
        Node *q = head->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        delete q;
        l--;
    }
    void de_given(int value)
    {
        Node *p = head;
        Node *q = p->next;
        while (q->data != value && q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        if (q->data == value)
        {
            p->next = q->next;
            delete q;
        }
        l--;
    }
    void reverse()
    {
        Node *pre = NULL;
        Node *current = head;
        Node *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        head = pre;
    }
    void sort()
    {
        Node *i=head;
        Node *j;
        while(i!=NULL)
        {
            j=i->next;
            while(j!=NULL)
            {
                if(i->data>j->data)
                {
                    int temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
                j=j->next;
            }
            i=i->next;
        }
    }
};

int main()
{
    l_list a;
    a.insert_begin(10);
    a.insert_begin(20);
    a.insert_end(30);
    a.insert_end(40);
    a.traverse();
    cout << endl;
    a.insert_between(2, 50);
    a.traverse();
    cout << endl;
    a.insert_afternode(a.index_node(3), 55);
    a.traverse();
    cout << endl;
    a.sort();
    a.traverse();
    cout << endl;
    a.reverse();
    a.traverse();
    cout << endl;
    a.de_begin();
    a.traverse();
    cout << endl;
    a.de_last();
    a.traverse();
    cout << endl;
    a.de_between(2);
    a.traverse();
    cout << endl;
    a.de_given(55);
    a.traverse();
    cout << endl;
    return 0;
}