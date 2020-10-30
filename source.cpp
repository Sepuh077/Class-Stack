#include <iostream>

using namespace std;

///////////////////////////////////////////////////////
template<typename T>
class stack {
    T* a;
    int n;
public:
    stack();
    stack(const stack<T>& s);
    ~stack() {
        if(n!=0)
            delete[] a;
    }
    bool empty() const;
    int size() const;
    T top() const;
    void push(T g);
    void pop();
    void swap();
};

///////////////////////////////////////////////////////////////////
template <class T>
stack<T>::stack() {
    n = 0;
}

template <class T>
stack<T>::stack(const stack<T>& s) {
    n = s.n;
    a = new T[n];
    for(int i=0;i<s.n;++i) {
        a[i] = s.a[i];
    }
}

template <class T>
bool stack<T>::empty() const {
    if(n == 0)
        return true;
    return false;
}

template <class T>
int stack<T>::size() const {
    return n;
}

template <class T>
T stack<T>::top() const {
    if(n!=0)
        return a[n-1];
    throw "Your stack doesnt have any member!";
}

template <class T>
void stack<T>::push(T g) {
    T* x = new T[n];
    if(n > 0) {
        for(int i=0;i<n;++i)
            x[i]=a[i];
        delete[] a;
    }
    n++;
    a = new T[n];
    for(int i=0;i<n-1;i++)
    {
        a[i]=x[i];
    }
    a[n-1] = g;
    delete[] x;
}

template <class T>
void stack<T>::pop() {
    if(n==0)
        throw "Your stack doesnt have any member!";
    else
    {
        if(n==1) {
            delete[] a;
            n = 0;
        }
        else {
            T* x = new T[n - 1];
            for(int i = 0;i < n-1;++i)
                x[i]=a[i];
            n--;
            delete[] a;
            a = new T[n];
            for(int i = 0;i < n;i++) {
                a[i] = x[i];
            }
            delete[] x;
        }
    }
    
}

template <class T>
void stack<T>::swap() {
    if(n != 0) {
        for(int i = 0;i < (n-1)/2;++i) {
            T x = a[i];
            a[i] = a[n-i-1];
            a[n-i-1] = x;
        }
    }
}

///////////////////////////////////////////////////////
// Function for find maximum value in stack
int find_max(stack<int> a, int max_v) {
    if(a.size() == 0)
        return max_v;
    if(max_v < a.top())
        max_v = a.top();
    a.pop();
    

    return find_max(a,max_v);
}
///////////////////////////////////////////////////////
int main() {
    stack<int> a;
    int count, member;
    cin>>count;
    for(int i = 0;i < count;++i) {
        cin>>member;
        a.push(member);
    }
    if(a.size() == 0)
        cout<<"You don not have any member!!!"<<endl;
    else
        cout<<find_max(a,a.top())<<endl;
    return 0;
}