#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class CongDan
{
private:
    string so_CMND;
    string ho_va_ten;
    string ngay_sinh;
    string ho_khau_thuong_tru;
public:
    void nhap();
    void xuat();
    friend class XeHoi;
    string get_ngaysinh();
    string get_hokhau();

};
string CongDan::get_hokhau()
{
    return ho_khau_thuong_tru;
}
string CongDan::get_ngaysinh()
{
    return ngay_sinh;
}
class XeHoi:public CongDan
{
private:
    string bien_so;
    string hang_xe;
    int soluong;
public:
    void nhap();
    void xuat();
    friend class CongDan;

};
void CongDan::nhap()
{
    cout <<"\n-Nhap so CMND:";              fflush(stdin);              getline(cin ,so_CMND);
    cout <<"\n-Nhap ho va ten:";            fflush(stdin);              getline(cin,ho_va_ten);
    cout <<"\n-Nhap Ngay sinh:";            fflush(stdin);              getline(cin ,ngay_sinh);
    cout <<"\n-Nhap ho khau thuong tru:";   fflush(stdin);              getline(cin ,ho_khau_thuong_tru);
}
void CongDan::xuat()
{
    cout <<"So CMND:" << setw(10) << so_CMND << endl;
    cout <<"Ho Va Ten:" << setw(10) << ho_va_ten << endl;
    cout <<"Ngay sinh:" << setw(10) << ngay_sinh << endl;
    cout <<"Ho khau thuong tru:" << setw(10) << ho_khau_thuong_tru << endl;
}
void XeHoi::nhap()
{
    CongDan::nhap();
    cout <<"\n-Nhap bien so xe:";           fflush(stdin);              getline(cin ,bien_so);
    cout <<"\n-Nhap ten hang xe:";          fflush(stdin);              getline(cin ,hang_xe);
}
void XeHoi::xuat()
{
    CongDan::xuat();
    cout << "Bien so xe:" << setw(10) << bien_so << endl;
    cout << "Ten hang xe:" << setw(10) << hang_xe << endl;
}
void check(XeHoi *a , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i].get_ngaysinh() == "1985")
        {
            a[i].xuat();
        }
    }
}
void chen(XeHoi *a, int &n, int vt,  XeHoi &sochen)
{
    for(int i = n; i > vt; i--)
    {
        a[i] = a[i - 1];
    }
    a[vt] = sochen;
    n++;
}

int main()
{
    int n;
    cout << "Nhap so luong xe:";
    cin >> n;
    cin.ignore();
    XeHoi *a = new XeHoi[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\tNhap Thong Tin thu " << i + 1 << endl;
        a[i].nhap();
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\tXuat Thong Tin thu " << i + 1 << endl;
        a[i].xuat();
        cout << endl;
    }

    cout << setw(50) << "Chu xe sinh 1985:" << endl;
    check(a, n);

    int vi_tri_chen;
    do {
        cout << "Nhap vi tri muon chen (tu 0 den " << n << "): ";
        cin >> vi_tri_chen;
    } while (vi_tri_chen < 0 || vi_tri_chen > n);
    cin.ignore();

    XeHoi newCar;
    cout << "Nhap thong tin cho xe moi:" << endl;
    newCar.nhap();
    chen(a, n, vi_tri_chen, newCar);

    cout << "Sau khi chen them xe:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\tXuat Thong Tin thu " << i + 1 << endl;
        a[i].xuat();
        cout << endl;
    }

    delete[] a;
    return 0;
}
