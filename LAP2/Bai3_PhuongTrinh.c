#include <stdio.h>

int main() {
    float a, b, x;

    // Nhập dữ liệu từ bàn phím
    printf("Nhap he so a (a != 0): ");
    scanf("%f", &a);
    
    printf("Nhap he so b: ");
    scanf("%f", &b);

    // Tính nghiệm (Vì giả định a luôn khác 0 nên không cần kiểm tra a == 0)
    x = -b / a;

    // Xuất kết quả ra màn hình
    printf("Nghiem cua phuong trinh %.2f * x + %.2f = 0 la: x = %.2f\n", a, b, x);

    return 0;
}