#include<iostream>
using namespace std;

//1. Khai báo struct phanSo
struct PhanSo
{
    int tu;
    int mau;
};
typedef struct PhanSo PHANSO;
void Nhap(PHANSO&);
void Xuat(PHANSO);
void Rutgon(PHANSO&);
int gcd(int a, int b);

//2. Hàm chính
int main()
{
    PHANSO PS;
    Nhap(PS);
    Rutgon(PS);
    cout << "Phân số sau khi được rút gọn là: ";
    Xuat(PS);
    return 1;
}

int gcd(int a, int b)
{
    while(b!=0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
        return a;
}

//3. Hàm nhập
void Nhap(PHANSO &a)
{
    cout << "Nhập tử số: ";
    cin >> a.tu;
    cout << "Nhập mẫu số: ";
    cin >> a.mau;
}

//4. Hàm xuất
void Xuat(PHANSO a)
{
    cout << a.tu << "/" << a.mau;
}

//5. Hàm rút gọn
void Rutgon(PHANSO &a)
{
    int ucln = gcd(a.tu, a.mau);
    a.tu /= ucln;
    a.mau /= ucln;
}
