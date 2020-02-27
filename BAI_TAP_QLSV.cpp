/*
    Nhap danh sach lop C nhung thong tin sau: ho va ten, lop, ngay sinh, que quan, diem trung binh. biet dtb < 4 thi phai hoc lai c
    to chuc menu sau:
    1, Nhap danh sach sinh vien
    2, In danh sach sinh vien 
    3, Sap xep danh sach sinh vien theo diem
    4, in ra nhung ban phai hoc lai C
    5, tim kiem 1 hoc sinh trong lop, neu co in ra thong tin hoc sinh ra man hinh, neu khong them hoc sinh do vao lop.
    6, xoa 1 ban ra khoi lop.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct ngaysinh
{
    int ngay, thang, nam;
};
struct SinhVien
{
    char hovaten[50];
    char lop[10];
    ngaysinh dmy;
    char quequan[100];
    float dtb;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ham hien thi menu
void hienthi(void)
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~   CHAO MUNG BAN DA DEN VOI MENU DO MK TU TAO:   ~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~    1.  Nhap danh sach sinh vien.                ~~\n");
    printf("~~    2.  In danh sach sinh vien.                  ~~\n");
    printf("~~    3.  Sap xep danh sach sinh vien theo diem.   ~~\n");
    printf("~~    4.  In ra nhung ban phai hoc lai C.          ~~\n");
    printf("~~    5.  Tim kiem 1 hoc sinh trong lop.           ~~\n");
    printf("~~    6.  Xoa 1 ban ra khoi lop.                   ~~\n");
    printf("~~    7.  Thoat.                                   ~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ham nhap
void nhap(SinhVien a[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("\nHay nhap thong tin cho Sinh Vien thu %d\n", i + 1);
        printf("Ho va ten: ");
        fgets(a[i].hovaten, sizeof(a[i].hovaten), stdin);
        printf("Lop: ");
        fgets(a[i].lop, sizeof(a[i].lop), stdin);
        printf("Ngay sinh: ");
        scanf("%d%d%d", &a[i].dmy.ngay, &a[i].dmy.thang, &a[i].dmy.nam);
        printf("Que Quan (tinh):");
        getchar();
        fgets(a[i].quequan, sizeof(a[i].quequan), stdin);
        printf("Diem trung binh = ");
        scanf("%f", &a[i].dtb);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ham xuat
void xuat(SinhVien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d: %s\t\t%s\t\t%d/%d/%d\n\t\t%s\t\t%.2f\n", i + 1, a[i].hovaten, a[i].lop, a[i].dmy.ngay, a[i].dmy.thang, a[i].dmy.nam, a[i].quequan, a[i].dtb);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ham sap xep
void sx(SinhVien *a, int n)
{
    SinhVien temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].dtb < a[j].dtb)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ham tim kiem
void timkiem(SinhVien *a, char aa[30], int &n)
{
    bool kiem = true;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(aa, a[i].hovaten) == 0)
        {
            printf("%d: %s\t\t%s\t\t%d/%d/%d\n\t\t%s\t\t%.2f", i + 1, a[i].hovaten, a[i].lop, a[i].dmy.ngay, a[i].dmy.thang, a[i].dmy.nam, a[i].quequan, a[i].dtb);
            kiem = false;
        }
    }
    if (kiem)
    {
        printf("Ten ban vua nhap khong co trong danh sach, vay hay them vao:");
        printf("Hay nhap thong tin cho Sinh Vien:\n");
        printf("Ho va ten: ");
        fgets(a[n].hovaten, sizeof(a[n].hovaten), stdin);
        printf("Lop: ");
        fgets(a[n].lop, sizeof(a[n].lop), stdin);
        printf("Ngay sinh: ");
        scanf("%d%d%d", &a[n].dmy.ngay, &a[n].dmy.thang, &a[n].dmy.nam);
        printf("Que Quan (tinh):");
        getchar();
        fgets(a[n].quequan, sizeof(a[n].quequan), stdin);
        printf("Diem trung binh = ");
        scanf("%f", &a[n].dtb);
        n++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ham xoa
void xoa(SinhVien *a, char aa[30], int &n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(aa, a[i].hovaten) == 0)
        {
            n--;
            break;
        }
    }
    for (i; i < n; i++)
    {
        a[i] = a[i + 1];
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ham xuat file
void xuatFile(SinhVien a[], int n, char fileName[])
{
    FILE *fp;
    fp = fopen(fileName, "w");
    fprintf(fp, "%s: %s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n", "STT", "Ho Va Ten", "Lop", "Ngay Sinh", "Que Quan", "DTB");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d:  %s\t\t%s\t\t%d/%d/%d\n\t\t%s\t\t%.2f\n", i + 1, a[i].hovaten, a[i].lop, a[i].dmy.ngay, a[i].dmy.thang, a[i].dmy.nam, a[i].quequan, a[i].dtb);
    }
    fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ham chinh
int main()
{
    SinhVien b[100];
    char fileName[] = "DSSV.txt";
    bool daNhap = false;
    int n, ss;
    hienthi();
go_here:
    printf("\nMOI BAN NHAP SO TUONG UNG TREN MENU:");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        printf("\nMoi ban nhap sach sinh vien:\n");
        scanf("%d", &ss);
        nhap(b, ss);
        daNhap = true;
        xuatFile(b, ss, fileName);
        goto go_here;
    case 2:
        if (daNhap)
        {
            printf("\nSau day la danh sach sinh vien:\n");
            xuat(b, ss);
        }
        else
            printf("Ban chua nhap danh sach... Hay nhap truoc nhe...\n");
        xuatFile(b, ss, fileName);
        goto go_here;
    case 3:
        if (daNhap)
        {
            printf("\nSau day la danh sach sap xep sinh vien theo diem tu cao xuong thap:\n");
            sx(b, ss);
            xuat(b, ss);
        }
        else
            printf("Ban chua nhap danh sach... Hay nhap truoc nhe...\n");
        xuatFile(b, ss, fileName);
        goto go_here;
    case 4:
        if (daNhap)
        {
            printf("\nSau day la danh sach cac sinh vien hoc lai C:\n");
            for (int i = 0; i < ss; i++)
            {
                if (b[i].dtb < 4)
                {
                    printf("\t%s", b[i].hovaten);
                }
            }
        }
        else
            printf("Ban chua nhap danh sach... Hay nhap truoc nhe...\n");
        goto go_here;
    case 5:
        if (daNhap)
        {
            char aa[50];
            printf("\nHay nhap day du ho va ten sinh vien (khong dau) de tim kiem:\n");
            getchar();
            fgets(aa, sizeof(aa), stdin);
            timkiem(b, aa, ss);
        }
        else
            printf("Ban chua nhap danh sach... Hay nhap truoc nhe...\n");
        goto go_here;
    case 6:
        if (daNhap)
        {
            char aaa[50];
            printf("\nHay nhap day du ho va ten sinh vien (khong dau) ma ban muon xoa:\n");
            getchar();
            fgets(aaa, sizeof(aaa), stdin);
            xoa(b, aaa, ss);
        }
        else
            printf("Ban chua nhap danh sach... Hay nhap truoc nhe...\n");
        xuatFile(b, ss, fileName);
        goto go_here;
    case 7:
        return 0;
    default:
        printf("Khong co yeu cau nhu vay!!!... \n");
        goto go_here;
    }
}
