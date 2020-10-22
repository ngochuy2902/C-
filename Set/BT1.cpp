#include <iostream>
using namespace std;

struct Set
{
    int max;
    int n;
    int *data;
    Set(int max = 10);
    Set(const Set &x);
    ~Set();
    Set operator+(int x);
    Set operator-(int x);
    Set operator+(Set &x);
    Set operator-(Set &x);
    Set operator*(Set &x);
    const Set &operator=(const Set &X);
    int operator[](int i) const;
    bool operator()(int x);
    friend ostream &operator<<(ostream &os, const Set &X);
};

Set::Set(int max)
{
    this->max = max;
    this->n = 0;
    this->data = new int[max];
}

Set::Set(const Set &x)
{
    this->max = x.max;
    this->data = new int[max];
    this->n = x.n;
    for (int i = 0; i < this->n; i++) this->data[i] = x.data[i];
}

Set::~Set()
{
    delete[] this->data;
}

Set Set::operator+(int x)
{
    if (this->n + 1 <= this->max)
    {
        int i = 0;
        while (i < this->n && this->data[i] < x) i++;
        if (i >= this->n)
        {
            this->data[i] = x;
            this->n++;
        }
        else if (this->data[i] != x)
        {
            for (int j = n; j > i; j--)
            {
                this->data[j] = this->data[j - 1];
            }
            this->data[i] = x;
            this->n++;
        }
    }
    return *this;
}

Set Set::operator-(int x)
{
    Set t(this->max);
    for (int i = 0; i < this->n; i++)
    {
        if (this->data[i] != x)
        {
            t = t + this->data[i];
        }
    }
    return t;
}

Set Set::operator+(Set &x)
{
    Set t(max + x.max);
    for (int i = 0; i < this->n; i++)
    {
        t = t + data[i];
    }
    for (int i = 0; i < x.n; i++)
    {
        t = t + x.data[i];
    }
    return t;
}

Set Set::operator-(Set &X)
{
    Set t(this->max);
    t = *this;
    for (int i = 0; i < this->n; i++)
    {
        t = t - X.data[i];
    }
    return t;
}

Set Set::operator*(Set &x)
{
    Set t(this->max);
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < x.n; j++)
        {
            if (this->data[i] == x.data[j])
            {
                t = t + this->data[i];
                break;
            }
        }
    }
    return t;
}

const Set &Set::operator=(const Set &x)
{
    if (this != &x)
    {
        this->max = x.max;
        this->n = x.n;
        delete[] this->data;
        this->data = new int[this->max];
        for (int i = 0; i < x.n; i++)
        {
            this->data[i] = x.data[i];
        }
    }
    return *this;
}

int Set::operator[](int i) const
{
    if (i<this->n) return this->data[i];
    return 0;
}

bool Set::operator()(int x)
{
    for (int i = 0; i < this->n; i++)
    {
        if (this->data[i] == x) return true;
    }
    return false;
}

ostream &operator<<(ostream &os, const Set &x)
{
    if (x.n == 0) os << "{}";
    else
    {
        os << "{";
        for (int i = 0; i < x.n - 1; i++)
        {
            os << x.data[i] << ", ";
        }
        os << x.data[x.n - 1];
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