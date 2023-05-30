/*  Infix to Prefix    */
 

#include<bits/stdc++.h>
using namespace std;

class Stack{
    int t = -1;
    char a[1000];
    public:
    void push(char x)
    {
        t+=1;
        a[t]=x;
    }
    void pop()
    {
        t-=1;
    }
    char top()
    {
        return a[t];
    }
    bool empty()
    {
        if(t==-1)
        return true;
        return false;
    }
};

bool IsOperand(char ch)
{
    if(isdigit(ch)||isalpha(ch))
    return true;
    return false;
}

bool IsOperator(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch== '^');
}

int Precedence(char p)
{
    if(p=='+'||p=='-')
    return 1;
    else if(p=='*'||p=='/')
    return 2;
    else if(p=='^')
    return 3;
    else
    return -1;
}

bool HasHigherPrecedence(char op1,char op2)
{
    int p1 = Precedence(op1);
    int p2 = Precedence(op2);
    return p1>=p2;
    return false;
}


string InfixToPrefix(string expr)
{
     Stack s;
    string p,rev;
    for(int i=expr.length()-1;i>=0;i--)
        rev += expr[i];
        
        for(int i=0;i<rev.length();i++)
        {
            char c = rev[i];
            if(IsOperand(c))
             p +=c ;
             else if(c==')')
             s.push(c);
             else if(c=='(')
             {
                 while(!s.empty()&&s.top()!=')')
                 {
                     p+=s.top();
                     s.pop();
                 }
                 s.pop();
             }
             else if(IsOperator(c))
             {
                 while (!s.empty() && HasHigherPrecedence(s.top(),c)) {
                p += s.top();
                s.pop();
            }
            s.push(c);
             }
        }
        while(!s.empty())
        {
            p+=s.top();
            s.pop();
        }
        
        string final;
        for(int i=p.length()-1;i>=0;i--)
        final+=p[i];
        
        return final;
}

int main()
{
   
    string expr,pre,rev;
    cin>>expr;
    cout<<expr<<endl;
    cout<<InfixToPrefix(expr)<<endl;
        
}