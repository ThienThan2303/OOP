#include<iostream>
using namespace std;

//1. Khai báo lóp thí sinh
class cCandidate
{
    private: 
        string ma;
        string hoTen;
        string ngaySinh;
        int diemToan;
        int diemAnh;
        int diemVan;
        int tongDiem;
    public:
        void nhap();
        void xuat();
        int gettongDiem();   
};

//2. Định nghĩa hàm nhập
void cCandidate::nhap()
{
    cout << "Nhập mã thí sinh: ";
    cin >> ma;
    cin.ignore();
    cout << "Nhập họ tên: ";
    cin >> hoTen;
    cin.ignore();
    cout << "Nhập ngày sinh: ";
    cin >> ngaySinh;
    cin.ignore();
    cout << "Nhập điểm toán: ";
    cin >> diemToan;
    cin.ignore();
    cout << "Nhập điểm anh: ";
    cin >> diemAnh;
    cin.ignore();
    cout << "Nhập điểm văn: ";
    cin >> diemVan;
    cin.ignore();
}

//3. Định nghĩa hàm xuất
void cCandidate::xuat()
{
    cout << "Mã thí sinh: " << ma << endl;
    cout << "Họ tên: " << hoTen << endl;
    cout << "Ngày sinh: " << ngaySinh << endl;
    cout << "Điểm toán: " << diemToan << endl;
    cout << "Điểm anh: " << diemAnh << endl;
    cout << "Điểm văn: " << diemVan << endl;
}

//4. Định nghĩa hàm lấy tổng điểm
int cCandidate::gettongDiem()
{
    return diemToan + diemAnh + diemVan;
}
void xuatTongDiemLonHon15(cCandidate ds[], int n)
{
    cout << "\n------Danh sách thí sinh có tổng điểm lớn hơn 15------" << endl;
    for (int i = 0; i < n; i++) {
        if (ds[i].gettongDiem() > 15) {
            cout << "Thí sinh thứ " << i + 1 << endl;
            ds[i].xuat();
        }
    }
}

//5. Cho biết thí sinh tổng điểm cao nhất
void timThiSinhTongDiemCaoNhat(cCandidate ds[], int n) {
    int maxTongDiem = ds[0].gettongDiem();
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].gettongDiem() > maxTongDiem) {
            maxTongDiem = ds[i].gettongDiem();
            index = i;
        }
    }
    cout << "\n------Thí sinh có tổng điểm cao nhất------" << endl;
    ds[index].xuat();
}

//6. Sắp xếp danh sách thí sinh giảm dần theo tổng điểm
void sapXepThiSinh(cCandidate ds[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(ds[i].gettongDiem() < ds[j].gettongDiem()){
                swap(ds[i], ds[j]);
            }
        }
    }
    cout << "\n------Danh sách thí sinh sau khi sắp xếp------" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Thí sinh thứ " << i + 1 << endl;
        ds[i].xuat();
    }
}

//7. Hàm chính
int main()
{
    cCandidate ds[100];
    int soLuongThiSinh;
    cout << "Nhập số lượng thí sinh: ";
    cin >> soLuongThiSinh;
    cin.ignore();
    for(int i = 0; i < soLuongThiSinh; i++)
    {
        cout << "Nhập thông tin thí sinh thứ " << i + 1 << endl;
        ds[i].nhap();
    }
    cout << "------Danh sách thí sinh------" << endl;
    for(int i = 0; i < soLuongThiSinh; i++)
    {
        cout << "Thí sinh thứ " << i + 1 << endl;
        ds[i].xuat();
    }
    xuatTongDiemLonHon15(ds, soLuongThiSinh);
    timThiSinhTongDiemCaoNhat(ds, soLuongThiSinh);
    sapXepThiSinh(ds, soLuongThiSinh);
    return 1;
}


