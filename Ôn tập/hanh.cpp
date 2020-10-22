#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Viết 01 chương trình có khai báo các hàm để thực hiện các công việc sau:
- Nhập vào 01 ma trận A vuông cấp n (3 <=n<=10) các số nguyên.
- Xuất ma trận ra màn hình
- Tìm vecto X trong đó X[i] là vị trí phần tử lớn nhất đầu tiên có trên hàng i của ma trận A
- Xuất vecto ra màn hình
- Tính K là tổng các số nguyên tố có trong vecto X
- Sắp xếp các phần tử trong vecto X theo thứ tự tăng dần. 
- Tìm vị trí của T= (int) sqrt(K) trong vecto X (đã sắp xếp), nếu có xuất "T được tìm thấy trong X tại vị trí ...", 
nếu không có thì xuất "Không tìm thấy giá trị của T trong X". (lưu ý in giá trị của T)
- Nhập M là 01 số nguyên bất kỳ, tìm và chèn M vào vị trí phù hợp trong vecto X (X đã sắp xếp tăng). 
*/
#define max 10
//Nhập ma trận
void NhapMT(int a[][max], int n);
//Xuất ma trận
void XuatMT(int a[][max], int n);
//Xuất vecto
void XuatVT(int a[], int n);
//Tìm vecto X
void TimVT(int a[][max], int n, int x[]);
//Tìm vị trí min
int vtMax(int a[], int n);
//Tính tổng các số nguyên tố trong vecto X
int TongNgto(int a[], int n);
//Kiểm tra số nguyên tố
bool Ngto(int x);
//Sắp xếp mảng
void SapXep(int a[], int n);
//Tìm vị trí của phần tử trong mảng có thứ tự - Tìm kiếm Nhị phân
int Timkiem(int a[], int n, int x);
//Chèn phần tử vào mảng
void ChenPtu(int a[], int *n, int x);
int main(){
    int a[max][max], x[max], n, s;
    int K, T, M, vt;
    do {
        printf("Nhập cấp của ma trận:"); 
        scanf("%d",&n);
        if (n>=3 && n<=10) break;
        else printf("Dữ liệu không hợp lệ. Bạn cần nhập lại!");
    } while (1);

    // Nhập vào 01 ma trận A vuông cấp n (3 <=n<=10) các số nguyên.
    printf("Nhập ma trận vuông cấp %d:\n",n);
    NhapMT(a,n);

    // Xuất ma trận ra màn hình
    printf("Ma trận vuông vừa nhập :\n");
    XuatMT(a,n);
   
    //Tìm vecto X trong đó X[i] là vị trí phần tử lớn nhất đầu tiên có trên hàng i của ma trận A
    TimVT(a,n,x);

    // Xuất vecto ra màn hình
    printf("Vecto x gồm các phần tử là vị trí lớn nhất đầu tiên trên các hàng của ma trận A:\n");
    XuatVT(x,n);

    //Tính K là tổng các số nguyên tố có trong vecto X
    K = TongNgto(x,n);
    printf("Tổng các số nguyên tố trong vecto X: %d\n", K);

    //Sắp xếp các phần tử trong vecto X theo thứ tự tăng dần. 
    SapXep(x,n);
    printf("Vecto x sau khi sắp xếp:");
    XuatVT(x,n);

    /*Tìm vị trí của T= (int) sqrt(K) trong vecto X (đã sắp xếp), 
    nếu có xuất "T được tìm thấy trong X tại vị trí ...", 
    nếu không có thì xuất "Không tìm thấy giá trị của T trong X". (lưu ý in giá trị của T) */
    s = (int)sqrt(K);
    vt = Timkiem(x,n,s);
    if (vt>=0) printf("%d được tìm thấy trong X tại vị trí %d.\n",s, vt);
    else printf("Không tìm thấy giá trị của %d trong X.\n",s);

    //Nhập M là 01 số nguyên bất kỳ, tìm và chèn M vào vị trí phù hợp trong vecto X (X đã sắp xếp tăng). 
    printf("Nhập 01 số nguyên M bất kỳ:"); scanf("%d",&M);
    ChenPtu(x,&n,M);
    printf("Vecto X sau khi chèn %d:",M);
    XuatVT(x,n);
    //getch();
    return 0;
}
//Nhập ma trận
void NhapMT(int a[][max], int n){
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            printf("Nhập phần tử hàng %d cột %d: ", i, j); scanf("%d",&a[i][j]);
        }
}

//Xuất ma trận
void XuatMT(int a[][max], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++) 
            printf("%5d", a[i][j]);
        printf("\n");
    }
}

//Xuất vecto
void XuatVT(int a[], int n){
    int i, j;
    for(i = 0; i < n; i++) printf("%5d", a[i]);
    printf("\n");
}

//Tìm vecto X
void TimVT(int a[][max], int n, int x[]){
    int i;
    for(i = 0; i < n; i++){
        x[i] = vtMax(a[i],n);
    }
}

//Tìm vị trí max đầu tiên
int vtMax(int a[], int n){
    int i, vtm = 0;
    for(i = 1; i < n; i++)
        if (a[vtm]<a[i]) vtm = i;
    return vtm;
}

//Tính tổng các số nguyên tố trong vecto X
int TongNgto(int a[], int n){
    int i, S = 0;
    for(i = 0; i < n; i++)
        if (Ngto(a[i])) S += a[i];
    return S;
}

//Kiểm tra số nguyên tố
bool Ngto(int x){
    int i;
    for(i = 2; i < sqrt(x); i++) 
        if (x%i==0) return false;
    return true;
}

//Sắp xếp mảng
void SapXep(int a[], int n){
    int i, j;
    for(i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

//Tìm vị trí của phần tử trong mảng có thứ tự - Tìm kiếm Nhị phân
int Timkiem(int a[], int n, int x){
    int d, c, g; // ví trí đầu, vị trí cuối, và vị trí giữa 
    d = 0; c= n - 1; 
    do {
        g = (d + c)/2;
        if (a[g] == x) return g;
        else
            if (a[g] < x) d = g + 1;
            else c = g - 1;
    } while (d<=c);
    return -1;
}

//Chèn phần tử vào mảng
void ChenPtu(int a[], int *n, int x){
    int i, j;
    for(i = 0;i < *n; i++)
        if (a[i] > x) break;
    for(j = *n; j > i; j--) a[j] = a[j - 1];
    a[j] = x;
    (*n)++;
}