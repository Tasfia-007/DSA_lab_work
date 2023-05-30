//operation of queue using array
#include<bits/stdc++.h>
using namespace std;
#define sz 100
int q[sz];
int l = -1, r = -1;

bool empty() {
    return l == -1;
}

bool full() {
    return r == sz;
}

void push(int data) {
    if (full()) {
        cout << "Queue is full. Cannot push.\n";
        return;
    } else {
        if (empty()) {
            l = 0;
        }
        r++;
        q[r] = data;
    }
}

void pop() {
    if (empty()) {
        cout << "Queue is empty. Cannot pop.\n";
        return;
    } else {
        if (l == r) {
            l = -1;
            r = -1;
        } else {
            q[l] = 0; // Reset the element at the front index
            l++;
        }
    }
}

int getFront() {
    if (empty()) {
        cout << "Queue is empty. No element.\n";
        return -1;
    }
    return q[l];
}

void display() {
    if (empty()) {
        cout << "Queue is empty. Nothing to display.\n";
        return;
    }
    for (int i = l; i <= r; i++) {
        cout << q[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        push(x);
    }
    display();
    pop();
    display();
    cout<<getFront()<<'\n';
        int a;
    cin >> a;
    push(a);
    display();

    return 0;
}
