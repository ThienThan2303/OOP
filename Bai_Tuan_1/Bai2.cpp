#include<iostream>
using namespace std;

//1. Khai báo struct phanSo
struct phanSo
{
    int tuSo;
    int mauSo;
};
typedef struct phanSo PHANSO;
void Nhap(PHANSO&);
void Xuat(PHANSO);
int timMax(PHANSO, PHANSO);

//2. Hàm nhập
void Nhap(PHANSO &a)
{
    cout << "Nhập tử số: ";
    cin >> a.tuSo;
    cout << "Nhập mẫu số: ";
    cin >> a.mauSo;
}

//3. Hàm xuất
void Xuat(PHANSO a)
{
    cout << a.tuSo << "/" << a.mauSo;
}

//4. Hàm tìm max
int timMax(PHANSO a, PHANSO b)
{
    float PHANSO1 = (float)a.tuSo / a.mauSo;
    float PHANSO2  = (float)b.tuSo / b.mauSo;
    if(PHANSO1 > PHANSO2) 
        return 1;
    else if(PHANSO1 < PHANSO2)
        return 2;
    else
        return 0;
}

//5. Hàm chính
int main()
{
    PHANSO PS1, PS2;
    cout << "Nhập phân số 1: " << endl;
    Nhap(PS1);
    cout << "Nhập phân số 2: " << endl;
    Nhap(PS2);
    int kq = timMax(PS1, PS2);
    if(kq == 1)
        cout << "Phân số 1 lớn nhất";
    else if(kq == 2)
        cout << "Phân số 2 lớn nhất";
    else
        cout << "Không tồn tại phân số lớn nhất";
    return 1;
}