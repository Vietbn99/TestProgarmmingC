/*
    ...
*/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 100
struct Doanhnghiep
{
    char madn[50];
    char giamdoc[50];
    float vondl;
    int nhanvien;
};

// Ham hien thi
void hienthi()
{
    cout << "\n\t\tCHAO MOI BAN DEN VOI CHUONG TRINH CUA CHUNG TOI:\n\n";
    cout << "1.\tNhap danh sach doanh nghiep.\n";
    cout << "2.\tSap xep tang dan cua von hoa dieu le.\n";
    cout << "3.\tXuat sanh sach doanh nghiep.\n";
    cout << "4.\tIn ra ma doanh nghiep, so nhan vien cua cac doanh nghiep\n\t\t co ma bat dau bang DN va co nhieu hon 300 nhan vien\n";
    cout << "5.\tXuat ra doanh nghiep khong hop le.(do co ma dn chua ky tu cach va von dieu le nho hon 10).\n";
    cout << "6.\tThoat\n\n";
}

//ham nhap
void nhap(Doanhnghiep *a, int &n)
{
    cout << "Danh sach ban chuan bi nhap gom bao nhieu doanh nghiep:  ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        getchar();
        cout << "Ma Doanh nghiep thu " << i + 1 << " : ";
        cin.getline(a[i].madn, 50);
        cout << "Giam Doc : ";
        cin.getline(a[i].giamdoc, 50);
        cout << "Von dieu le cua doanh nghiep: ";
        cin >> a[i].vondl;
        cout << "So nhan vien : ";
        cin >> a[i].nhanvien;
    }
}

//ham sap xep vdl
void sapxep(Doanhnghiep a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].vondl > a[j].vondl)
            {
                float temp = a[i].vondl;
                a[i].vondl = a[j].vondl;
                a[j].vondl = temp;
            }
        }
    }
}

// Ham xuat
void xuat(Doanhnghiep a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ".\t" << a[i].madn << "\n\t"
             << "Giam Doc: " << a[i].giamdoc << "\n\tVon dieu le: " << a[i].vondl << "\n\tSo nhan vien: " << a[i].nhanvien << endl;
    }
}

// Ham in ra dn co MA bd "DN" va so nhan vien nhieu hon 300
void in4(Doanhnghiep a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].madn[0] == 'D' && a[i].madn[1] == 'N' && a[i].nhanvien >= 300)
        {
            cout << "Ma Doanh nghiep: " << a[i].madn << "\n\tSo nhan vien: " << a[i].nhanvien << endl;
        }
    }
}

// Ham xuat doanh nghiep khong hop le
void dnkhl(Doanhnghiep a[], int n)
{
    int aa = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(a[i].madn); j++)
        {
            if (a[i].madn[j] == ' ' && a[i].vondl < 10)
            {
                aa++;
            }
        }
        if (aa != 0)
        {
            cout << "Ma Doanh nghiep: " << a[i].madn << endl;
        }
    }
}

// ham chinh
int main()
{
    Doanhnghiep a[MAX];
    int ss;
    int n;
    bool danhap = false;
    hienthi();
go_here:
    cout << "MOI BAN CHON MUC CAN THUC HIEN:  ";
    cin >> ss;

    switch (ss)
    {
    case 1:
        nhap(a, n);
        danhap = true;
        goto go_here;

    case 2:
        if (danhap)
        {
            sapxep(a, n);
            cout << "Sau day la danh sach da sap xep: \n";
            xuat(a, n);
        }
        else
            cout << "Moi ban nhap DS nghiep truoc\n";
        goto go_here;

    case 3:
        if (danhap)
        {
            cout << "Sau day la danh sach doanh nghiep:\n";
            xuat(a, n);
        }
        else
            cout << "Moi ban nhap DS nghiep truoc\n";
        goto go_here;

    case 4:
        if (danhap)
        {
            in4(a, n);
        }
        else
            cout << "Moi ban nhap DS nghiep truoc\n";
        goto go_here;

    case 5:
        if (danhap)
        {
            cout << "Doanh nghiep khong hop le!!!\n";
            dnkhl(a, n);
        }
        else
            cout << "Moi ban nhap DS nghiep truoc\n";
        goto go_here;

    case 6:
        exit(0);

    default:
        cout << "\tKhong co yeu cau nhu vay!!!!!\n";
        goto go_here;
    }
}
