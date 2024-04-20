#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class BenhNhan
{
private:
    string ho_va_ten;
    string gioi_tinh;
    string thoi_gian_dieutri;
public:
    void nhap();
    void xuat();
};
class Thuoc
{
private:
    string ten_thuoc;
    string don_vi_tinh;
    int so_luong;
    string lieu_luong;
public:
    void nhap();
    void xuat();
};
class Phieu
{
    string ngay_nhap_vien;
    string bac_si;
    BenhNhan y;
    Thuoc x[100];
    int n;
public:
    void nhap();
    void xuat();
    friend class BenhNhan;
    friend class Thuoc;
};
void BenhNhan ::nhap()
{
    cout <<"Nhap ho va ten:";               fflush(stdin);          getline(cin , ho_va_ten);
    cout <<"Nhap gioi tinh:";               fflush(stdin);          getline(cin , gioi_tinh);
    cout <<"Nhap thoi gian dieu tri:";      fflush(stdin);          getline(cin , thoi_gian_dieutri);
}
void BenhNhan::xuat()
{
    cout <<"Ho va ten benh nhan: " << ho_va_ten << setw(30) <<"Gioi tinh: " << gioi_tinh << endl;
    cout <<"Thoi gian dieu tri: " << thoi_gian_dieutri << endl;
}
void Thuoc::nhap()
{
    cout <<"Nhap ten thuoc:";               fflush(stdin);          getline(cin , ten_thuoc);
    cout <<"Nhap don vi tinh: ";            fflush(stdin);          getline(cin , don_vi_tinh);
    cout <<"Nhap so luong: ";                                       cin >> so_luong;
    cout <<"Nhap lieu luong: ";             fflush(stdin);          getline(cin , lieu_luong);
}
void Thuoc::xuat()
{
    cout <<ten_thuoc<<setw(15) << don_vi_tinh<<setw(15)<<so_luong<<setw(30)<<lieu_luong<< endl;
}
void Phieu ::nhap()
{
    cout <<"Nhap ngay nhap vien: ";         fflush(stdin);          getline(cin , ngay_nhap_vien);
    cout <<"Nhap bac si dieu tri: ";        fflush(stdin);          getline(cin , bac_si);
    y.nhap(); 
    cout <<"Nhap so loai thuoc: "; cin >> n; 
    for(int i = 0 ;i < n ; i ++)
    {
        x[i].nhap();
    }
}
void Phieu ::xuat()
{
    cout <<"Ngay nhap vien: " << ngay_nhap_vien << setw(30) <<"Bac si dieu tri: " << bac_si << endl;
    y.xuat();
    cout <<"Danh muc nhung loai thuoc dieu tri " << endl;
     cout <<"Ten thuoc"<<setw(15) <<"Don vi tinh" <<setw(15) <<"So luong" <<setw(30) <<"Lieu luong / 1 ngay" << endl;
    for(int i = 0 ; i < n; i++)
    {
        x[i].xuat();
    }
}
int main()
{
    Phieu a;
    a.nhap();
    cout << endl;
    a.xuat();
}