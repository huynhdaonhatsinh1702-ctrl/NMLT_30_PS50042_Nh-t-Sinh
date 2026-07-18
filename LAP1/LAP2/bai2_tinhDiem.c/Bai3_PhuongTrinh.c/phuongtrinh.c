#include <stdio.h>

int main() {
    float a, b, x;

    // Nhập hệ số a và b từ bàn phím
    printf("Nhap he so a (a != 0): ");
    scanf("%f", &a);
    printf("Nhap he so b: ");
    scanf("%f", &b);

    // Tính nghiệm x của phương trình ax + b = 0
    // Vi a luon khac 0 nen x = -b / a
    x = -b / a;

    // Xuất kết quả ra màn hình (lấy 2 chữ số thập phân)
    printf("Nghiem cua phuong trinh %.2f*x + %.2f = 0 la: x = %.2f\n", a, b, x);

    return 0;
}