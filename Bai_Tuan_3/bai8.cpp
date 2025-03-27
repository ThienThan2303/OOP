#include<iostream>
using namespace std;

//1. Khai báo lớp nhanVienVanPhong
class cNhanVienSX
{
    private:
        string maNV;
        string hoTen;
        string ngaySinh;
        int sanPham;
        int donGia;
        int tuoi;
    public:
        void nhap();
        void xuat();
        int tinhLuong();
        int getTuoi();
};

//2. Định nghĩa hàm nhập
void cNhanVienSX::nhap()
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
    cout << "Nhập số sản phẩm: ";
    cin >> sanPham;
    cin.ignore();
    cout << "Nhập đơn giá: ";
    cin >> donGia;
    cin.ignore();
    cout << "Nhập tuổi: ";
    cin >> tuoi;
    cin.ignore();
}

//3. Định nghĩa hàm xuất
void cNhanVienSX::xuat()
{
    cout << "Mã nhân viên: " << maNV << endl;
    cout << "Họ tên: " << hoTen << endl;
    cout << "Ngày sinh: " << ngaySinh << endl;
    cout << "Tuổi: " << tuoi << endl;
    cout << "Lương: " << tinhLuong() << endl;
}

//4. Định nghĩa hàm lấy lương thấp nhất
int cNhanVienSX::tinhLuong()
{
    return sanPham * donGia;
}
void timNhanVienLuongThapNhat(cNhanVienSX ds[], int n) {
    int minLuong = ds[0].tinhLuong();
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].tinhLuong() < minLuong) {
            minLuong = ds[i].tinhLuong();
            index = i;
        }
    }
    cout << "------Nhân viên có lương thấp nhất------" << endl;
    ds[index].xuat();
}

//5. Định nghĩa hàm lấy tuổi cao nhất
int cNhanVienSX::getTuoi()
{
    return tuoi;
}
void timNhanVienTuoiCaoNhat(cNhanVienSX ds[], int n) {
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
int tinhTongLuong(cNhanVienSX ds[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ds[i].tinhLuong();
    }
    return sum;
}

//7. Sắp xếp nhân viên tăng dần theo lương
void sapXepTangDanTheoLuong(cNhanVienSX ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].tinhLuong() > ds[j].tinhLuong()) {
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
    cNhanVienSX *ds = new cNhanVienSX[soLuongNhanVien];
    for (int i = 0; i < soLuongNhanVien; i++) {
        cout << "Nhân viên thứ " << i + 1 << endl;
        ds[i].nhap();
    }
    cout << "------Thông tin nhân viên văn phòng------" << endl;
    for (int i = 0; i < soLuongNhanVien; i++) {
        cout << "Nhân viên thứ " << i + 1 << endl;
        ds[i].xuat();
    }
    timNhanVienLuongThapNhat(ds, soLuongNhanVien);
    timNhanVienTuoiCaoNhat(ds, soLuongNhanVien);
    cout << "\n------Tổng lương công ty phải trả------ " << endl << tinhTongLuong(ds, soLuongNhanVien);
    sapXepTangDanTheoLuong(ds, soLuongNhanVien);
    return 1;
}