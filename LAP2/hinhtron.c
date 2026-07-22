#include <stdio.h>

// Định nghĩa hằng số PI theo yêu cầu
#define PI 3.14159

int main() {
    float ban_kinh, chu_vi, dien_tich;

    // Nhập bán kính từ bàn phím
    printf("Nhâp vao ban kinh hinh tron: ");
    scanf("%f", &ban_kinh);

    // Tính chu vi và diện tích
    chu_vi = 2 * PI * ban_kinh;
    dien_tich = PI * ban_kinh * ban_kinh;

    // Hiển thị kết quả ra màn hình
    printf("Chu vi hinh tron la: %.2f\n", chu_vi);
    printf("Dien tich hinh tron la: %.2f\n", dien_tich);

    return 0;
}