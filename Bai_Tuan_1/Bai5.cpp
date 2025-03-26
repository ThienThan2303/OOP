#include<iostream>
using namespace std;

//1. Khai báo struct hocSinh
struct hocSinh
{
    string ten;
    float diemToan;
    float diemVan;
    float diemAnh;
    float diemTrungBinh;
};
typedef struct hocSinh HOCSINH;

//2. Các hàm cần thiết
void nhap(HOCSINH&);
void xuat(HOCSINH);
void tinhDiemTrungBinh(HOCSINH&);

//3. Khai báo hàm tính điểm trung bình
void tinhDiemTrungBinh(HOCSINH &hs)
{
    hs.diemTrungBinh = (hs.diemToan * 2 + hs.diemVan + hs.diemAnh) / 4.0;
}

//4. Khai báo hàm nhập
void nhap(HOCSINH &hs)
{
    cout << "Nhập thông tin học sinh: " << endl;
    do
    {
        cout << "Nhập tên học sinh: ";
        getline(cin, hs.ten);
        if(hs.ten == "" ||cin.fail())
        {
            cout << "Tên học sinh không được để trống. Vui lòng nhập lại!" << endl;
            continue;
        }
        break;
    } while (true);
    
    do
    {
        cout << "Nhập điểm toán: ";
        cin >> hs.diemToan;
        if(cin.fail() || hs.diemToan < 0 || hs.diemToan > 10)
        {
            cin.clear();
            cin.ignore();
            cout << "Điểm không hợp lệ. Vui lòng nhập lại!" << endl;
            continue;
        }
        break;
    } while (true);
    
    do
    {
        cout << "Nhập điểm văn: ";
        cin >> hs.diemVan;
        if(cin.fail() || hs.diemVan < 0 || hs.diemVan > 10)
        {
            cin.clear();
            cin.ignore();
            cout << "Điểm không hợp lệ. Vui lòng nhập lại!" << endl;
            continue;
        }
        break;
    } while (true);
    
    do 
    {
        cout << "Nhập điểm anh: ";
        cin >> hs.diemAnh;
        if(cin.fail() || hs.diemAnh < 0 || hs.diemAnh > 10)
        {
            cin.clear();
            cin.ignore();
            cout << "Điểm không hợp lệ. Vui lòng nhập lại!" << endl;
            continue;
        }
        break;
    } while (true);
    cin.ignore();
}
    
//5. Khai báo hàm xuất
void xuat(HOCSINH hs)
{
    cout << "---------Thông tin học sinh---------" << endl;
    cout << "Tên học sinh: " << hs.ten << endl;
    cout << "Điểm toán: " << hs.diemToan << endl;
    cout << "Điểm văn: " << hs.diemVan << endl;
    cout << "Điểm anh: " << hs.diemAnh << endl;
    cout << "Điểm trung bình: " << hs.diemTrungBinh << endl;
}

//6. Hàm chính
int main()
{
    HOCSINH hs;
    nhap(hs);
    xuat(hs);
    return 1;
}