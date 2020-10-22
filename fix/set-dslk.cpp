#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    struct node *next;
};

typedef struct node *Node;

struct SET
{
    int n, max;
    int i, *data;
    Node head;
    SET(int m = 10);
    SET(const SET &x);
    ~SET();
    void AddHead(int x);
    void AddTail(int x);
    void AddAt(Node &q, int x);
    void DelHead();
    void DelTail();
    void DelAt(Node &q);
    SET operator+(int x);
    SET operator-(int x);
    SET operator+(SET &x);
    SET operator-(SET &x);
    SET operator*(SET &x);
    const SET &operator=(const SET &X);
    int operator[](int i) const;
    bool operator()(int x);
};

SET::SET(int m)
{
    this->max = m;
    this->n = 0;
    this->head = NULL;
}

SET::SET(const SET &x)
{
    max = x.max;
    n = x.n;
    head = NULL;
    Node p = x.head;
    while (p != NULL)
    {
        //AddHead(p->data); //chỗ em làm sai
        AddTail(p->data);
        p = p->next;
    }
}

SET::~SET()
{
    while (this->head != NULL)
    {
        DelHead();
    }
}

ostream& operator <<(ostream &os,const SET &x)
{
    if (x.n == 0) os<<"{}";
    else
    {
        os<<"{";
        Node p = x.head;
        while (p->next != NULL)
        {
            os<<p->data<<", ";
            p = p->next;
        }
        os<<p->data;
        os<<"}"<<endl;
    }
    return os;
}

void SET::AddHead(int x)
{
    Node p = new node;
    p->data = x;
    p->next = head;
    head = p;
}

void SET::AddTail(int x)
{
    if (head == NULL) AddHead(x);
    else
    {
        Node p = head;
        while (p->next != NULL) p = p->next;
        Node q = new node;
        q->data = x;
        p->next = q;
        q->next = NULL;
    }
}

void SET::AddAt(Node &q, int x)
{
    Node p = new node;
    p->data = x;
    p->next = q->next;
    q->next = p;
}

void SET::DelHead()
{
    if (head != NULL)
    {
        Node p = head;
        head = p->next;
        delete p;
    }
}

void SET::DelTail()
{
    if (head == NULL) return;
    if (head->next == NULL) DelHead();
    else
    {
        Node p = head, q=NULL;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        delete p;
    }
}

void SET::DelAt(Node &q)
{
    Node p = q->next;
    q->next = p->next;
    delete p;
}

SET SET::operator+(int x)
{
    if (n + 1 <=max && !(*this)(x))
    {
        if (n == 0)
        {
            AddHead(x);
            n++;
        }
        else
        {
            Node p = head, q = NULL;
            while (p != NULL && p->data < x)
            {
                q = p;
                p = p->next;
            }
            if (p == head)
            {
                AddHead(x);
                n++;
            }
            else
            {
                AddAt(q, x);
                n++;
            }
        }
    }
    return *this;
}

SET SET::operator-(int x)
{
    SET temp(max);
    Node p = head;
    while (p != NULL)
    {
        if (p->data != x)
        {
            temp = temp + p->data;
        }
        p = p->next;
    }
    return temp;
}
SET SET::operator+(SET &x)
{
    SET result(max + x.max);
    Node p = head;
    while (p != NULL)
    {
        result = result + p->data;
        p = p->next;
    }
    p = x.head;
    while (p != NULL)
    {
        result = result + p->data;
        p = p->next;
    }
    return result;
}

SET SET::operator-(SET &x)
{
    SET result(max);
    result = *this;
    Node p = x.head;
    while (p != NULL)
    {
        result = result - p->data;
        p = p->next;
    }
    return result;
}

SET SET::operator*(SET &x)
{
    SET result(max);
    Node p = head;
    while (p != NULL)
    {
        Node q = x.head;
        while (q != NULL)
        {
            if (p->data == q->data)
            {
                result = result + p->data;
                break;
            }
            q = q->next;
        }
        p = p->next;
    }
    return result;
}

const SET &SET::operator=(const SET &x)
{
    if (this != &x)
    {
        max = x.max;
        n = x.n;
        while (this->head != NULL)
        {
            DelHead();
        }
        Node q = x.head;
        while (q != NULL)
        {
            AddTail(q->data);
            q = q->next;
        }
    }
    return *this;
}

int SET::operator[](int i) const
{
    Node p = head;
    int index = 0;
    while (p != NULL)
    {
        if (index == i) return p->data;
        index++;
        p = p->next;
    }
    return 0;
}

bool SET::operator()(int x)
{
    Node p = head;
    while (p != NULL)
    {
        if (p->data == x) return true;
        p = p->next;
    }
    return false;
}


int main()
{
    int max, x;
    cout<<"Nhap gioi han tap hop: "; cin>>max;
    SET a(max), b(max);
   
    cout << "Nhap tap hop a: " << endl;
    cout << "Nhap phan tu x can them vao tap hop a. Nhap 0 de dung!" << endl;
    while (true)
    {
        cout << "x: "; cin >> x;
        if (!x) break;
        a = a + x;
        cout << "a = " << a << endl;
    }
    cout << endl;

    cout << "Nhap tap hop b: " << endl;
    cout << "Nhap phan tu x can them vao tap hop b. Nhap 0 de dung!" << endl;
    while (true)
    {
        cout << "x: "; cin >> x;
        if (!x) break;
        b = b + x;
        cout << "b = " << b << endl;
    }
    cout << endl;

    cout << "Nhap phan tu x can xoa khoi tap hop b. Nhap 0 de dung!" << endl;
    while (true)
    {
        cout << "x: "; cin >> x;
        if (!x) break;
        a = a - x;
        cout << "a = " << a << endl;
    }
    cout << "Nhap phan tu x can xoa khoi tap hop b. Nhap 0 de dung!" << endl;
    while (true)
    {
        cout << "x: "; cin >> x;
        if (!x) break;
        b = b - x;
        cout << "b = " << b << endl;
    }
    cout << endl;

    cout << "Tap hop a:" << a << endl;
    cout << "Tap hop b:" << b << endl;
    cout << "a giao b = a * b = " << a * b;
    cout << "a hop b = a + b =  " << a + b;
    cout << "a tru b = a - b =  " << a - b;
    cout << "a = " << a;
    cout << "b = " << b;
    cout << endl;

    cout << "Tim gia tri cua phan tu tai vi tri i" << endl;
    cout << "Nhap vi tri: "; cin >> x;
    cout << "a[" << x << "] = " << a[x] << endl;
    cout << "B[" << x << "] = " << b[x] << endl;
    cout << "Kiem tra phan tu co thuoc tap hop" << endl;
    cout << "Nhap phan tu: ";
    cin >> x;
    if (a(x))cout << x << " co trong tap a" << endl;
    else cout << x << " khong co trong tap a" << endl;
    if (b(x)) cout << x << " co trong tap b" << endl;
    else cout << x << " khong co trong tap b" << endl;

    return 0;
}