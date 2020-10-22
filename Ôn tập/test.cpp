#include <iostream>
#include <math.h>

using namespace std;

bool Ngto(int x){
    int i;
    if (x<2) return false;
    for(i = 2; i <= sqrt(x); i++) 
        if (x%i==0) return false;
    return true;
}

int main() {
    int n;
    int a[5];
    cout<<"N = ";cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"A["<<i<<"] = "; cin>>a[i];
    }
    for (int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    for (int i=0; i<n; i++) {
        cout<<Ngto(a[i]);
    }
    

    return 0;
}