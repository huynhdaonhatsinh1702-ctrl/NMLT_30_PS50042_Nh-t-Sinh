#include <stdio.h>
#include <string.h>
void menu();
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();
void chucNang5();
void demNguyenAmPhuAm(char str[]);
void kiemTraDangNhap(char username[], char password[]);
void sapXepChuoi(char arr[][100], int n);
void thapPhanSangNhiPhan(int n);
int main()
{
    int chon;
    do
    {
        menu();
        printf(">> Xin mời chọn chức năng (1-5): ");
        scanf("%d", &chon);
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
void menu()
{
    printf("+---------------------------------------------------+\n");
    printf("|             MENU CHƯƠNG TRÌNH LAB 7               |\n");
    printf("+---------------------------------------------------+\n");
    printf("| 1. Đếm Nguyên âm và Phụ âm trong chuỗi            |\n");
    printf("| 2. Đăng nhập hệ thống (User & Password)           |\n");
    printf("| 3. Sắp xếp danh sách Chuỗi theo thứ tự Alphabet   |\n");
    printf("| 4. Chuyển đổi số Thập phân sang Nhị phân (Chuỗi)  |\n");
    printf("| 5. Thoát chương trình                             |\n");
    printf("+---------------------------------------------------+\n");
    printf(">> Xin mời chọn chức năng (1-5): \n");
}
void chucNang1()
{
    char str[100];
    printf("Nhap chuoi: ");
    scanf(" %[^\n]", str);
    demNguyenAmPhuAm(str);
}
void chucNang2()
{
    char username[50];
    char password[50];
    printf("Nhap username: ");
    scanf("%s", username);
    printf("Nhap password: ");
    scanf("%s", password);
    kiemTraDangNhap(username, password);
}
void chucNang3()
{
    int n;
    printf("Nhap so luong chuoi: ");
    scanf("%d", &n);
    char arr[n][100];
    for (int i = 0; i < n; i++)
    {
        printf("Nhap chuoi thu %d: ", i + 1);
        scanf(" %[^\n]", arr[i]);
    }
    sapXepChuoi(arr, n);
    printf("Danh sach chuoi sau khi sap xep:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
}
void chucNang4()
{
    int n;
    printf("Nhap so thap phan: ");
    scanf("%d", &n);
    printf("So nhiet phan tuong ung la: ");
    thapPhanSangNhiPhan(n);
    printf("\n");
}
void demNguyenAmPhuAm(char str[])
{
    int demNguyenAm = 0;
    int demPhuAm = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
demNguyenAm++;
            }
            else
            {
                demPhuAm++;
            }
        }
    }
    printf("So luong nguyen am: %d\n", demNguyenAm);
    printf("So luong phu am: %d\n", demPhuAm);
}
void kiemTraDangNhap(char username[], char password[])
{
    const char correctUsername[] = "admin";
    const char correctPassword[] = "123456";

    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0)
    {
        printf("Dang nhap thanh cong!\n");
    }
    else
    {
        printf("Dang nhap that bai! Sai username hoac password.\n");
    }
}
void sapXepChuoi(char arr[][100], int n)
{
    char temp[100];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}
void thapPhanSangNhiPhan(int n)
{
    if (n == 0)
    {
        printf("0");
        return;
    }
    int binary[32];
    int i = 0;
    while (n > 0)
    {
        binary[i] = n % 2;
        n /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
}
