/*
    cong 2 ma tran.
*/

#include <stdio.h>
// ham nhap
void nhap(int a[][10], int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

// ham hien thi
void xuat(int a[][10], int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
}
//ham tinh tong
void tong(int a[][10], int b[][10], int r, int cc)
{
    for (int i = 0; i < cc; i++)
    {
        for (int j = 0; j < r; j++)
        {
            a[i][j] += b[i][j];
        }
    }
}

int main()
{
    int a[10][10], b[10][10];
    int r, c;
    printf("Moi ban nhap so hang cua ma tran: ");
    scanf("%d", &r);
    printf("Moi ban nhap so cot cua ma tran: ");
    scanf("%d", &c);
    printf("Moi ban nhap cac pt ma tran A:\n");
    nhap(a, r, c);
    printf("Moi ban nhap cac pt ma tran B:\n");
    nhap(b, r, c);
    printf("Sau day la 2 ma tran vua nhap: \n");
    xuat(a, r, c);
    printf("\n");
    xuat(b, r, c);
    printf("Sau day la ma tran tong: \n");
    tong(a, b, r, c);
    xuat(a, r, c);
}