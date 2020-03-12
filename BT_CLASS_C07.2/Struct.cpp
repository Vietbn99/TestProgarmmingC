/*
    Viết chương trình quản lý danh sách sinh viên. Tạo menu có các yêu cầu sau:
    1, Nhập số lượng sinh viên
    2, Nhập Danh sách sinh viên
    3, In Danh Sách sinh viên
    4, Tìm kiếm và Sửa 1 sinh viên trong danh sách
    5, Sắp xếp sinh viên theo điểm
    6, Sắp xếp sinh viên theo tên.
    Yêu cầu: mỗi chức năng viết bằng 1 hàm, người dùng nhập phím nào thì chạy hàm tương ứng. 
    Hợp lí trong cách sử dụng.
    VD: nếu người dùng chưa nhập số lượng sinh viên thì không thể nhập danh sách,.... 
    Nếu người dùng chưa nhập danh sách thì không làm được các chức năng còn lại.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef struct Sinhvien
{
    char ten[20];
    char lop[10];
    char quequan[50];
    float diemk1, diemk2, diemtbn;
} SV;

// ham hien thi menu
void hienthimenu()
{
    printf("\t\tMENU\n");
    printf("\t1, Nhap so luong sinh vien\n");
    printf("\t2, Nhap danh sach sinh vien\n");
    printf("\t3, In Danh sach sinh vien\n");
    printf("\t4, Tim kiem va sua 1 sinh vien trong danh sach\n");
    printf("\t5, Sap xep sinh vien theo diem\n");
    printf("\t6, Sap xep sinh vien theo ten.\n");
    printf("\t7, Thoat\n");
}
// ham nhap vao danh sach
void nhapdanhsach(SV *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("\tMoi ban nhap thong tin SV %d\n", i + 1);
        printf("    Ten: ");
        fflush(stdin);
        fgets((arr + i)->ten, 20, stdin);
        printf("    Lop: ");
        fflush(stdin);
        fgets((arr + i)->lop, 10, stdin);
        printf("    Que Quan: ");
        fflush(stdin);
        fgets((arr + i)->quequan, 50, stdin);
        printf("    Diem hk1, kh2: ");
        scanf("%f%f", &(arr + i)->diemk1, &(arr + i)->diemk2);
        (arr + i)->diemtbn = ((arr + i)->diemk1 + (arr + i)->diemk2 * 2) / 3;
    }
}
// ham in danh sach
void indanhsach(SV arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d.\tTen: %s\tLop: %s\tQue Quan: %s\tDiem TB nam: %.2f\n", i + 1, (arr + i)->ten, (arr + i)->lop, (arr + i)->quequan, (arr + i)->diemtbn);
    }
}
// tim va sua 1 sinh vien
void timvasua(SV *arr, int n)
{
    char tensinhvientk[20];
    printf("Moi ban nhap ten sinh vien de tim kiem: ");
    fflush(stdin);
    fgets(tensinhvientk, 20, stdin);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(tensinhvientk, (arr + i)->ten) == 0)
        {
            printf("\tTen: %s\tLop: %s\tQue Quan: %s\tDiem TB nam: %.2f\n", (arr + i)->ten, (arr + i)->lop, (arr + i)->quequan, (arr + i)->diemtbn);
            printf("Moi ban sua thong tin cua sinh vien cua sinh vien tren:\n");
            printf("    Ten: ");
            fflush(stdin);
            fgets((arr + i)->ten, 20, stdin);
            printf("    Lop: ");
            fflush(stdin);
            fgets((arr + i)->lop, 10, stdin);
            printf("    Que Quan: ");
            fflush(stdin);
            fgets((arr + i)->quequan, 50, stdin);
            printf("    Diem hk1, kh2: ");
            scanf("%f%f", &(arr + i)->diemk1, &(arr + i)->diemk2);
            (arr + i)->diemtbn = ((arr + i)->diemk1 + (arr + i)->diemk2 * 2) / 3;
            break;
        }
    }
}
// sap xep theo diem
void sapxeptheodiem(SV *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if ((arr + i)->diemtbn < (arr + j)->diemtbn)
            {
                SV temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    indanhsach(arr, n);
}
// sap xep theo ten
void sapxeptheoten(SV *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if ((arr + i)->ten[0] > (arr + j)->ten[0])
            {
                SV temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    indanhsach(arr, n);
}

int main()
{
    int n, dmuc;
    SV *dssv;
    bool danhapslsv = false;
    bool danhapds = false;
    hienthimenu();
nhaplai:
    printf("Moi ban nhap yeu cau can thuc hien: ");
    scanf("%d", &dmuc);
    switch (dmuc)
    {
    case 1:
        printf("Moi ban nhap so luong sinh vien co trong danh sach: ");
        scanf("%d", &n);
        danhapslsv = true;
        goto nhaplai;
    case 2:
        if (danhapslsv)
        {
            dssv = (SV *)malloc(n * sizeof(SV));
            nhapdanhsach(dssv, n);
            danhapds = true;
        }
        else
        {
            printf("\tBan chua nhap so luong sinh vien. Hay nhap so luong sinh vien truoc>>>\n");
        }
        goto nhaplai;
    case 3:
        if (danhapslsv && danhapds)
        {
            indanhsach(dssv, n);
        }
        else
        {
            printf("\tChua co du lieu nhap vao yeu cau nhap truoc..>>>\n");
        }
        goto nhaplai;
    case 4:
        if (danhapslsv && danhapds)
        {
            timvasua(dssv, n);
        }
        else
        {
            printf("\tChua co du lieu nhap vao yeu cau nhap truoc..>>>\n");
        }
        goto nhaplai;
    case 5:
        if (danhapslsv && danhapds)
        {
            sapxeptheodiem(dssv, n);
        }
        else
        {
            printf("\tChua co du lieu nhap vao yeu cau nhap truoc..>>>\n");
        }
        goto nhaplai;
    case 6:
        if (danhapslsv && danhapds)
        {
            sapxeptheoten(dssv, n);
        }
        else
        {
            printf("\tChua co du lieu nhap vao yeu cau nhap truoc..>>>\n");
        }
        goto nhaplai;
    case 7:
        break;
    default:
        printf("\tYeu cau cua ban khong hop le!!! Vui long nhap lai>>> \n");
        goto nhaplai;
    }
    free(dssv);
}