#include<iostream>
using namespace std;

//1. Khai báo struct phanSo
struct phanSo
{
    int tuSo;
    int mauSo;
};
typedef struct phanSo PHANSO;

//2. Các hàm cần thiết
void nhap(PHANSO&);
void xuat(PHANSO);
PHANSO tong(PHANSO, PHANSO);
PHANSO hieu(PHANSO, PHANSO);
PHANSO tich(PHANSO, PHANSO);
PHANSO thuong(PHANSO, PHANSO);

//3. Khai báo hàm nhập
void nhap(PHANSO &ps)
{
    cout << "Nhập tử số: ";
    cin >> ps.tuSo;
    cout << "Nhập mẫu số: ";
    cin >> ps.mauSo;
}

//4. Khai báo hàm xuất
void xuat(PHANSO ps)
{
    cout << ps.tuSo << "/" << ps.mauSo;
}

//5. Khai báo hàm tổng
PHANSO tong(PHANSO a, PHANSO b)
{
    PHANSO temp;
    temp.tuSo = a.tuSo * b.mauSo + b.tuSo * a.mauSo;
    temp.mauSo = a.mauSo * b.mauSo;
    return temp;
}

//6. Khai báo hàm hiệu
PHANSO hieu(PHANSO a, PHANSO b)
{
    PHANSO temp;
    temp.tuSo = a.tuSo * b.mauSo - b.tuSo * a.mauSo;
    temp.mauSo = a.mauSo * b.mauSo;
    return temp;
}

//7. Khai báo hàm tích
PHANSO tich(PHANSO a, PHANSO b)
{
    PHANSO temp;
    temp.tuSo = a.tuSo * b.tuSo;
    temp.mauSo = a.mauSo * b.mauSo;
    return temp;
}

//8. Khai báo hàm thương
PHANSO thuong(PHANSO a, PHANSO b)
{
    PHANSO temp;
    temp.tuSo = a.tuSo * b.mauSo;
    temp.mauSo = a.mauSo * b.tuSo;
    return temp;
}

//9. Hàm rút gọn
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
void Rutgon(PHANSO &a)
{
    int ucln = gcd(a.tuSo, a.mauSo);
    a.tuSo /= ucln;
    a.mauSo /= ucln;
}

//9.Khai báo hàm chính
int main()
{
    PHANSO ps1, ps2, kq;
    cout << "Nhập phân số 1: " << endl;
    nhap(ps1);
    cout << "Nhập phân số 2: " << endl;
    nhap(ps2);
    
    kq = tong(ps1, ps2);
    cout << "Tổng hai phân số: ";
    xuat(kq);
    
    kq = hieu(ps1, ps2);
    cout << "\nHiệu hai phân số: ";
    xuat(kq);
    
    kq = tich(ps1, ps2);
    cout << "\nTích hai phân số: ";
    xuat(kq);
    
    kq = thuong(ps1, ps2);
    cout << "\nThương hai phân số: ";
    xuat(kq);
    
    return 0;
}