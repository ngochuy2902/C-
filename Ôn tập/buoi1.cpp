#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//1. Ham nhap ma tran A cap n
void nhap(int a[10][10], int n)
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
void xuat(int a[10][10], int n)
{
    cout << "A = " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

//3. Ham tim vector X la vi tri phan tu lon nhat dau tien co tren hang i cua ma tran A
void timX(int a[10][10], int n, int x[10])
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int max = a[i][0];
        int pos = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                pos = j;
            }
        }
        x[index++] = pos;
    }
}

//4.Ham xuat vector X
void xuatX(int x[10], int n)
{
    cout << "X = ";
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl
         << endl;
}

//5. Tinh K la tong cac so nguyen to trong vector X
int timK(int x[10], int n)
{
    int rs = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] < 2)
            continue;
        bool check = true;
        for (int j = 2; j <= sqrt(x[i]); j++)
        {
            if (x[i] % j == 0)
            {
                check = false;
                break;
            }
        }
        if (check)
            rs += x[i];
    }
    return rs;
}

//6. Sap xep X theo thu tu tang dan
void sapxepX(int x[10], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] > x[j])
            {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
}

//7. Tim vi tri cua T=(int)sqrt(K) trong vector X
void timVitriT(int x[10], int n, int t)
{
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == t)
        {
            if (check == false)
            {
                cout << "T duoc tim thay trong X tai vi tri: ";
                check = true;
            }
            cout << i << " ";
        }
    }
    if (check == false)
        cout << "T khong duoc tim thay trong X" << endl;
    cout << endl;
}

//8. Chen M vao vi tri thich hop trong vector X
void chenM(int x[10], int n, int m)
{
    int rs[11];
    int pos = -1;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (x[i] >= m)
        {
            pos = i;
            break;
        }
        rs[j++] = x[i];
    }
    rs[j++] = m;
    if (pos > -1)
    {
        for (int i = pos; i < n; i++)
        {
            rs[j++] = x[i];
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        x[i] = rs[i];
    }
}

int main()
{
    int a[10][10];
    int x[10];

    int n, k, t, m;

    while (true)
    {
        cout << "Nhap n = ";
        cin >> n;
        if (n >= 3 && n <= 10)
            break;
    }

    nhap(a, n);
    xuat(a, n);

    timX(a, n, x);
    cout << "Vector X la vi tri phan tu lon nhat dau tien co tren hang i cua ma tran A" << endl;
    xuatX(x, n);

    k = timK(x, n);
    cout << "K la tong cac so nguyen to trong vector X" << endl;
    cout << "K = " << k << endl
         << endl;

    sapxepX(x, n);
    cout << "X da sap xep theo thu tu tang dan" << endl;
    xuatX(x, n);

    t = (int)(sqrt)(k);
    cout << "T = (int)sqrt(K) = " << t << endl;
    timVitriT(x, n, t);
    cout << endl;

    cout << "Nhap M = ";
    cin >> m;
    chenM(x, n, m);
    cout << "X da chen M: " << endl;
    xuatX(x, n + 1);

    return 0;
}