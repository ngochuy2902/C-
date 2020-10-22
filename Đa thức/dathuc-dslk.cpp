#include <iostream>
#include <math.h>

using namespace std;

struct Node
{
    int heso;
    int somu;
    Node *next;
};
typedef struct Node *pNode;

struct Dathuc
{
    pNode head;
    Dathuc();
    Dathuc(const Dathuc &x);
    ~Dathuc();
    void InsertHead(int hs, int sm);
    void InsertTail(int hs, int sm);
    void DelHead();
    void DelTail();
    Dathuc operator+(Dathuc &x);
    Dathuc operator-(Dathuc &x);
    const Dathuc &operator=(const Dathuc &x);
    int &operator[](int x);
    int operator()(int x);
    friend istream &operator>>(istream &is, Dathuc &x);
    friend ostream &operator<<(ostream &os, const Dathuc &x);
};

Dathuc::Dathuc()
{
    this->head = NULL;
}

Dathuc::Dathuc(const Dathuc &x)
{
    this->head=NULL;
    pNode p = x.head;
    while (p!=NULL)
    {
        this->InsertTail(p->heso, p->somu);
        p = p->next;
    }
}

Dathuc::~Dathuc()
{
    while (this->head != NULL)
    {
        DelHead();
    }
}

void Dathuc::InsertHead(int hs, int sm)
{
    pNode p = new Node;
    p->heso = hs;
    p->somu = sm;
    p->next = head;
    this->head = p;
}

void Dathuc::InsertTail(int hs, int sm)
{
    if (head == NULL) InsertHead(hs, sm);
    else
    {
        pNode p = head;
        while (p->next != NULL) p = p->next;
        pNode q = new Node;
        q->heso = hs;
        q->somu = sm;
        p->next = q;
        q->next = NULL;
    }
}

void Dathuc::DelHead()
{
    if (head != NULL)
    {
        pNode p = head;
        head = p->next;
        delete p;
    }
}

void Dathuc::DelTail()
{
    if (head == NULL) return;
    if (head->next == NULL) DelHead();
    else
    {
        pNode p = head, q=NULL;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        delete p;
    }
}

Dathuc Dathuc::operator+(Dathuc &x)
{
    Dathuc rs;
    pNode p=this->head;
    pNode q=x.head;
    int max = (p->somu > q->somu)? p->somu : q->somu;
    while (max>=0)
    {
        int t=0;
        if (max==p->somu)
        {
            t += p->heso;
            p = p->next;
        }

        if (max==q->somu)
        {
            t+=q->heso;
            q = q->next;
        }
        rs.InsertTail(t, max);
        max--;
    }
    return rs;
}

Dathuc Dathuc::operator-(Dathuc &x)
{
    Dathuc rs;
    pNode p=this->head;
    pNode q=x.head;
    int max = (p->somu > q->somu)? p->somu : q->somu;
    while (max>=0)
    {
        int t=0;
        if (max==p->somu)
        {
            t += p->heso;
            p = p->next;
        }

        if (max==q->somu)
        {
            t-=q->heso;
            q = q->next;
        }
        rs.InsertTail(t, max);
        max--;
    }
    return rs;
}

const Dathuc &Dathuc::operator=(const Dathuc &x)
{
    if (this!=&x)
    {
        while (this->head != NULL)
        {
            DelHead();
        }

        pNode p = x.head;
        while (p!=NULL)
        {
            this->InsertTail(p->heso, p->somu);
            p = p->next;
        }
    }
    return *this;
}

int &Dathuc::operator[](int i)
{
    static int x = 0;
    pNode p = this->head;
    while (p != NULL)
    {
        if (p->somu == i) return p->heso;
        p = p->next;
    }
    return x;
}

int Dathuc::operator()(int x)
{
    pNode p = this->head;
    int rs = 0;
    while (p!=NULL)
    {
        rs += p->heso *  pow(x, p->somu);
        p = p->next;
    }
    return rs;
}

istream &operator>>(istream &is, Dathuc &x)
{
    int hs, sm;
    cout<<"Nhap he so bang 0 de dung lai"<<endl;
    while (true)
    {
        cout<<"Nhap he so: "; cin>>hs;
        if (hs == 0 ) break;
        cout<<"Nhap so mu: "; cin>>sm;
        x.InsertTail(hs, sm);
        cout<<"--------------"<<endl;
    }
    return is;
}

ostream &operator<<(ostream &os, const Dathuc &x)
{
    pNode p = x.head;
    while (p!=NULL)
    {
        if (p->heso!=0)
        {
            if (p->somu == x.head->somu && p->heso < 0) os << "-";
            else if (p->somu != x.head->somu && p->heso > 0) os << " + ";
            else if (p->somu != x.head->somu && p->heso < 0) os << " - ";
            
            if (abs(p->heso)!=1 || p->somu==0) os << abs(p->heso);
            
            if (p->somu==1) os <<"x";
            else if (p->somu>0) os << "x^" << p->somu;
        }
        p = p->next;
    }
    return os;
}

int main()
{
    cout<<"Nhap da thuc A"<<endl;
    Dathuc A; cin>>A;
    cout<<endl;

    cout<<"Nhap da thuc B"<<endl;
    Dathuc B; cin>>B;
    cout<<endl;

    cout<<"A = "<<A<<endl;
    cout<<"B = "<<B<<endl;
    
    Dathuc C = A+B;
    cout<<"C = A + B = "<<C<<endl;

    Dathuc D = A-B;
    cout<<"D = A - B = "<<D<<endl;
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