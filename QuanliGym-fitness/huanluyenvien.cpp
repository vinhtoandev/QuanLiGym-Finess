#include "huanluyenvien.h"
#include<iostream>
using namespace std;


void huanluyenvien::show(){
    cout<<"ID: "<<id<<"\t\tHo ten: "<<ten<<"\t\tPin: "<<pin<<"\tgt: ";
    if(gioitinh == 1){
        cout<<"Nam\t";
    }
    else if(gioitinh == 0){
        cout<<"Nu\t";
    }
    int cnt=0;
    cout<<"\tSDT: "<<sdt<<"\t\tngay sinh: "<<ngaysinh<<"\t\tngay vao lam: "<<ngayvaolam<<"\t\tSo luong hoc vien:";
    for (int i=0;i<10;i++){
        if(idhv[i]!=0){
            cnt++;
        }
    }
    slhv=cnt;
    cout<<this->slhv;
    cout<<endl;
}
void huanluyenvien::nhap(){
    cin.ignore();
    cout<<"nhap ten: ";
    getline(cin, ten);
    cout<<"nhap pin: ";
    cin>>pin;
    cout<<"nhap gioi tinh : [0] nu,[1] nam :";
    cin>>gioitinh;
    cout<<"nhap sdt: ";
    cin>>sdt;
    cout<<"nhap ngay sinh:"<<endl;
    string ngay,thang,nam;
    cout<<"nhap ngay: ";
    cin>>ngay;
    cout<<"nhap thang: ";
    cin>>thang;
    cout<<"nhap nam: ";
    cin>>nam;
    ngaysinh=ngay + "/" + thang + "/" + nam;
    cout<<"nhap ngay vao lam: "<<endl;
    string ngayvl,thangvl,namvl;
    cout<<"nhap ngay: ";
    cin>>ngayvl;
    cout<<"nhap thang: ";
    cin>>thangvl;
    cout<<"nhap nam: ";
    cin>>namvl;
    ngayvaolam=ngayvl + "/" + thangvl + "/" + namvl;
    cout<<endl;
}
ostream& operator<< (ostream& o, const huanluyenvien& pt){
    o<<"ID:"<<pt.id<<"\tHo ten:"<<pt.ten<<"\tGioi tinh:";
    if(pt.gioitinh == 1){
        cout<<"Nam";
    }
    else if(pt.gioitinh == 0){
        cout<<"Nu";
    }
    o<<"\t\tNgay sinh:"<<pt.ngaysinh<<"\t\tSDT: "<<pt.sdt<<"\t\tNgay vao lam: "<<pt.ngayvaolam<<endl;
    return o;
}
huanluyenvien::huanluyenvien(){
    this->slhv = 0;
    for (int i=0;i<10;i++){
        idhv[i]=0;
    }
}
int huanluyenvien::getId(){
    return this->id;
}
int huanluyenvien::getPin(){
    return this->pin;
}
int huanluyenvien::getGioitinh(){
    return this->gioitinh;
}
int huanluyenvien::getSlhv(){
    return this->slhv;
}
int* huanluyenvien::getIdhv(){
    return this->idhv;
}
string huanluyenvien::getTen(){
    return this->ten;
}
string huanluyenvien::getSdt(){
    return this->sdt;
}
string huanluyenvien::getNgaysinh(){
    return this->ngaysinh;
}
string huanluyenvien::getNgayvaolam(){
    return this->ngayvaolam;
}
void huanluyenvien::setId(int id){
    this->id=id;
}
void huanluyenvien::setPin(int pin){
    this->pin=pin;
}
void huanluyenvien::setGioitinh(int gt){
    this->gioitinh=gt;
}
void huanluyenvien::setTen(string ten){
    this->ten=ten;
}
void huanluyenvien::setSdt(string sdt){
    this->sdt=sdt;
}
void huanluyenvien::setSlhv(int slhv){
    this->slhv = slhv;
}
void huanluyenvien::setNgaysinh(string ngaysinh){
    this->ngaysinh=ngaysinh;
}
void huanluyenvien::setNgayvaolam(string ngayvaolam){
    this->ngayvaolam=ngayvaolam;
}
void huanluyenvien::setIdhv(int idhv[]){
    for (int i=0;i<10;i++){
        this->idhv[i] = idhv[i];
    }
}
void huanluyenvien::tangslhv(){
    this->slhv++;
}
