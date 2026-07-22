#include <stdio.h>

// Định nghĩa hằng số PI theo yêu cầu
#define PI 3.14159

int main() {
    // === 1. BÀI TOÁN HÌNH CHỮ NHẬT ===
    float chieu_dai, chieu_rong;
    float cv_hcn, dt_hcn;

    printf("--- HÌNH CHỮ NHẬT ---\n");
    printf("Nhập chiều dài: ");
    scanf("%f", &chieu_dai);
    printf("Nhập chiều rộng: ");
    scanf("%f", &chieu_rong);

    // Tính toán
    cv_hcn = (chieu_dai + chieu_rong) * 2;
    dt_hcn = chieu_dai * chieu_rong;

    // Hiển thị kết quả
    printf("Chu vi hình chữ nhật: %.2f\n", cv_hcn);
    printf("Diện tích hình chữ nhật: %.2f\n\n", dt_hcn);
}