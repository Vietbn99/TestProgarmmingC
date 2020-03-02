/*
    Tach mang thanh 2 mang chan va le.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// ham random
int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

//ham hien thi
void xuat(int a[], int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("%d\t", a[j]);
    }
    printf("\n");
}
// ham chinh
int main()
{
    int aa = 0, bb = 0, n;
    srand((int)time(0));
    int a[100], chan[100], le[100];

    for (int i = 0; i < 9; i++)
    {
        a[i] = random(1, 100);
    }
    printf("Nhap so pt co day = ");
    scanf("%d", &n);
    xuat(a, n);

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            chan[aa] = a[i];
            ++aa;
        }
        else
        {
            le[bb] = a[i];
            ++bb;
        }
    }

    printf("Mang chan:\n");
    xuat(chan, aa);
    printf("Mang le:\n");
    xuat(le, bb);
}