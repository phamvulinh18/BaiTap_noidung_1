#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Phieu;

class Hang
{
private:
    string ten_hang;
    float don_gia;
    int so_luong;
public:
    void nhap();
    void xuat();
    float thanh_tien();
    float get_don_gia();
    friend  void minn(Phieu a);
    friend class Phieu;
};
float Hang::get_don_gia()
{
    return don_gia;
}
float Hang::thanh_tien()
{
    return don_gia * so_luong;
}
class Phieu
{
private:
    string ma_phieu;
    string khach_hang;
    string ngay_lap;
    Hang *x;
    int n;
public:
    void nhap();
    void xuat();
    friend void minn(Phieu a);
};
void Hang::nhap()
{
    cout <<"\n-Nhap ten hang:";         fflush(stdin);          getline(cin , ten_hang);
    cout <<"\n-Nhap don gia:";                                  cin >> don_gia;
    cout <<"\n-Nhap so luong:";                                 cin >> so_luong;
}
void Hang::xuat()
{
    cout << ten_hang << setw(20) << don_gia << setw(20) << so_luong << setw(20) << thanh_tien() << endl;
}
void Phieu::nhap()
{
    cout <<"\n-Nhap ma phieu:";         fflush(stdin);          getline(cin , ma_phieu);
    cout <<"\n-Nhap ten khach hang:";   fflush(stdin);          getline(cin , khach_hang);
    cout <<"\n-Nhap ngay lap:";         fflush(stdin);          getline(cin , ngay_lap);
    cout <<"\n-Nhap so luong hang:";                            cin >> n;
    x = new Hang[n];
    for(int i = 0 ; i < n; i++)
    {
        x[i].nhap();
    }
}
void Phieu::xuat()
{
    cout << setw(10) << "Ma phieu:  " << ma_phieu << setw(30) << "Khach hang:  " << khach_hang << endl;
    cout << setw(10) << "Ngay Lap:  " << ngay_lap << endl;
    cout << "Danh muc hang hoa"<< endl; 
    cout << setw(45) << "PHIEU MUA HANG" << endl;
    cout << "Ten hang" << setw(20) << "Don gia" << setw(20) << "So luong" << setw(20) << "Thanh tien"<< endl;
    for(int i = 0 ; i < n ; i++)
    {
        x[i].xuat();
    }
}
void minn(Phieu a)
{
    int min = a.x[0].get_don_gia();
    for(int i = 0 ; i < a.n ; i++)
    {
        if(a.x[i].get_don_gia() < min)
        {
            min = a.x[i].get_don_gia();
        }
    }
    cout << "Ten hang" << setw(20) << "Don gia" << setw(20) << "So luong" << setw(20) << "Thanh tien"<< endl;
    for(int i = 0 ; i <a.n ; i++)
    {
        if(a.x[i].get_don_gia() == min)
        {
            a.x[i].xuat();
        }
    }
}
int main()
{
    Phieu a;
    int n;
    a.nhap();
    cout << endl;
    a.xuat();
    cout << endl;
    cout << "\t\tHang Hoa Co Don Gia Nho Nhat" << endl;
    minn(a);
}