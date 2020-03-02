/*
    liet ke cac so nguyen to nho hon N.
*/

#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    bool dem = true;
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n > 2)
    {
        printf("2\t");
    }
    for (int i = 2; i <= n; i++)
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
    return 0;
}