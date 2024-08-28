#ifndef THIETBI_H
#define THIETBI_H
#include<iostream>
#include<string>
using namespace std;

class thietbi{
    private:
        int id,soluong,slhong;
        string tentb,ngaynhap;
    public:
        void nhap();
        void show();
        int getId();
        int getSlhong();
        int getSoluong();
        string getTentb();
        string getNgaynhap();
        void setId(int id);
        void setSlhong(int slhong);
        void setSoluong(int soluong);
        void setTentb(string tentb);
        void setNgaynhap(string ngaynhap);
};
#endif