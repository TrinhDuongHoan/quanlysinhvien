// TRINH DUONG HOAN 22684251 28/3/2023
#include<bits/stdc++.h>

using namespace std ;

#define MAX 100

struct SINHVIEN
{
    char MSSV [10];
    char hoten[30];
    char ghichu[10];
    float TK;
    float GK;
    float CK;
    float TH;
    float DTB;
};

void nhap1(SINHVIEN &sv)
{
    printf("nhap ma so sinh vien : ");scanf("%s",&sv.MSSV);fflush(stdin);
    printf("nhap ho ten sinh vien : ");gets(sv.hoten);fflush(stdin);
    printf("nhap diem thuong ky : ");scanf("%f",&sv.TK);fflush(stdin);
    printf("nhap diem giua ky : ");scanf("%f",&sv.GK);fflush(stdin);
    printf("nhap diem cuoi ky : ");scanf("%f",&sv.CK);fflush(stdin);
    printf("nhap diem thuc hanh : ");scanf("%f",&sv.TH) ;fflush(stdin);
}
void nhapds(SINHVIEN a[], int n)
{
    for (int i = 0 ; i < n; i++ )
    {
        printf("Sinh vien %d \n",i+1);
        nhap1(a[i]);
        printf("\n");
    }
}
void xuatds(SINHVIEN a[], int n)
{
    for (int i = 1; i <= 82; i++) printf("-");
    printf("\n");
    printf("|\t\t\t\t DANH SACH SINH VIEN\t\t\t\t |\n");
    for (int i = 1; i <= 82; i++) printf("-");
    printf("\n");
    printf("|STT|  MSSV    |\t   Ho va ten         | TK | GK | CK | TH |DTB | Ghi chu  | ");
    printf("\n");
    for (int i = 1; i <= 82; i++) printf("-");
    printf("\n");
    for (int i = 0 ; i < n; i++)
    {
        printf("|%-3d|%-10s|%-29s|%-4.1f|%-4.1f|%-4.1f|%-4.1f|%-4.1f|%-10s|",i+1,a[i].MSSV,a[i].hoten,a[i].TK,a[i].GK,a[i].CK,a[i].TH,a[i].DTB,a[i].ghichu);
        printf("\n");
        for (int j = 1; j <= 82; j++) printf("-");
        printf("\n");
    }
    printf("\n");

}
void tinhtrungbinh(SINHVIEN a[],int n)
{
    for (int i = 0 ; i < n; i++ )
    {
        a[i].DTB = ((2*a[i].TK +3*a[i].GK + 5*a[i].CK)/5 + a[i].TH) / 3;
    }
}
void checkdiem( SINHVIEN a[], int n)
{
    char s[10] = " Hoc lai ";
    char s1[10] = "         ";
    for (int i = 0 ; i < n; i++)
    {
        if (a[i].DTB < 4.0)
        {
            strcpy(a[i].ghichu,s);
        }
        else strcpy(a[i].ghichu,s1) ;
    }
}
void xuathoclai(SINHVIEN a[], int n)
{
    int cnt = 0;
    for (int i = 0 ; i < n; i++)
    {
        if (a[i].DTB < 4.0) cnt++;
    }
    if (cnt == 0) printf("Khong co sinh vien hoc lai");
    else
    {
        for (int i = 1; i <= 51; i++) printf("-");
        printf("\n");
        printf("|\t DANH SACH SINH VIEN HOC LAI  \t\t  |\n");
        for (int i = 1; i <= 51; i++) printf("-");
        printf("\n");
        printf("|STT|  MSSV    |\t   Ho va ten         |DTB |\n");
        for (int i = 1; i <= 51; i++) printf("-");
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            if (a[i].DTB < 4.0)
            {
                printf("|%-3d|%-10s|%-29s|%-4.1f|",i+1,a[i].MSSV,a[i].hoten,a[i].DTB);
                printf("\n");
                for (int j = 1; j <= 51; j++) printf("-");
                printf("\n");
            }
        }
    }
}
void sortDTB(SINHVIEN a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1 ; j < n; j++)
        {
            if (a[i].DTB < a[j].DTB) swap(a[i],a[j]);
        }
    }
}
void swap(SINHVIEN &a, SINHVIEN &b)
{
    SINHVIEN tmp = a;
    a = b;
    b = tmp;
}
void menu()
{
    printf("\t DANH SACH CAC CHUC NANG \t \n");
    printf("1. Nhap danh sach sinh vien. \n");
    printf("2. Xuat danh sach sinh vien. \n");
    printf("3. Xuat danh sach sinh vien hoc lai. \n");
    printf("4. Tim kiem sinh vien. \n");
    printf("5. Xuat danh sach sinh vien theo diem trung binh giam dan. \n");
    printf("6.Thoat chuong trinh. \n");
}
void findsv(SINHVIEN a[], char name[], int n)
{
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].hoten,name) == 0)
        {
            printf("Ho ten : %s\n",a[i].hoten);
            printf("Ma sinh vien: %s\n",a[i].MSSV);
            printf("Diem thuong ky: %.1f\n", a[i].TK);
            printf("Diem giua ki: %.1f\n",a[i].GK);
            printf("Diem cuoi ky: %.1f\n",a[i].CK);
            printf("Diem thuc hanh: %.1f\n",a[i].TH);
            printf("Diem trung binh: %.1f\n",a[i].DTB);
            check = 1;
        }
    }
    if (check == 0) printf("Khong tim thay\n");
}
int main()
{
    int n;
    SINHVIEN a[MAX];
    int t;
    do
    {
        menu();
        cin >> t;
        switch(t)
        {
            case 1 :
                printf("Nhap so luong sinh vien : "); scanf("%d",&n);
                nhapds(a,n);
                tinhtrungbinh(a, n);
                checkdiem(a, n);
                break;
            case 2 :
                xuatds(a, n);
                break;
            case 3 :
                xuathoclai(a, n);
                break;
            case 4 :
                char name[30];
                fflush(stdin);
                printf("Nhap sinh vien can tim kiem : "); gets(name);
                findsv(a, name, n);
                break;
            case 5 :
                sortDTB(a, n);
                xuatds(a, n);
                break;
            default:
                printf("Cam on da su dung dich vu, Hen gap lai !\n");
                break;
        }
    } while (t <= 5);
}
