#include <bits/stdc++.h>
using namespace std;

int f(int n){
    if( n==1 ) return 1;
    if(n==0) return 0;
    return f(n-1) + f(n-2);
}

int fibo(int n){
    int a = 0,b=1,c;
    for(int i=0;i<n;i++){
        cout<<a<<" ";
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    cout<<"\n";
    cout<<fibo(6);
    return 0;
}