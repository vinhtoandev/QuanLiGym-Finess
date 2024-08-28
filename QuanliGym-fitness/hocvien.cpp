#include"hocvien.h"
#include<iostream>
#include<iomanip>
using namespace std;



hocvien::hocvien(){
    for (int i=0;i<7;i++){
        this->lichtap[i] = 0;
    }
    this->idpt = 0;
}
void hocvien::show(){
    cout<<"ID: "<<id<<"\tHo ten: "<<ten<<"\tPin: "<<pin<<"\tgt: ";
    if(gioitinh == 1){
        cout<<"Nam\t";
    }
    else if(gioitinh == 1){
        cout<<"Nu\t";
    }
    cout<<"\tSDT: "<<sdt<<"\t\tngay sinh: "<<ngaysinh<<"\t\tngaydk: "<<ngaydk<<"\tngay het han: "<<ngayhethan<<setw(16)<<"IDpt:"<<idpt<<"\tlich tap: ";
    for(int i=2;i<8;i++){
        if(lichtap[i-2] == 1){
            cout<<"T"<<i<<"-";
        }
    }
    if (lichtap[6] == 1) cout<< "CN-";
    cout<<endl;
}
void hocvien::nhap(){
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
    cout<<"nhap ngay dang ki: "<<endl;
    string ngaydangki,thangdk,namdk;
    cout<<"nhap ngay: ";
    cin>>ngaydangki;
    cout<<"nhap thang: ";
    cin>>thangdk;
    cout<<"nhap nam: ";
    cin>>namdk;
    ngaydk=ngaydangki + "/" + thangdk + "/" + namdk;
    cout<<"nhap ngay hen han: "<<endl;
    string ngayhh,thanghh,namhh;
    cout<<"nhap ngay: ";
    cin>>ngayhh;
    cout<<"nhap thang: ";
    cin>>thanghh;
    cout<<"nhap nam: ";
    cin>>namhh;
    ngayhethan=ngayhh + "/" + thanghh + "/" + namhh;
    cout<<endl;
}

void hocvien::dangkilichtap(){
    cout << "Chon ngay dang ki trong tuan : " << endl;
    cout << "Chon (1)- Bo (0)" << endl;
    int i = 2;
    do {
        if (i != 8) cout << "Thu " << i << ": ";
        else cout << "Chu nhat: ";
        cin >> this->lichtap[i - 2];
        if (lichtap[i - 2] == 0 || lichtap[i - 2] == 1) i++;
    } while (i < 9);
}
void hocvien::dangkihuanluyenvien(int id){
    this->idpt = id;
}

ostream& operator << (ostream& o, const hocvien& hv){
    o<<"ID: "<<hv.id<<"\tHo ten: "<<hv.ten<<"\tGioi tinh: ";
    if(hv.gioitinh == 1){
        o<<"Nam";
    }
    else{
        o<<"Nu";
    }
    o<<"\t\tNgay sinh:"<<hv.ngaysinh<<"\tSDT:"<<hv.sdt<<"\t\tNgaydk:"<<hv.ngaydk<<"\t\tNgayhethan: "<<hv.ngayhethan<<"\t";
    o<<"Lich tap:";
    for(int i=2;i<8;i++){
        if(hv.lichtap[i-2] == 1){
            o<<"T"<<i<<"-";
        }
    }
    if(hv.lichtap[6] == 1) o<<"CN-";
    return o;
}
int hocvien::getId(){
    return this->id;
}
int hocvien::getPin(){
    return this->pin;
}
int hocvien::getGioitinh(){
    return this->gioitinh;
}
int* hocvien::getLichtap(){
    return lichtap;
}
int hocvien::getIdpt(){
    return this->idpt;
}
string hocvien::getTen(){
    return this->ten;
}
string hocvien::getSdt(){
    return this->sdt;
}
string hocvien::getNgaysinh(){
    return this->ngaysinh;
}
string hocvien::getNgaydk(){
    return this->ngaydk;
}
string hocvien::getNgayhethan(){
    return this->ngayhethan;
}
void hocvien::setId(int id){
    this->id=id;
}
void hocvien::setPin(int pin){
    this->pin=pin;
}
void hocvien::setGioitinh(int gt){
    this->gioitinh=gt;
}
void hocvien::setTen(string ten){
    this->ten=ten;
}
void hocvien::setSdt(string sdt){
    this->sdt=sdt;
}
void hocvien::setNgaysinh(string ngaysinh){
    this->ngaysinh=ngaysinh;
}
void hocvien::setNgaydk(string ngaydangki){
    this->ngaydk=ngaydangki;
}
void hocvien::setNgayhethan(string ngayhethan){
    this->ngayhethan=ngayhethan;
}
void hocvien::setLichtap(int lichtap[]){
    for (int i=0;i<7;i++){
        this->lichtap[i]=lichtap[i];
    }
}
void hocvien::setIdPt(int id){
    this->idpt = id;
}