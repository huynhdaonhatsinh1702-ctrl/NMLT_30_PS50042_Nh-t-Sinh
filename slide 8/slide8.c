#include<stdio.h>
int main(){
     struct SinhVien{
       char MSSV[7];
        char HoTenSV[30];
        float DiemTB;
    };

   
    
struct SinhVien SinhVien[3];
    for (int i = 0; i <3; i++){
        printf("Nhap MSSV: ");
        gets(SinhVien[i].MSSV);
        printf("Nhap Ho Ten SV: ");
        gets(SinhVien[i].HoTenSV);  
        printf("Nhap Diem TB: ");
        scanf("%f",&SinhVien[i].DiemTB);
        getchar();
    }
    for (int i = 0; i <3; i++){
        printf("MSSV: %s\n",SinhVien[i].MSSV);
        printf("Ho Ten SV: %s\n",SinhVien[i].HoTenSV);  
        printf("Diem TB: %.2f\n",SinhVien[i].DiemTB);
    }
    return 0;
}  