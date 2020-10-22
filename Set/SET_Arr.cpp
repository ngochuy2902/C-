#include <iostream>
using namespace std;
struct SET {
    int n, max;
    int *data;
    SET(int m = 10);
    ~SET();
    SET(const SET &x);
    SET operator + (int x);
    SET operator - (int x);
    int &operator [] (int i) const;
    bool operator () (int x);
    const SET &operator = (const SET &x);
};
SET::SET(const SET &x){
    max = x.max;
    data = new int [max];
    n = x.n;
    for(int i=0; i<n; i++) data[i] = x[i];
}
ostream& operator <<(ostream &out,const SET  &x){
    out<<"{";
    if (x.n>0) {
        for (int i=0; i<x.n-1; i++)
            out<<x.data[i]<<",";
        out<<x.data[x.n-1];
    }
    cout<<"}"<<endl;
    return out;
}
SET::SET(int m){ //khởi tạo
    max = m;
    data = new int [max];
    n = 0;
}
SET::~SET(){
    delete [] data;
}
SET SET::operator + (int x){
int t=0;
//SET a(max + 1);
while (t<n && data[t]<x) t++;
if (t>=n) { data[t] = x; n++;}
else
    if (data[t] != x) {
        for(int i=n; i>t; i--)
            data[i] = data[i-1];
        data[t] = x;
        n++;
    }
return *this;
}
SET SET::operator - (int x){
    int t =0;
    while (t<n && data[t] != x) t++;
    if (t<n){
        for(int i=t; i<n; i++)
            data[i] = data[i+1];
        n--;
    }
    return *this;
}
int &SET::operator [] (int i) const{
    return data[i];
}
bool SET::operator () (int x){
    int d, c, g;
    d = 0; c = n-1; 
    do {
        g = (d + c)/2;
        if (data[g] == x) return true;
        else    if (data[g]<x) d = g + 1;
                else c = g - 1; 
    } while (d<=c);
    return false;
}
const SET &SET::operator = (const SET &x){
    if (this != &x) {
        n = x.n;
        max = x.max;
        delete [] data;
        data = new int [max];
        for(int i=0; i<n; i++) data[i] = x.data[i];
    }
    return *this;
}

int main(){
    SET a;
    //a = a + 3 + 2 + 5 + 7 + 8 + 2 + 1 + 6 + 4;
    int x;
    cout<<"Nhap phan tu x can them vao tap hop. Nhap 0 de dung!"<<endl;
    while (1){  
        cout<<"x: "; cin>>x;
        if (!x) break;
        a = a + x;
    }
    cout << "Tap hop a: "<<a<<endl;
    cout<<"Nhap phan tu x bat ky can xoa: "; cin>>x;
    a = a - x;
    cout << "Tap hop a sau khi xoa "<<x<<": "<<a<<endl;
    cout<<"Nhap phan tu x bat ky can tim: "; cin>>x;
    if (a(x)) cout<<x<<" thuoc tap hop"<<endl;
    else cout<<x<<" khong thuoc tap hop."<<endl;

    return 0;
}