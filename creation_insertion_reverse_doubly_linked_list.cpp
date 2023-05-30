#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
};

void Create(Node **head,int d)
{
    Node *ptr = new Node();
    ptr->data = d;
    ptr->next = NULL;
    ptr->prev = NULL ;
    if(*head == NULL)
    {
        *head = ptr;
    }
    else{
        Node *temp = *head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
}

/*   int InsertAtFirst(Node **head,int d,int n)
{
    Node *ptr = new Node();
    ptr->data = d;
    ptr->next = NULL;
    ptr->prev = NULL ;
    (*head)->prev = ptr;
    ptr->next = *head;
    *head = ptr;
    return n+1;
}  */


void display(Node **head)
{
    Node *p = *head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"\n";
}

void Reverse(Node **head)
{
    Node *temp = *head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    Node *last = temp;
    temp = last;
    *head = last;
    Node *st, *ptr;
    while(temp->prev!=NULL)
    {
        st = temp->prev;
        if(temp==last)
            temp->prev = NULL;
        temp->next = st;
        ptr = temp;
        temp = st;
    }
    temp->prev = st;
    temp->next = NULL ;
}

int main()
{
    Node *head = NULL;
    int data,n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>data;
        Create(&head,data);
    }
    display(&head);

  /*  cout<<"Insert at the beginning:"<<endl;
    cin>>data;
    n = InsertAtFirst(&head,data,n);
    display(&head);  */

    Reverse(&head);
    display(&head);
}