#ifndef SINHVIEN_H
#define SINHVIEN_H
#include<string>
#include<iostream>
#include"huanluyenvien.h"
using namespace std;
class hocvien{
    private:
        int id,pin,gioitinh;
        string ten,sdt,ngaysinh,ngaydk,ngayhethan;
        int lichtap[7];
        int idpt;
    public:
        hocvien();
        friend ostream& operator<<(ostream &o, const hocvien &sv); 
        void show();
        void nhap();
        void dangkilichtap();
        void dangkihuanluyenvien(int id);
        int getId();
        int getIdpt();
        int getPin();
        int getGioitinh();
        string getTen();
        string getSdt();
        string getNgaysinh();
        string getNgaydk();
        string getNgayhethan();
        int* getLichtap();
        void setId(int id);
        void setPin(int pin);
        void setGioitinh(int gioitinh);
        void setTen(string ten);
        void setSdt(string sdt);
        void setNgaysinh(string ngaysinh);
        void setNgaydk(string ngaydk);
        void setNgayhethan(string ngayhethan);
        void setLichtap(int lichtap[]);
        void setIdPt(int id);
};
#endif
