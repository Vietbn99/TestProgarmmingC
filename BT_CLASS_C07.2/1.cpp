/*
    liet ke cac so nguyen to nho hon N.
*/

#include <stdio.h>
#include <math.h>
// ham xuat cac so nguyen to
void snt(int n)
{
    bool dem = true;
    if (n > 2)
    {
        printf("\t2\t");
    }
    for (int i = 2; i < n; i++)
    {
        dem = true;
        for (int j = 2; j <= sqrt(n); j++)
        {
            if (i % j == 0)
            {
                dem = false;
            }
        }
        if (dem)
        {
            printf("%d\t", i);
        }
    }
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Sau day cac so nguyen to nho hon %d\n", n);
    snt(n);
    printf("\n");
    return 0;
}
