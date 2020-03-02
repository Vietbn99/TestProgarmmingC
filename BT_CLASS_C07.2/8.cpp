/*
    tim vi tri phan tu co gia tri x xuat hien cuoi cung trong mang.
*/

#include <stdio.h>
// ham nhap
void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("pt[%d] = ", i + 1);
        scanf("%d", &a[i]);
    }
}
// ham xuat
void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    printf("\n");
}
// ham tim vi tri
void timvt(int a[], int n, int x, int dem[], int &aa)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            dem[aa] = i + 1;
            ++aa;
        }
    }
}

// ham chuyen vi tri
void chuyen(int *a, int n, int dem[], int aa, int x)
{
    for (int i = 0; i < aa; i++)
    {
        for (int j = dem[i] - 1 - i; j < n; j++)
        {
            a[j] = a[j + 1];
        }
        a[n - 1] = x;
    }
}

int main()
{
    int aa = 0;
    int dem[100];
    int x, a[100], n;
    printf("nhap n = ");
    scanf("%d", &n);
    nhap(a, n);
    printf("Sau day la mang vua nhap: \n");
    xuat(a, n);
    printf("\nNhap x = ");
    scanf("%d", &x);
    printf("\tSo %d nam o vi tri:", x);
    timvt(a, n, x, dem, aa);
    xuat(dem, aa);
    printf("Day tra ket qua:\n");
    chuyen(a, n, dem, aa, x);
    xuat(a, n);
}