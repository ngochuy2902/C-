#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"N = "; cin>>n;
    int *p; //tạo biến con trỏ p
    p = new int; //khởi tạo địa chỉ vùng nhớ cho con trỏ p
    p = &n; //gán địa chỉ của p bằng địa chỉ của n
    cout<<"dia chi con tro p = "<<p<<endl;
    cout<<"gia tri con tro p = "<<*p<<endl; //1000

    int *q = &n; //tạo biến con trỏ q, đồng thời gán địa chỉ của con trỏ q bằng địa chỉ của n
    cout<<"dia chi con tro q = "<<q<<endl;
    cout<<"gia tri con tro q = "<<*q<<endl; //1000

    int* r = p;
    cout<<"dia chi con tro r = "<<r<<endl;
    cout<<"gia tri con tro r = "<<*r<<endl;

    *q = 1100; //thay đổi giá trị của con trỏ q = 100 => giá trị của biến n và giá trị của con trỏ p đều thay đổi và = 100
    cout<<"gia tri cua n = "<<n<<endl; //100
    cout<<"gia tri con tro p = "<<*p<<endl; //100
    cout<<"gia tri con tro q = "<<*q<<endl; //100
    cout<<"gia tri con tro r = "<<*r<<endl; //100
}