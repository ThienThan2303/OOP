#include<iostream>
using namespace std;

//1. Khai báo struct ngayThangNam
struct ngayThangNam
{
    int ngay;
    int thang;
    int nam;
};
typedef struct ngayThangNam NGAYTHANGNAM;

//2. Các hàm cần thiết
void nhap(NGAYTHANGNAM&);
void xuat(NGAYTHANGNAM);
bool kiemTraNamNhuan(NGAYTHANGNAM);
void ngayKeTiep(NGAYTHANGNAM &);

//3. Khai báo hàm nhập
void nhap(NGAYTHANGNAM &ntn)
{
    do
    {
        cout << "Nhập ngày: ";
        cin >> ntn.ngay;
        if(cin.fail() || ntn.ngay < 1 || ntn.ngay > 31)
        {
            cin.clear();
            cin.ignore();
            cout << "Ngày không hợp lệ. Vui lòng nhập lại!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        break;
    } while (true);
    
    do
    {
        cout << "Nhập tháng: ";
        cin >> ntn.thang;
        if(cin.fail() || ntn.thang < 1 || ntn.thang > 12)
        {
            cin.clear();
            cin.ignore();
            cout << "Tháng không hợp lệ. Vui lòng nhập lại!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        break;
    } while (true);
    
    do 
    {
        cout << "Nhập năm: ";
        cin >> ntn.nam;
        if(cin.fail() || ntn.nam < 1)
        {
            cin.clear();
            cin.ignore();
            cout << "Năm không hợp lệ. Vui lòng nhập lại!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        break;
    }while(true);
}

//4. Khai báo hàm xuất
void xuat(NGAYTHANGNAM ntn)
{
    cout << ntn.ngay << "/" << ntn.thang << "/" << ntn.nam;
}

//5. Kiểm tra năm nhuận
bool kiemTraNamNhuan(NGAYTHANGNAM ntn)
{
    if((ntn.nam % 4 == 0 && ntn.nam % 100 != 0) || ntn.nam % 400 == 0)
        return true;
    return false;
}

//6. Khai báo hàm ngày kế tiếp
void ngayKeTiep(NGAYTHANGNAM &ntn)
{
    int soNgayTrongThang;
    switch(ntn.thang)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            soNgayTrongThang = 31;
            break;
        case 4: case 6: case 9: case 11:
            soNgayTrongThang = 30;
            break;
        case 2:
            if(kiemTraNamNhuan(ntn))
                soNgayTrongThang = 29;
            else
                soNgayTrongThang = 28;
            break;
    }
    if(ntn.ngay < soNgayTrongThang)
        ntn.ngay++;
    else
    {
        ntn.ngay = 1;
        if(ntn.thang < 12)
            ntn.thang++;
        else
        {
            ntn.thang = 1;
            ntn.nam++;
        }
    }
}

//7. Hàm chính
int main()
{
    NGAYTHANGNAM ntn;
    cout << "Nhập ngày tháng năm: " << endl;
    nhap(ntn);
    cout << endl;
    cout << "Ngày kế tiếp là: ";
    ngayKeTiep(ntn);
    xuat(ntn);
}
    


    