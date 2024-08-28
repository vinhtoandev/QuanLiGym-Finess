#ifndef HUANLUYENVIEN_H
#define HUANLUYENVIEN_H

#include<string>
#include<iostream>
// #include<hocvien.h>
using namespace std;

class huanluyenvien{
    private:
        int id,pin,gioitinh,slhv;
        string ten,sdt,ngaysinh,ngayvaolam;
        int idhv[10];
    public:
        huanluyenvien();
        friend ostream& operator<<(ostream &o, const huanluyenvien &pt); 
        void show();
        void nhap();
        int getId();
        int getPin();
        int getGioitinh();
        int getSlhv();
        int *getIdhv();
        string getTen();
        string getSdt();
        string getNgaysinh();
        string getNgayvaolam();
        void setId(int id);
        void setPin(int pin);
        void setGioitinh(int gioitinh);
        void setTen(string ten);
        void setSdt(string sdt);
        void setSlhv(int slhv);
        void setNgaysinh(string ngaysinh);
        void setNgayvaolam(string ngaydk);
        void setIdhv(int idhv[]);
        void tangslhv();
};
#endif