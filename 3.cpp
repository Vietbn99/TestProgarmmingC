/*
    Chỉ sử dụng một con trỏ có kiểu cấu trúc sinh viên gồm các trường: 
    họ tên, tuổi, điểm lý thuyết, điểm thực hành, điểm trung bình, 
    trong đó: điểm trung bình = (điểm lý thuyết + điểm thực hành * 2) / 3 
    Hãy nhập vào 5 sinh viên và cho biết sinh viên có điểm trung bình cao nhất
*/
#include <stdio.h>
struct Sinhvien
{
    char hoten[50];
    int tuoi;
    float dlt, dth, dtb;
};
// ham nhap
void nhap(Sinhvien *p)
{
    printf("Nhap thong tin sinh vien: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Nhap thong tin sinh vien thu %d: \n", i + 1);
        printf("Ten: ");
        getchar();
        fflush(stdin);
        scanf("%s", (p + i)->hoten);
        printf("Tuoi: ");
        fflush(stdin);
        scanf("%d", &(p + i)->tuoi);
        printf("Diem ly thuyet, diem thuc hanh: ");
        fflush(stdin);
        scanf("%f%f", &(p + i)->dlt, &(p + i)->dth);
        (p + i)->dtb = ((p + i)->dlt + (p + i)->dth * 2) / 3;
    }
}
int main()
{
    Sinhvien *p;
    nhap(p);
    float max;
    max = p->dtb;
    for (int i = 1; i < 5; i++)
    {
        if (max < ((p + i)->dtb))
        {
            max = ((p + i)->dtb);
        }
    }
    printf("Sinh vien co diem tb cao nhat la:\n");
    for (int i = 0; i < 5; i++)
    {
        if (max = (p + i)->dtb)
        {
            puts((p + i)->hoten);
            break;
        }
    }
}