#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
  int *arr;
  int max_size;
  int last;

public:
  Stack()
  {
    arr = new int[100];
    max_size = 10;
    last = -1;
  }
  Stack(int n)
  {
    arr = new int[n];
    max_size = n;
    last = -1;
  }
  int size()
  {
    return last + 1;
  }
  bool empty()
  {
    if (last == -1)
    {
      return true;
    }
    return false;
  }
  bool full()
  {
    if (last == max_size - 1)
    {
      return true;
    }
    return false;
  }

  int top()
  {
    return arr[last];
  }
  void push(int data)
  {
    if (full())
    {
      cout << "stack is full" << endl;
      return;
    }
    last++;
    arr[last] = data;
  }
  void pop()
  {
    if (empty())
    {
      cout << "nothing to pop" << endl;
      return;
    }
    last--;
  }
};
int main()
{
  Stack s;
  s.push(10);
  s.push(8);
  s.push(6);
  s.push(4);
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }

  return 0;
}