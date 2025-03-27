#include<iostream>
using namespace std;

//1. Khai báo lớp nhanVienVanPhong
class cNhanVienVP
{
    private:
        string maNV;
        string hoTen;
        string ngaySinh;
        int luong;
        int tuoi;
    public:
        void nhap();
        void xuat();
        int getLuong();
        int getTuoi();
};

//2. Định nghĩa hàm nhập
void cNhanVienVP::nhap()
{
    cout << "Nhập mã nhân viên: ";
    cin >> maNV;
    cin.ignore();
    cout << "Nhập họ tên: ";
    cin >> hoTen;
    cin.ignore();
    cout << "Nhập ngày sinh: ";
    cin >> ngaySinh;
    cin.ignore();
    cout << "Nhập lương: ";
    cin >> luong;
    cin.ignore();
    cout << "Nhập tuổi: ";
    cin >> tuoi;
    cin.ignore();
}

//3. Định nghĩa hàm xuất
void cNhanVienVP::xuat()
{
    cout << "Mã nhân viên: " << maNV << endl;
    cout << "Họ tên: " << hoTen << endl;
    cout << "Ngày sinh: " << ngaySinh << endl;
    cout << "Tuổi: " << tuoi << endl;
    cout << "Lương: " << luong << endl;
}

//4. Định nghĩa hàm lấy lương cao nhất
int cNhanVienVP::getLuong()
{
    return luong;
}
void timNhanVienLuongCaoNhat(cNhanVienVP ds[], int n) {
    int maxLuong = ds[0].getLuong();
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].getLuong() > maxLuong) {
            maxLuong = ds[i].getLuong();
            index = i;
        }
    }
    cout << "------Nhân viên có lương cao nhất------" << endl;
    ds[index].xuat();
}

//5. Định nghĩa hàm lấy tuổi cao nhất
int cNhanVienVP::getTuoi()
{
    return tuoi;
}
void timNhanVienTuoiCaoNhat(cNhanVienVP ds[], int n) {
    int maxTuoi = ds[0].getTuoi();
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].getTuoi() > maxTuoi) {
            maxTuoi = ds[i].getTuoi();
            index = i;
        }
    }
    cout << "\n------Nhân viên có tuổi cao nhất------ " << endl;
    ds[index].xuat();
}

//6. Tính tổng lương công ti phải trả
int tinhTongLuong(cNhanVienVP ds[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ds[i].getLuong();
    }
    return sum;
}

//7. Sắp xếp nhân viên tăng dần theo lương
void sapXepTangDanTheoLuong(cNhanVienVP ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getLuong() > ds[j].getLuong()) {
                swap(ds[i], ds[j]);
            }
        }
    }
    cout << "\n------Danh sách nhân viên sau khi sắp xếp tăng dần theo lương------ " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nhân viên thứ " << i + 1 << endl;
        ds[i].xuat();
    }
}

//8. Hàm chính
int main()
{
   int soLuongNhanVien;
    cout << "Nhập số lượng nhân viên: ";
    cin >> soLuongNhanVien;
    cin.ignore();
    cNhanVienVP *ds = new cNhanVienVP[soLuongNhanVien];
    for (int i = 0; i < soLuongNhanVien; i++) {
        cout << "Nhân viên thứ " << i + 1 << endl;
        ds[i].nhap();
    }
    cout << "------Thông tin nhân viên văn phòng------" << endl;
    for (int i = 0; i < soLuongNhanVien; i++) {
        cout << "Nhân viên thứ " << i + 1 << endl;
        ds[i].xuat();
    }
    timNhanVienLuongCaoNhat(ds, soLuongNhanVien);
    timNhanVienTuoiCaoNhat(ds, soLuongNhanVien);
    cout << "\n------Tổng lương công ty phải trả------ " << endl << tinhTongLuong(ds, soLuongNhanVien);
    sapXepTangDanTheoLuong(ds, soLuongNhanVien);
    return 1;
}