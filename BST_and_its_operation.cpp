#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *insertion(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertion(root->right, d);
    }
    else if (d < root->data)
    {
        root->left = insertion(root->left, d);
    }
    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertion(root, data);
        cin >> data;
    }
}
node *minval(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
node *deletion(node *root, int val)
{
    // have no root values
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // have 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // have 1 child in left
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        //have 1 child in right
        if (root->left == NULL && root->right != NULL)
        {
            node *temp=root->right;
            delete root;
            return temp;
        }
        //have two child
        if (root->left!=NULL && root->right!=NULL)
        {
            int mini=minval(root->right)->data;
            root->right=deletion(root->right,val);
            return root;
        }
        
    }
    else if(root->data>val)
    {
        root->left=deletion(root->left,val);
        return root;
    }
    else
    {
        root->right=deletion(root->right,val);
        return root;
    }
}
void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    node *root=NULL;
    cout<<"enter data"<<endl;
    takeinput(root);
    cout << "Inorder:\n";
    inorder(root);
    cout << endl;
     cout << "after deltion" << endl;
    node *x=deletion(root,30);
    inorder(x);
    cout << endl;
    return 0;
}