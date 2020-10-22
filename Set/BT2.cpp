#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef struct Node *pNode;

struct Set
{
    int max;
    int n;
    pNode head;
    Set(int max = 10);
    Set(const Set &x);
    ~Set();
    void InsertHead(int x);
    void InsertTail(int x);
    void InsertAfter(pNode &q, int x);
    void DelHead();
    void DelTail();
    void DelAfter(pNode &q);
    Set operator+(int x);
    Set operator-(int x);
    Set operator+(Set &x);
    Set operator-(Set &x);
    Set operator*(Set &x);
    const Set &operator=(const Set &x);
    int &operator[](int i) const;
    bool operator()(int x);
    friend ostream &operator<<(ostream &os, const Set &x);
};

Set::Set(int max)
{
    this->max = max;
    this->n = 0;
    this->head = NULL;
}

Set::Set(const Set &x)
{
    this->max = x.max;
    this->n = x.n;
    this->head = NULL;
    pNode p = x.head;
    while (p != NULL)
    {
        this->InsertTail(p->data);
        p = p->next;
    }
}

Set::~Set()
{
    while (this->head != NULL)
    {
        DelHead();
    }
}

void Set::InsertHead(int x)
{
    pNode p = new Node;
    p->data = x;
    p->next = head;
    this->head = p;
}

void Set::InsertTail(int x)
{
    if (head == NULL) InsertHead(x);
    else
    {
        pNode p = head;
        while (p->next != NULL) p = p->next;
        pNode q = new Node;
        q->data = x;
        p->next = q;
        q->next = NULL;
    }
}

void Set::InsertAfter(pNode &q, int x)
{
    pNode p = new Node;
    p->data = x;
    p->next = q->next;
    q->next = p;
}

void Set::DelHead()
{
    if (head != NULL)
    {
        pNode p = head;
        head = p->next;
        delete p;
    }
}

void Set::DelTail()
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

void Set::DelAfter(pNode &q)
{
    pNode p = q->next;
    q->next = p->next;
    delete p;
}

Set Set::operator+(int x)
{
    if (this->n + 1 <= this->max && !(*this)(x))
    {
        if (this->n == 0)
        {
            this->InsertHead(x);
            this->n++;
        }
        else
        {
            pNode p = head, q = NULL;
            while (p != NULL && p->data < x)
            {
                q = p;
                p = p->next;
            }
            if (p == head)
            {
                this->InsertHead(x);
                this->n++;
            }
            else
            {
                this->InsertAfter(q, x);
                this->n++;
            }
        }
    }
    return *this;
}

Set Set::operator-(int x)
{
    Set temp(this->max);
    pNode p = this->head;
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

Set Set::operator+(Set &x)
{
    Set result(this->max + x.max);
    pNode p = this->head;
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

Set Set::operator-(Set &x)
{
    Set result(this->max);
    result = *this;
    pNode p = x.head;
    while (p != NULL)
    {
        result = result - p->data;
        p = p->next;
    }
    return result;
}

Set Set::operator*(Set &x)
{
    Set result(this->max);
    pNode p = this->head;
    while (p != NULL)
    {
        pNode q = x.head;
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

const Set &Set::operator=(const Set &x)
{
    if (this != &x)
    {
        this->max = x.max;
        this->n = x.n;
        while (this->head != NULL)
        {
            DelHead();
        }
        pNode q = x.head;
        while (q != NULL)
        {
            InsertTail(q->data);
            q = q->next;
        }
    }
    return *this;
}

int &Set::operator[](int i) const
{   
    static int x = 0;
    pNode p = head;
    int index = 0;
    while (p != NULL)
    {
        if (index == i) return p->data;
        index++;
        p = p->next;
    }
    return x;
}

bool Set::operator()(int x)
{
    pNode p = head;
    while (p != NULL)
    {
        if (p->data == x) return true;
        p = p->next;
    }
    return false;
}

ostream &operator<<(ostream &os, const Set &x)
{
    if (x.n == 0)
        os << "{}";
    else
    {
        os << "{";
        pNode p = x.head;
        while (p->next != NULL)
        {
            os << p->data << ", ";
            p = p->next;
        }
        os << p->data;
        os << "}";
    }
    return os;
}

int main()
{
    int max, x;
    cout << "Nhap gioi han tap hop: "; cin >> max;
    Set A(max), B(max);
    cout << "Nhap tap hop A: " << endl;
    cout << "Nhap phan tu x can them vao tap hop A. Nhap 0 de dung!" << endl;
    while (true)
    {
        cout << "x: "; cin >> x;
        if (!x) break;
        A = A + x;
        cout << "A = " << A << endl;
    }
    cout << endl;

    cout << "Nhap tap hop B: " << endl;
    cout << "Nhap phan tu x can them vao tap hop B. Nhap 0 de dung!" << endl;
    while (true)
    {
        cout << "x: "; cin >> x;
        if (!x) break;
        B = B + x;
        cout << "B = " << B << endl;
    }
    cout << endl;

    cout << "Nhap phan tu x can xoa khoi tap hop A. Nhap 0 de dung!" << endl;
    while (true)
    {
        cout << "x: "; cin >> x;
        if (!x) break;
        A = A - x;
        cout << "A = " << A << endl;
    }
    cout << "Nhap phan tu x can xoa khoi tap hop B. Nhap 0 de dung!" << endl;
    while (true)
    {
        cout << "x: "; cin >> x;
        if (!x) break;
        B = B - x;
        cout << "B = " << B << endl;
    }
    cout << endl;

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    Set C = A * B;
    Set D = A + B;
    Set E = A - B;
    cout << "A giao B = A * B = " << C << endl;
    cout << "A hop B = A + B = " << D << endl;
    cout << "A tru B = A - B = " << E << endl;
    cout << endl;

    cout << "Tim gia tri cua phan tu tai vi tri i" << endl;
    cout << "Nhap vi tri: "; cin >> x;
    cout << "A[" << x << "] = " << A[x] << endl;
    cout << "B[" << x << "] = " << B[x] << endl;

    cout << "Kiem tra phan tu co thuoc tap hop" << endl;
    cout << "Nhap phan tu: "; cin >> x;
    if (A(x))cout << x << " co trong tap A" << endl;
    else cout << x << " khong co trong tap A" << endl;
    if (B(x)) cout << x << " co trong tap B" << endl;
    else cout << x << " khong co trong tap B" << endl;

    return 0;
}