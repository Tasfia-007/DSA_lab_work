#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
  int data;
  Node *next;

};

void CreateList1(Node **head1,int d)
{
    Node *ptr = new Node();
    ptr->data = d;
    ptr->next = NULL ;
    if(*head1==NULL)
    {
        *head1 = ptr;
    }
    else{
        Node *temp = *head1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = ptr ;
    }
}

void CreateList2(Node **head2,int d)
{
    Node *ptr = new Node();
    ptr->data = d;
    ptr->next = NULL ;
    if(*head2==NULL)
    {
        *head2 = ptr;
    }
    else{
        Node *temp = *head2;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = ptr ;
    }
}

void Merge(Node **head1, Node **head2)
{
    Node *temp1 = *head1;
    Node *temp2 = *head2;
    Node *st1,*st2;
    while(temp1!=NULL&&temp2!=NULL)
    {
        st1 = temp1->next;
        temp1->next = temp2;
        st2 = temp2->next;
        temp2->next = st1;
        temp1 = st1;
        temp2 = st2;
    }
    *head2 = NULL;
}


void Print(Node **head)
{
   Node *p = *head;
   while(p!=NULL)
   {
       cout<<p->data<<" ";
       p=p->next;

   }
   if(p==NULL)
    cout<<"NULL";
}

int main()
{
    int data1,data2,n;
    Node *head1 = NULL;
    Node *head2 = NULL;
    cin>>n;

    cout<<"Create List_1:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>data1;
        CreateList1(&head1,data1);
    }

    cout<<"Create List_2:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>data2;
        CreateList2(&head2,data2);
    }
   Print(&head1);
   cout<<"\n";
   Print(&head2);
   cout<<"\n";

   Merge(&head1,&head2);
   Print(&head1);
   Print(&head2);
}