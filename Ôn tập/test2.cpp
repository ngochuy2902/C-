#include <iostream>
#include <math.h>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a=b;
    b=temp;
}
int main() {
    int a,b;
    cout<<"a = "; cin>>a;
    cout<<"b = "; cin>>b;
    cout<<"a = "<<a<<"   "<<"b = "<<b<<endl;
    swap(a,b);
    cout<<"a = "<<a<<"   "<<"b = "<<b<<endl;
}