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
//2. Kiểm tra Năm nhuận  
void chucNang2(){
    int nam;
    printf("Nhap nam: ");
    scanf("%d",&nam);
    if(kiemTraNamNhuan(nam)){
        printf("Nam %d la nam nhuan\n",nam);
    }else{
        printf("Nam %d khong phai la nam nhuan\n",nam);
    }
}
// 1 nhuan.   0 khong nhuan
//Năm nhuận là năm chia hết cho 400, hoặc chia hết cho 4 nhưng không chia hết cho 100
bool kiemTraNamNhuan(int nam){
    if(nam%400==0 || (nam%4==0 && nam%100!=0))
        return true;
    else
        return false;
}
//hoan vi
void chucNang3(){
    int x,y;
    printf("Nhap hai so x, y: ");
    scanf("%d%d",&x,&y);
    printf("Truoc khi hoan vi x = %d. y = %d\n",x,y);
    swap(&x,&y); //chú ý
    printf("Sau khi hoan vi x = %d. y = %d\n",x,y);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
} 

void chucNang4(){
    int a,b,c;
    printf("Nhap 3 canh a,b,c: ");
    scanf("%d%d%d",&a,&b,&c);
    printf("%s\n",checkTriangle(a,b,c));
}

//tri tuyet doi |6 - 4| = 2  abs
const char* checkTriangle(float a, float b, float c){
if(a+b>c && a+c>b && b+c>a && a>0 && b>0 && c>0)
        if(a==b && b==c)
            return "Tam giac deu.";
        else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
        {
            if(a==b || a==c || b==c){
                return "Tam giac vuong can";
            }else{
                return "Tam giac vuong";
            }
        }else 
            return "Tam giac thuong";
    else
        return "Khong phai la bo 3 canh cua tam giac";
}
