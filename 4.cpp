#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class NhanVien
{
private:
    string ma_nv;
    string ho_ten;
    string ngay_sinh;
    string gioi_tinh;
    string noi_sinh;
    float he_so_luong;
public:
    void nhap();
    void xuat();
    long double luong();
    string get_gioitinh();
    float get_hsluong();
};
string NhanVien::get_gioitinh()
{
    return gioi_tinh;
}
float NhanVien::get_hsluong()
{
    return he_so_luong;
}
long double NhanVien::luong()
{
    return he_so_luong * 1300;
}
void NhanVien::nhap()
{
    cout <<"\n-Nhap ma nhan vien:";             fflush(stdin);              getline(cin , ma_nv);
    cout <<"\n-Nhap ho ten nhan vien:";         fflush(stdin);              getline(cin , ho_ten);
    cout <<"\n-Nhap ngay sinh:";                fflush(stdin);              getline(cin , ngay_sinh);
    cout <<"\n-Nhap gioi tinh:";                fflush(stdin);              getline(cin ,gioi_tinh);
    cout <<"\n-Nhap noi sinh:";                 fflush(stdin);              getline(cin , noi_sinh);
    cout <<"\n-Nhap he so luong:";              cin >> he_so_luong;
}
void NhanVien ::xuat()
{
    cout <<ma_nv<<setw(20)<<ho_ten<<setw(20)<<ngay_sinh<<setw(20)<<gioi_tinh<<setw(20)<<noi_sinh<<setw(20)<<he_so_luong<<setw(20)<<luong()<< endl;
}
void dsnam(NhanVien *a , int n )
{
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i].get_gioitinh() == "Nam" && a[i].get_hsluong() >= 3.99)
        {
            a[i].xuat();
            return;
        }
        else 
        {
            cout <<"Khong co nhan vien nam nao co muc luong nay het!!"<< endl;
        }
    }
}
float tong_luong(NhanVien *a , int n)
{
    float tong = 0;
    for(int i = 0 ; i < n ;i++)
    {
        tong += a[i].luong();
    }
    return tong;
}
int main()
{
    int n;
    cout << "\n-Nhap so luong nhan vien:";          cin >> n;
    NhanVien *a = new NhanVien[n];
    for(int i = 0 ; i < n ;i ++)
    {
        a[i].nhap();
    }
    cout << endl;
    cout <<"Ma NV"<<setw(20)<<"Ho va ten"<<setw(20)<<"Ngay sinh"<<setw(20)<<"Gioi tinh"<<setw(20)<<"Noi sinh"<<setw(20)<<"HS luong"<<setw(20)<<"Luong"<< endl;
     for(int i = 0 ; i < n ;i ++)
    {
        a[i].xuat();
    }
    cout <<setw(200) <<"Tong luong theo danh sach:" << tong_luong(a,n) << endl;
    cout << setw(40) <<"DANH SACH NHAN VIEN NAM CO HE SO LUONG >= 3.99"<<endl;
    cout <<"Ma NV"<<setw(20)<<"Ho va ten"<<setw(20)<<"Ngay sinh"<<setw(20)<<"Gioi tinh"<<setw(20)<<"Noi sinh"<<setw(20)<<"HS luong"<<setw(20)<<"Luong"<< endl;
    dsnam(a,n);
}