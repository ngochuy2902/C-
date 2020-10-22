#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    srand(time(0));
    int a[10][10], i, j;
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 10; ++j)
        {
            a[i][j] = rand() % 100 + 1;
        }
    }
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 10; ++j)
            cout << a[i][j] << " ";
        cout << '\n';
    }
    return 0;
}