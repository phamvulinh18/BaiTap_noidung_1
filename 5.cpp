#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class MayTinh;
class HangSX
{
private:
    string ten_hang_sx;
    string quoc_gia;
    string ten_giam_doc;
public:
    void nhap();
    void xuat();
    friend class MayTinh;
    string get_hangsx();
    // friend void nhanhieu(MayTinh *a , int n);
};
string HangSX::get_hangsx()
{
    return ten_hang_sx;
}
class CauHinh
{
private:
    float tocdo_cpu;
    string dung_luong;
    int dung_luong_HDD;
public:
    void nhap();
    void xuat();
    friend class MayTinh;
    string get_dungluong();
};
string CauHinh::get_dungluong()
{
    return dung_luong;
}
class MayTinh
{
private:
    HangSX x;
    string nhan_hieu;
    int nam_sx;
    int kich_thuoc;
    CauHinh y;
    int n;
public:
    void nhap();
    void xuat();
    friend class CauHinh;
    friend class HangSX;
    string get_nhanhieu();
    friend void danhsach( MayTinh *a , int n);
    friend void nhanhieu(MayTinh *a , int n);
};
string MayTinh::get_nhanhieu()
{
    return nhan_hieu;
}

void HangSX::nhap()
{
    cout <<"\n-Nhap ten hang sx: ";                 fflush(stdin);          getline(cin , ten_hang_sx);
    cout <<"\n-Nhap ten quoc gia: ";                fflush(stdin);          getline(cin , quoc_gia);
    cout <<"\n-Nhap ten giam doc: ";                fflush(stdin);          getline(cin , ten_giam_doc);
}
void HangSX::xuat()
{
    cout << ten_hang_sx << quoc_gia << ten_giam_doc << endl;
}
void CauHinh::nhap()
{
    cout <<"\n-Nhap toc do CPU: ";                  cin >> tocdo_cpu;
    cout <<"\n-Nhap dung luong: ";                  fflush(stdin);             getline(cin , dung_luong);
    cout <<"\n-Nhap dung luong HDD: ";              cin >> dung_luong_HDD;
}
void CauHinh::xuat()
{
    cout << tocdo_cpu << dung_luong << dung_luong_HDD << endl;
}
void MayTinh::nhap()
{
        x.nhap();
        cout <<"\n-Nhap ten nhan hieu: ";               fflush(stdin);             getline(cin, nhan_hieu);
        cout <<"\n-Nhap nam san xuat: ";                cin >> nam_sx;
        cout <<"\n-Nhap kich thuoc: ";                  cin >> kich_thuoc;
        y.nhap();
}
void MayTinh::xuat()
{
    cout << x.ten_hang_sx << setw(25) << x.quoc_gia << setw(23) << x.ten_giam_doc << setw(23) << nhan_hieu << setw(20) << nam_sx << setw(20) << kich_thuoc << setw(20) << y.tocdo_cpu << setw(20) << y.dung_luong << setw(20) << y.dung_luong_HDD << endl;
}
void  danhsach(MayTinh *a , int n)
{
    cout <<"\tMAY CO DUNG LUONG 3GB"<< endl;
    cout << "Hang san xuat" << setw(20) << "Quoc gia" << setw(20) << "Giam doc" << setw(20) << "Nhan hieu" << setw(20) << "Nam san xuat" << setw(20) << "Kich thuoc" << setw(20) << "Toc do CPU" << setw(20) << "Dung luong ram" << setw(20) << "Dung luong HDD" << endl;
    for(int i = 0 ; i < n; i++)
    {
        if(a[i].y.get_dungluong() == "3GB")
        {
            a[i].xuat();
            break;
        }
        else
        {
            cout << "Khong co Hang nao co dung luong 3GB"<< endl;
        }
    }
}
void nhanhieu(MayTinh *a , int n)
{
    cout << "\tHang San Xuat Cua May Tinh Dell Aspirion "<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i].get_nhanhieu() == "Dell Aspirion")
        {
          cout << a[i].x.get_hangsx() << endl;
            break;
        }
        else{
            cout <<"Khong co may tinh nao co hang nay!!!!"<<endl;
        }
    }
    cout << "\tThong Tin Cua May Tinh Dell Aspirion " << endl;
    cout << "Hang san xuat" << setw(20) << "Quoc gia" << setw(20) << "Giam doc" << setw(20) << "Nhan hieu" << setw(20) << "Nam san xuat" << setw(20) << "Kich thuoc" << setw(20) << "Toc do CPU" << setw(20) << "Dung luong ram" << setw(20) << "Dung luong HDD" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        a[i].xuat();
    }
}
int main()
{
    MayTinh *a;
    int n;
    cout << "Nhap so luong may tinh :" ; cin >> n;
    a = new MayTinh[n];
    for(int i = 0 ; i < n ; i++)
    {
        cout << "\n-Nhap Thong Tin may thu " << i + 1 << endl;
        a[i].nhap();
        cout << endl;
    }
    cout << "Hang san xuat" << setw(20) << "Quoc gia" << setw(20) << "Giam doc" << setw(20) << "Nhan hieu" << setw(20) << "Nam san xuat" << setw(20) << "Kich thuoc" << setw(20) << "Toc do CPU" << setw(20) << "Dung luong ram" << setw(20) << "Dung luong HDD" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        a[i].xuat();
        cout << endl;
    }
    danhsach(a,n);
    cout << endl;
    nhanhieu(a ,n);

}