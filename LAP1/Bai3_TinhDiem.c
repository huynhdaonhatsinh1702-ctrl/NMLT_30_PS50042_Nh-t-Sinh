#include <stdio.h>

int main() {
    char mssv[20];
    char hoTen[50];
    float diemToan, diemLy, diemHoa, diemTrungBinh;

    // Nhập dữ liệu từ bàn phím
    printf("Nhap ma so sinh vien (MSSV): ");
    scanf("%s", mssv);

    // Xóa bộ nhớ đệm trước khi nhập chuỗi có khoảng trắng
    printf("Nhap ho va ten: ");
    scanf(" %[^\n]s", hoTen); 

    printf("Nhap diem Toan: ");
    scanf("%f", &diemToan);

    printf("Nhap diem Ly: ");
    scanf("%f", &diemLy);

    printf("Nhap diem Hoa: ");
    scanf("%f", &diemHoa);

    // Công thức tính toán điểm trung bình
    diemTrungBinh = (diemToan * 2 + diemLy + diemHoa) / 4;

    // Xuất dữ liệu ra màn hình theo đúng định dạng mẫu
    printf("\nMa so sinh vien : %s\n", mssv);
    printf("Ho Va Ten : %s\n", hoTen);
    printf("Diem Trung Binh: %.2f\n", diemTrungBinh); // Làm tròn đến 2 chữ số thập phân

    return 0;
}