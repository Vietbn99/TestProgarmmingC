/*
    Tạo 1 danh sách các số nguyên ( dùng dslk ) có n phần tử, nhập và in các phần tử đó theo chiều xuôi, ngược
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *file;
    file = fopen("file.txt", "w");
    int arr[100], n;
    printf("Nhap n = ");
    scanf("%d", &n);
    // nhap mang
    for (int i = 0; i < n; i++)
    {
        printf("pt[%d] = ", i + 1);
        scanf("%d", &arr[i]);
        fprintf(file, "%d\t", arr[i]);
    }
    fclose(file);
    // mo file doc va in ra
    FILE *p;
    int arr1[100];
    int i = 0, success;
    p = fopen("file.txt", "r");
    while (success != EOF)
    {
        success = fscanf(p, "%d", &arr1[i]);
        ++i;
    }
    printf("\nIn cac pt theo chieu xuoi:\n");
    for (int j = 0; j < i - 1; j++)
    {
        printf("%d\t", arr1[j]);
    }
    printf("\nIn cac pt theo chieu nguoc:\n");
    for (int j = i - 2; j >= 0; j--)
    {
        printf("%d\t", arr1[j]);
    }
}