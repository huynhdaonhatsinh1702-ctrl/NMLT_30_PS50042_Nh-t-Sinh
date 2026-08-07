#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//khai báo các hàm chức năng
void chucnang1();
void chucnang2();
void chucnang3();
void chucnang4();
void chucnang5();

int main()
{
    int chon;
    do
    {
        printf("+-------------------------------------------------------+\n");
        printf("|  MENU CHUONG TRINH LAB 6.                             |\n");
        printf("+-------------------------------------------------------+\n");
        printf("| 1. Tinh trung binh tong so chia het cho 3 va 5        |\n");
        printf("| 2. Tim gia tri lon nhat va nho nhat trong mang        |\n");
        printf("| 3. Sap xep mang theo thu tu giam dan                  |\n");
        printf("| 4. Ma tran binh phuong (mang 2 chieu)                 |\n");
        printf("| 5. Loc va xuat vi tri cac so le trong ma tran         |\n");
        printf("| 6. Thoat chuong trinh                                 |\n");
        printf("+-------------------------------------------------------+\n");
        printf("Ban hay chon chuc nang (1 - 6): ");
        scanf("%d", &chon);

        switch (chon)
        {
            case 1:
                printf("Tinh trung binh tong so chia het cho 3 va 5.\n");
                chucnang1();
                break;
            case 2:
                printf("Tim gia tri lon nhat va nho nhat trong mang.\n");
                chucnang2();
                break;
            case 3:
                printf("Sap xep mang theo thu tu giam dan.\n");
                chucnang3();
                break;
            case 4:
                printf("Ma tran binh phuong (mang 2 chieu).\n");
                chucnang4();
                break;
            case 5:
                printf("Loc va xuat vi tri cac so le trong ma tran.\n");
                chucnang5();
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Loi: Chuc nang khong hop le.\n");
                printf("Ban hay chon tu 1 - 6.\n");
                break;
        }
    }
    while (chon != 6);

    return 0;
}

//chức năng và hàm 

float tinhTrungBinh(int a[], int n)
{
    int tong = 0;
    int sodem = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 3 == 0 && a[i] % 5 == 0)
        {
            tong += a[i];
            sodem++;
        }
    }
    if(sodem == 0)
    {
        return -__FLT_MAX__; // số nhỏ nhất kiểu float
    }
    else
    {
        return (float)tong / sodem;
    }
}

void chucnang1()
{
    int n = 5;
    int a[10];
    printf("Nhap 5 so nguyen:\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("Nhap a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    float trungBinh = tinhTrungBinh(a, n);
    if(trungBinh == -__FLT_MAX__)
    {
        printf("Khong co so nao chia het cho 3 va 5 trong mang.\n");
    }
    else
    {
        printf("Trung binh tong cac so chia het cho 3 va 5 trong mang la: %.2f\n", trungBinh);
    }
}

// xg chức năng 1
void timMaxMin(int a[], int n)
{
    int min,max;
    min = a[0];
    max = a[0];
    for(int i = 1; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
        if (max < a[i])
        {
            max = a[i];
        }
    }
    printf("Gia tri nho nhat trong mang la: %d\n", min);
    printf("Gia tri lon nhat trong mang la: %d\n", max);
    
}
void chucnang2()
{
    int n = 5;
    int a[10];
    printf("Nhap 5 so nguyen:\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("Nhap a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    timMaxMin(a, n);
}
//xog chức năng 2

//chức năng 3
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sapXepGiamDan(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] < a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
    }
}
void chucnang3()
{
    int n = 5;
    int a[10];
    printf("Nhap 5 so nguyen:\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("Nhap a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("\n");
    sapXepGiamDan(a, n);    
}
// xog chức năng 3
//chuc năng 4
void maTranBinhPhuong(int row, int col)
{
    int a[row][col];
    //nhap
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Nhap a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    //xuat
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%3d \t", a[i][j] * a[i][j]);
        }
        printf("\n");
    }
} 
void chucnang4()
{
    int row, col;
    printf("Nhap so hang: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &col);
    maTranBinhPhuong(row, col);
}
//xog chức năng 4

//chức năng 5
void xuatSoLeMaTran(int row, int col)
{
    int a[row][col];
    //nhap
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Nhap a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    //xuat vi tri so le
    printf("Vi tri cac so le trong ma tran:\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(a[i][j] % 2 != 0)
            {
                printf("a[%d][%d] = %d\n", i, j, a[i][j]);
            }
        }
    }
}
void chucnang5()
{
    int row, col;
    printf("Nhap so hang: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &col);
    xuatSoLeMaTran(row, col);
}
//xog chức năng 5