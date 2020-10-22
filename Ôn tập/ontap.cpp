#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//1. Ham nhap ma tran A cap n
void nhap(int a[8][8], int n)
{
    cout << "Nhap ma tran A: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i << "," << j << "] = ";
            cin >> a[i][j];
        }
    }
}

//2. Ham xuat ma tran A
void xuat(int a[8][8], int n)
{
    cout << "A = " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//3. Ham tim vector X
vector<int> timX(int a[8][8], int n)
{
    int k = 0;
    vector<int> rs;
    for (int i = 0; i < n; i++)
    {
        int max = a[i][0];
        int pos = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > max) {
                max = a[i][j];
                pos = j;
            }
                
        }
        rs.push_back(pos);
    }
    return rs;
}

//4.Ham xuat vector X
void xuatX(vector<int> x)
{
    cout << "X = ";
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

//5. Tinh K la tong cac so nguyen to trong vector X
int timK(vector<int> x)
{
    int rs = 0;
    for (int i = 0; i < x.size(); i++)
    {
        bool check = true;
        for (int j = 2; j <= sqrt(x[i]); j++)
        {
            if (x[i] % j == 0)
                check = false;
        }

        if (check)
            rs += x[i];
    }

    return rs;
}

//6. Sap xep X theo thu tu tang dan
vector<int> sortX(vector<int> x)
{
    vector<int> t(x);
    for (int i = 0; i < x.size() - 1; i++)
    {
        for (int j = i + 1; j < x.size(); j++)
        {
            if (x[i] > x[j])
            {
                int temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
    return t;
}

//7. Tim vi tri cua T=(int)sqrt(K) trong vector X
void timVitriT(vector<int> x, int t)
{
    vector<int> rs;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == t)
            rs.push_back(i);
    }
    if (rs.size() == 0)
    {
        cout << "Khong tim thay gia tri T trong X" << endl;
    }
    else
    {
        cout << "T duoc tim thay trong X tai vi tri: ";
        for (int i = 0; i < rs.size(); i++)
        {
            cout << rs[i] << " ";
        }
        cout << endl;
    }
}

//8. Chen M vao vi tri thich hop trong vector X
vector<int> chenM(vector<int> x, int m)
{
    vector<int> rs;
    int index = -1;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] >= m)
        {
            index = i;
            break;
        }
        rs.push_back(x[i]);
    }
    rs.push_back(m);

    if (index > -1)
    {
        for (int i = index; i < x.size(); i++)
        {
            rs.push_back(x[i]);
        }
    }

    return rs;
}

int main()
{
    int a[8][8];
    vector<int> x;

    int n, k, m;

    while (true)
    {
        cout << "Nhap n = ";
        cin >> n;
        if (n >= 3 && n <= 10)
            break;
    }

    nhap(a, n);
    xuat(a, n);

    x = timX(a, n);
    xuatX(x);

    cout << "K la tong cac so nguyen so co trong vector X" << endl;
    k = timK(x);
    cout << "K = " << k << endl
         << endl;

    x = sortX(x);
    cout << "X da sap xep: " << endl;
    xuatX(x);
    cout << endl;

    int t = (int)sqrt(k);
    cout << "T = " << t << endl;
    timVitriT(x, t);
    cout << endl;

    cout << "Nhap M = ";
    cin >> m;
    x = chenM(x, m);
    cout << "X da chen M: " << endl;
    xuatX(x);

    return 0;
}