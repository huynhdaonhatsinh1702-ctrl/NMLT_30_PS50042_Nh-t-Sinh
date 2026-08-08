#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include<float.h>
void menu();
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();
void chucNang5();

float tinhTrungBinhCong(int a[], int n);
void timMaxMin(int a[], int n);
void sapXepGiamDan(int a[], int n);
void maTranBinhPhuong(int row, int col);
void swap(int *a, int *b);
int main(){
    int chon;
    do
    {
        menu();
        printf(">> Xin mời chọn chức năng (1-6): ");
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
            chucNang5();
            break;
        case 6:
            printf("Tam biet!");
            break;
        default:
            printf("Ban phai chon chuc nang tu 1 - 6\n");
            break;
        }
    } while (chon != 6);
    
    return 0;
}

void menu(){
    printf("+---------------------------------------------------+\n");
    printf("|             MENU CHƯƠNG TRÌNH LAB 6               |\n");
    printf("+---------------------------------------------------+\n");
    printf("| 1. Tính trung bình tổng số chia hết cho 3 và 5    |\n");
    printf("| 2. Tìm giá trị Lớn nhất và Nhỏ nhất trong Mảng    |\n");
    printf("| 3. Sắp xếp Mảng theo thứ tự Giảm dần              |\n");
    printf("| 4. Ma trận bình phương (Mảng 2 chiều)             |\n");
    printf("| 5. Lọc và xuất vị trí các Số lẻ trong Ma trận     |\n");
    printf("| 6. Thoát chương trình                             |\n");
    printf("+---------------------------------------------------+\n");
    
}

void chucNang1(){
    int n;
    int a[10];
    printf("Nhap n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Nhap A[%d]= ",i);
        scanf("%d",&a[i]);
    }
    float tbc = tinhTrungBinhCong(a,n);
    if(tbc == -FLT_MAX){
        printf("Khong co so chia het cho 3 va 5\n");
    }else{
        printf("Trung binh cong cua mang: %.2f\n",tbc);
    }
}

//2. Kiểm tra Năm nhuận  
void chucNang2(){
    int n;
    int a[10];
    printf("Nhap n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Nhap A[%d]= ",i);
        scanf("%d",&a[i]);
    }
    timMaxMin(a,n);
}

//hoan vi
void chucNang3(){
    int n;
    int a[10];
    printf("Nhap n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Nhap A[%d]= ",i);
        scanf("%d",&a[i]);
    }
    sapXepGiamDan(a,n);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
} 

void chucNang4(){
    maTranBinhPhuong(3,3);
}

void chucNang5(){

}

//////
float tinhTrungBinhCong(int a[], int n){
    int tong = 0;
    int soDem = 0;
    for(int i=0;i<n;i++){
        if(a[i]%3==0 && a[i]%5==0){
            tong+=a[i];
            soDem++;
            }
    }
    if(soDem==0){
        return -FLT_MAX; //số nhỏ nhất trong float
    }else{
        return (float)tong/soDem;
    }
        
}

void timMaxMin(int a[], int n){
    //4 6 3 8
    int min,max;
    min=a[0]; //4
    max=a[0]; //4
    for(int i=1;i<n;i++){
        if(min>a[i]){   //1   4 > 6  
                        //2.  4 > 3   min = 3
            min=a[i];
        }
        if(max<a[i]){   //1   4 < 6. max = 6
                        //2   6 < 3
            max=a[i]; 
        }
    }
    printf("Min = %d\t Max = %d\n",min,max);
}

void sapXepGiamDan(int a[], int n){
    //8 6 4 3.   n=4
    for(int i=0;i<n-1;i++){         //i=3 < 4-1
        for(int j=i+1;j<n;j++){     //j=3 <4
            if(a[i] > a[j]){        //a[2] = 3. a[3] = 4
                swap(&a[i],&a[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void maTranBinhPhuong(int row, int col){
    int a[row][col];
    //nhap
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("A[%d,%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    //xuat
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%4d\t",a[i][j]*a[i][j]);
        }
        printf("\n");
    }
}