#include <iostream>
#include <math.h>

using namespace std;

struct Dathuc
{
    int bac;
    int *heso;
    Dathuc(int bac = 2);
    Dathuc(const Dathuc &x);
    ~Dathuc();
    Dathuc operator+(Dathuc &x);
    Dathuc operator-(Dathuc &x);
    const Dathuc &operator=(const Dathuc &x);
    int operator[](int x);
    int operator()(int x);
    friend istream &operator>>(istream &is, Dathuc &x);
    friend ostream &operator<<(ostream &os, const Dathuc &x);
};

Dathuc::Dathuc(int bac)
{
    this->bac = bac;
    this->heso = new int[bac+1]; 
    for (int i=0; i<=bac; i++)
    {
        this->heso[i] = 0;
    }
}

Dathuc::Dathuc(const Dathuc &x)
{
    this->bac = x.bac;
    this->heso = new int[this->bac + 1];
    for (int i=this->bac; i>=0; i--)
    {
        this->heso[i] = x.heso[i];
    }
}

Dathuc::~Dathuc()
{
    delete[] this->heso;
}

const Dathuc &Dathuc::operator=(const Dathuc &x)
{
    if (this!=&x)
    {
        this->bac = x.bac;
        delete[] this->heso;
        this->heso = new int[this->bac + 1];
        for (int i=this->bac; i>=0; i--)
        {
            this->heso[i] = x.heso[i];
        }
    }
    return *this;
}

Dathuc Dathuc::operator+(Dathuc &x)
{
    Dathuc result(this->bac>x.bac? this->bac : x.bac);
    for (int i=0; i<=result.bac; i++)
    {
        if (i<=this->bac) result.heso[i] += this->heso[i];
        if (i<=x.bac) result.heso[i] += x.heso[i];
    }
    return result;
}

Dathuc Dathuc::operator-(Dathuc &x)
{
    Dathuc result(this->bac>x.bac? this->bac : x.bac);
    for (int i=0; i<=result.bac; i++)
    {
        if (i<=this->bac) result.heso[i] += this->heso[i];
        if (i<=x.bac) result.heso[i] -= x.heso[i];
    }
    return result;
}

int Dathuc::operator[](int x)
{
    if (x<=this->bac) return this->heso[x];
    return 0;
}

int Dathuc::operator()(int x)
{
    int rs=0;
    for (int i=this->bac; i>=0; i--)
    {
        rs += this->heso[i] * pow(x,i);
    }
    return rs;
}

istream &operator>>(istream &is, Dathuc &x)
{
    for (int i=x.bac; i>=0; i--)
    {
        cout<<"He so tai x^"<<i<<": "; is>>x.heso[i];
    }
    return is;
}

ostream &operator<<(ostream &os, Dathuc &x)
{
    for (int i=x.bac; i>=0; i--)
    {
        if (x.heso[i]!=0)
        {
            if (i==x.bac && x.heso[i] < 0) os<<"-";
            else if (i!=x.bac && x.heso[i]>0) os<<" + ";
            else if (i!=x.bac && x.heso[i]<0) os<<" - ";

            if (abs(x.heso[i])!=1 || i==0) os<<abs(x.heso[i]);
            
            if (i == 1) os<<"x";
            else if (i>0) os<<"x^"<<i;
        } 
    }
    os<<endl;
    return os;
}

int main()
{
    int n,m;
    cout<<"Nhap da thuc A"<<endl;
    cout<<"Nhap bac: "; cin>>n;
    Dathuc A(n); cin>>A;
    cout<<endl;

    cout<<"Nhap da thuc B"<<endl;
    cout<<"Nhap bac: "; cin>>m;
    Dathuc B(m); cin>>B;
    cout<<endl;

    cout<<"A = "<<A;
    cout<<"B = "<<B;
    
    Dathuc C = A+B;
    cout<<"C = A + B = "<<C;

    Dathuc D = A-B;
    cout<<"D = A - B = "<<D;
    cout<<endl;

    int y;
    cout<<"Tim he so tai x^y : y = "; cin>>y;
    cout<<"A["<<y<<"] = "<<A[y]<<" : "<<A[y]<<"x^"<<y<<endl;
    cout<<"B["<<y<<"] = "<<B[y]<<" : "<<B[y]<<"x^"<<y<<endl;
    cout<<endl;

    int x;
    cout<<"Tinh gia tri da thuc tai x = "; cin>>x;
    cout<<"A("<<x<<") = "<<A(x)<<endl;
    cout<<"B("<<x<<") = "<<B(x)<<endl;

    return 0;
}