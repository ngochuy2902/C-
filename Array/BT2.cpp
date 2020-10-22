/*Viết chương trình cho phép thực hiện các thao tác trên kiểu mảng:
- Hàm nhập, xuất mảng.
- Lấy kích thước mảng.
- Lấy phần tử tại vị trí nào đó.
- Sắp xếp tăng, giảm (theo các phương pháp sắp xếp: Chọn trực tiếp, Chèn trực tiếp, Nổi bọt BubbleSort, QuickSort, HeapSort, ShellSort, RadixSort)
- Tìm phần tử nào đó trong mảng (tuần tự, nhị phân, nội suy)*/

#include <iostream>
#include <time.h>

using namespace std;

void Input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "] = ";
        cin >> a[i];
    }
}

void Display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int ValueOf(int a[], int index)
{
    return a[index];
}

bool ascending(int left, int right)
{
    return left > right;
}

bool ascending()
{
    return true;
}

bool descending(int left, int right)
{
    return left < right;
}

bool descending()
{
    return false;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int a[], int n, bool compare(int, int))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compare(a[i], a[j]))
            {
                swap(a[i], a[j]);
            }
        }
    }
}

void BubbleSort(int a[], int n, bool compare(int, int))
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (compare(a[j - 1], a[j]))
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
}

void InsertionSort(int a[], int n, bool compare(int, int))
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (compare(a[j - 1], a[j]))
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
}

void ShellSort(int a[], int n, bool compare(int, int))
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && compare(a[j - gap], temp); j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

void QuickSortFunc(int a[], int left, int right, bool compare(int, int))
{
    srand(time(NULL));
    int key = a[left + rand() % (right - left + 1)];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (compare(key, a[i]))
            i++;
        while (compare(a[j], key))
            j--;
        if (i <= j)
        {
            if (i < j)
            {
                swap(a[i], a[j]);
            }
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSortFunc(a, left, j, compare);
    if (i < right)
        QuickSortFunc(a, i, right, compare);
}

void QuickSort(int a[], int n, bool compare(int, int))
{
    QuickSortFunc(a, 0, n - 1, compare);
}

void Heapify(int a[], int n, int i, bool compare(int, int))
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && compare(a[left], a[largest]))
        largest = left;
    if (right < n && compare(a[right], a[largest]))
        largest = right;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        Heapify(a, n, largest, compare);
    }
}

void HeapSort(int a[], int n, bool compare(int, int))
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i, compare);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        Heapify(a, i, 0, compare);
    }
}

void RadixSort(int a[], int n, bool type())
{
    int b[n], m = a[0], exp = 1;

    for (int i = 0; i < n; i++)
        if (a[i] > m)
            m = a[i];

    while (m / exp > 0)
    {
        int bucket[10] = {0};
        for (int i = 0; i < n; i++)
            if (type())
                bucket[a[i] / exp % 10]++;
            else
                bucket[9 - a[i] / exp % 10]++;
        for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; i--)
            if (type())
                b[--bucket[a[i] / exp % 10]] = a[i];
            else
                b[--bucket[9 - a[i] / exp % 10]] = a[i];
        for (int i = 0; i < n; i++)
            a[i] = b[i];
        exp *= 10;
    }
}

bool SequentialSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return true;
    }
    return false;
}

bool BinarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int k = (left + right) / 2;
        if (a[k] == x)
            return true;
        if (a[k] > x)
            right = k - 1;
        else
            left = k + 1;
    }
    return false;
}

bool InterPolationSearch(int a[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    while (left <= right && x >= a[left] && x <= a[right])
    {
        int val1 = (x - a[left]) / (a[right] - a[left]);
        int val2 = right - left;
        int pos = left + val1 * val2;
        if (a[pos] == x)
            return true;
        if (a[pos] < x)
            left = pos + 1;
        else
            right = pos - 1;
    }
    return false;
}

int main()
{
    // int n;
    // cout<<"Size of array = ";cin>>n;
    // int a[n];
    // Input(a,n);

    int a[] = {2, 3, 5, 1, 4};
    
    int n = sizeof(a)/sizeof(int);

    cout<<"Size of array = "<<n<<endl;

    cout<<"Original array: "; Display(a, n);

    int index;
    cout<<"Value of index = "; cin>>index;
    cout<<"ValueOf(A["<<index<<"]) = "<<ValueOf(a,index)<<endl;

    cout<<"Sorted array: "<<endl;
    cout<<"SelectionSort ascending: "; SelectionSort(a,n,ascending); Display(a,n);
    cout<<"SelectionSort descending: "; SelectionSort(a,n,descending); Display(a,n);
    cout<<endl;
    
    cout<<"BubbleSort ascending: "; BubbleSort(a,n,ascending); Display(a,n);
    cout<<"BubbleSort descending: "; BubbleSort(a,n,descending); Display(a,n);
    cout<<endl;

    cout<<"InsertionSort ascending: "; InsertionSort(a,n,ascending); Display(a,n);
    cout<<"InsertionSort descending: "; InsertionSort(a,n,descending); Display(a,n);
    cout<<endl;

    cout<<"ShellSort ascending: "; ShellSort(a,n,ascending); Display(a,n);
    cout<<"ShellSort descending: "; ShellSort(a,n,descending); Display(a,n);
    cout<<endl;
    
    cout<<"QuickSort ascending: "; QuickSort(a,n,ascending); Display(a,n);
    cout<<"QuickSort descending: "; QuickSort(a,n,descending); Display(a,n);
    cout<<endl;

    cout<<"HeapSort ascending: "; HeapSort(a,n,ascending); Display(a,n);
    cout<<"HeapSort descending: "; HeapSort(a,n,descending); Display(a,n);
    cout<<endl;

    cout<<"RadixSort ascending: "; RadixSort(a,n,ascending); Display(a,n);
    cout<<"RadixSort descending: "; RadixSort(a,n,descending); Display(a,n);
    cout<<endl;

    QuickSort(a,n,ascending);

    int x;
    cout<<"Check exist of x = "; cin>>x;
    cout<<"SequentialSearch: "<<SequentialSearch(a,n,x)<<endl;
    cout<<"BinarySearch: "<<BinarySearch(a,n,x)<<endl;
    cout<<"InterPolationSearch: "<<InterPolationSearch(a,n,x);
    return 0;
}