#include <stdio.h>
#include <stdbool.h>
#include <math.h>
void menu();
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();
int soLonNhat(int a, int b, int c);
bool kiemTraNamNhuan(int nam);
void swap(int *a, int *b);
const char* checkTriangle(float a, float b, float c);
int main(){
    int chon;
    do
    {
        menu();
        printf(">> Xin mời chọn chức năng (1-5): ");
        scanf("%d",&chon);
        switch (chon)
        {
        case 1:
            chucNang1();
            break;
        case 2:
            chucNang2();
            break;
        case 3:
            chucNang3();
            break;
        case 4:
            chucNang4();
            break;
        case 5:
            printf("Tam biet!");
            break;
        default:
            printf("Ban phai chon chuc nang tu 1 - 5\n");
            break;
        }
    } while (chon != 5);
    
    return 0;
}
void menu(){
    printf("+---------------------------------------------------+\n");
    printf("|             MENU CHƯƠNG TRÌNH LAB 5               |\n");
    printf("+---------------------------------------------------+\n");
    printf("| 1. Tìm giá trị lớn nhất trong 3 số                |\n");
    printf("| 2. Kiểm tra Năm nhuận                             |\n");
    printf("| 3. Hoán vị 2 số (Sử dụng Con trỏ)                 |\n");
    printf("| 4. Kiểm tra & Phân loại Tam giác                  |\n");
    printf("| 5. Thoát chương trình                             |\n");
    printf("+---------------------------------------------------+\n");
}

void chucNang1(){
    int a,b,c;
    printf("Nhap a,b,c: ");
    scanf("%d%d%d",&a,&b,&c);
    printf("So lon nhat: %d\n",soLonNhat(a,b,c));
}

int soLonNhat(int a, int b, int c){
    int lonNhat = a;
    if(lonNhat<b){
        lonNhat = b;
    }else if (lonNhat < c)
    {
        lonNhat = c;
    }
    return lonNhat;
}
