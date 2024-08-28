#include "thietbi.h"
#include<iomanip>
void thietbi::nhap(){
    cin.ignore();
    cout<<"nhap ten thiet bi: ";
    getline(cin, tentb);
    cout<<"nhap so luong: ";
    cin>>soluong;
    cout<<"Nhap so luong hong:";
    cin>>slhong;
    cout<<"nhap ngay nhap thiet bi:\n";
    string ngay,thang,nam;
    cout<<"nhap ngay : ";cin>>ngay;
    cout<<"nhap thang: ";cin>>thang;
    cout<<"nhap nam ";cin>>nam;
    ngaynhap=ngay + "/" + thang + "/" + nam;
}
void thietbi::show(){
    cout<<"ID: "<<id<<setw(20)<<"Tentb: "<<tentb<<"\t\tSo luong: "<<soluong<<"\t\tSlhong: "<<slhong<<"\tNgaynhap: "<<ngaynhap<<endl;
}
int thietbi::getId(){
    return this->id;
}
int thietbi::getSoluong(){
    return this->soluong;
}
int thietbi::getSlhong(){
    return this->slhong;
}
string thietbi::getTentb(){
    return this->tentb;
}
string thietbi::getNgaynhap(){
    return this->ngaynhap;
}
void thietbi::setId(int id){
    this->id=id;
}
void thietbi::setSlhong(int slhong){
    this->slhong = slhong;
}
void thietbi::setSoluong(int soluong){
    this->soluong = soluong;
}
void thietbi::setTentb(string tentb){
    this->tentb = tentb;
}
void thietbi::setNgaynhap(string ngaynhap){
    this->ngaynhap = ngaynhap;
}