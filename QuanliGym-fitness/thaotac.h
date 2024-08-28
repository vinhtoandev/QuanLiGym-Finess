#include "quanli.h"
#include <iostream>
#include<conio.h>
using namespace std;


void Menu_chinh(quanli ad);
void Menu_Huanluyenvien(quanli ad, int id);
void Menu_Hocvien(quanli ad, int id);
void Menu_Admin(quanli ad);
void Dang_Nhap_Admin(quanli ad);
void Dang_Nhap_Huanluyenvien(quanli ad);
void Dang_Nhap_Hocvien(quanli ad);
void Tro_lai_Menu_Admin();
void Tro_lai_Menu_Huanluyenvien();
void Tro_lai_Menu_Hocvien();
void Tao_Tai_Khoan_Hocvien(quanli ad);
void Tao_Tai_Khoan_Huanluyenvien(quanli ad);
void Addtb(quanli ad);
void XuatTheoIdHv(quanli ad, int id);
void XuatTheoIdpt(quanli ad, int id);
void DangKiLichTap(quanli ad, int id);
void DangkiHuanLuyenVien(quanli ad, int id);
void XemThongTinHuanLuyenVien(quanli ad, int id);
void XemThongTinHocVien(quanli ad, int id);

void Addtb(quanli ad){
    system("cls");
    ad.showtb();
    cout<<"Nhap thong tin thiet bi:\n";
    int id;
    cout<<"Nhap ID:";cin>>id;
    if(ad.kiemtraIdtb(id)){
        thietbi tb;
        tb.setId(id);
        tb.nhap();
        ad.addtb(tb);
    }
    else{
        cout<<"ID khong hop le \n";
        cout<<"[1] Nhap lai\n";
        cout<<"[2] Thoat\n";
        int c;
        cin>>c;
        if(c==1){
            Addtb(ad);
        }
        else if (c==2){
            return;
        }
    }
}

void XemThongTinHocVien(quanli ad, int id){
    int cnt =0;
    nodept *temp = ad.searchPt(id);
    for (int i = 0; i<10; i++){
        if(temp->data.getIdhv()[i] != 0){
            cout<<ad.searchHv(temp->data.getIdhv()[i])->data<<endl;
            cnt++;
        }
    }
    if(cnt==0) cout<<"Hien khong co hoc vien nao theo hoc!\n";
}

void XemThongTinHuanLuyenVien(quanli ad, int id){
    if(ad.searchHv(id)->data.getIdpt()==0){
        cout<<"Chua dang ki huan luyen vien\n";
        return;
    }
    // ad.xuattheoidpt(ad.searchHv(id)->data.getIdpt());
    cout<<ad.searchPt(ad.searchHv(id)->data.getIdpt())->data;
}
void DangkiHuanLuyenVien(quanli ad, int id){
    ad.showpt();
    int idpt;
    cout<<"Nhap id cua huan luyen vien ban muon hoc: ";
    cin>>idpt;
    if(ad.getIdpt(idpt)){
        nodehv *hv = ad.searchHv(id);
        nodept *pt = ad.searchPt(hv->data.getIdpt());
        if(hv->data.getIdpt() != 0){
            for (int i=0;i<10;i++){
                if(pt->data.getIdhv()[i] == hv->data.getId()){
                    pt->data.getIdhv()[i] = 0;
                    break;
                }
            }
            hv->data.dangkihuanluyenvien(idpt);
            nodept *temp = ad.searchPt(hv->data.getIdpt());
            for (int i=0;i<10;i++){
                if(temp->data.getIdhv()[i] == 0){
                    temp->data.getIdhv()[i] = id;
                    break;
                }
            }
            cout<<"ban da dang ki thanh cong.";   
        }
        else{
            hv->data.dangkihuanluyenvien(idpt);
            nodept *temp = ad.searchPt(hv->data.getIdpt());
            for (int i=0;i<10;i++){
                if(temp->data.getIdhv()[i] == 0){
                    temp->data.getIdhv()[i] = id;
                    break;
                }
            }
            cout<<"ban da dang ki thanh cong.";
        }
        
    }
    else{
        cout<<"id khong hop le moi ban nhap lai:";
        int option ;
        cout<<"[1] Nhap lai:\n";
        cout<<"[2] Thoat\n";
        cout<<"Lua chon: ";
        cin>>option;
        if(option == 1){
            DangkiHuanLuyenVien(ad,id);
        }
        else{
            return;
        }
    }
    return;
}


void DangKiLichTap(quanli ad, int id){
    nodehv *temp = ad.searchHv(id);
    temp->data.dangkilichtap();
}

void XuatTheoIdHv(quanli ad, int id){
    nodehv* temp = ad.searchHv(id);
    temp->data.show();
    cout<<endl;
}
void XuatTheoIdpt(quanli ad, int id){
    nodept *temp = ad.searchPt(id);
    temp->data.show();
}

void Tro_lai_Menu_Admin(){
    int option ;
    cout<<"Bam [0] de tro lai MENU ADMIN: ";
    while (cin>>option) {
        if (option==0) {
            break;
        }else{
            system("cls");
            cout<<"Khong hop le, vui long nhap lai : ";
        }
    }
}
void Tro_lai_Menu_Huanluyenvien(){
    int option ;
    cout<<"\nBam [0] de tro lai MENU HUAN LUYEN VIEN: ";
    while (cin>>option) {
        if (option==0) {
            break;
        }else{
            system("cls");
            cout<<"Khong hop le, vui long nhap lai: ";
        }
    }
}
void Tro_lai_Menu_Hocvien(){
    int option ;
    cout<<"\nBam [0] de tro lai MENU HOC VIEN: ";
    while (cin>>option) {
        if (option==0) {
            break;
        }else{
            system("cls");
            cout<<"Khong hop le, vui long nhap lai: ";
        }
    }
}
void Tao_Tai_Khoan_Hocvien(quanli ad){
    hocvien hv;
    int id;
    do{
        cout<<"Nhap thong tin hoc vien: "<<endl;
        cout<<"Nhap id: ";
        cin>>id;
        if(ad.kiemtraIdhv(id) == 0){
            cout<<"Id nay da ton tai moi ban nhap lai"<<endl;
        }
        else{
            hv.setId(id);
            hv.nhap();
        }
    }while(ad.kiemtraIdhv(id)==0);
    system("cls");
    ad.addhv(hv);
    cout<<"Tao thanh cong tai khoan: "<<hv.getId()<<endl;
}
void Tao_Tai_Khoan_Huanluyenvien(quanli ad){
    huanluyenvien pt;
    int id;
    do{
        cout<<"Nhap thong tin huan luyen vien: "<<endl;
        cout<<"Nhap ID: ";
        cin>>id;
        if(ad.kiemtraIdpt(id) == 0){
            cout<<"Id nay da ton tai moi ban nhap lai"<<endl;
        }
        else{
            pt.setId(id);
            pt.nhap();
        }
    }while(ad.kiemtraIdpt(id) == 0);
    system("cls");
    ad.addpt(pt);
    cout<<"Tao thanh cong tai khoan: "<<pt.getId()<<endl;
}
void Menu_Admin(quanli ad){
    system("cls");
    int option;
    cout<<"MENU ADMIN"<<endl;
    cout<<"-----------\n";
    cout<<"[1] Xem danh sach tai khoan\n";
    cout<<"[2] Them tai khoan\n";
    cout<<"[3] Xoa tai khoan\n";
    cout<<"[4] Update tai khoan\n";
    cout<<"[5] Xem danh sach thiet bi\n";
    cout<<"[6] Them thiet bi\n";
    cout<<"[7] Xoa thiet bi\n";
    cout<<"[8] Update thiet bi \n";
    cout<<"[9] Dang xuat\n";
    cout<<"Nhap lua chon :";
    cin>>option;
    switch(option){
        case 1:{
            system("cls");
            int luachon;
            cout<<"[1] Xem danh sach tai khoan hoc vien\n";
            cout<<"[2] Xem danh sach tai khoan huan luyen vien\n";
            cout<<"nhap lua chon:";
            cin>>luachon;
            if(luachon == 1){
                system("cls");
                ad.showhv();
                cout<<"[1] xem chi tiet\n";
                cout<<"[2] Thoat\n";
                int lc;
                cout<<"Nhap lua chon:";
                cin>>lc;
                if(lc == 1){
                    while(1){
                        int id;
                        cout<<"Nhap ID can xem:";cin>>id;
                        if(ad.getIdhv(id)){
                            system("cls");
                            cout<<"Thong tin huan luyen vien dang hoc:\n";
                            XemThongTinHuanLuyenVien(ad,id);
                            Tro_lai_Menu_Admin();
                            break;
                        }
                        else{
                            cout<<"ID khong hop le !\n";
                            int c;
                            cout<<"[1] Nhap lai\n";
                            cout<<"[2] Thoat\n";
                            cin>>c;
                            if(c==1){
                                continue;
                            }
                            else{
                                break;
                            }
                        }

                    }
                }
            }
            else if(luachon == 2){
                system("cls");
                ad.showpt();
                cout<<"[1] xem chi tiet\n";
                cout<<"[2] Thoat\n";
                int lc;
                cout<<"Nhap lua chon:";
                cin>>lc;
                if(lc==1){
                    while(1){
                        int id;
                        cout<<"Nhap ID can xem:";cin>>id;
                        if(ad.getIdpt(id)){
                            system("cls");
                            cout<<"Thong tin nhung hoc vien dang day la:\n";
                            XemThongTinHocVien(ad,id);
                            Tro_lai_Menu_Admin();
                            Menu_Admin(ad);
                        }
                        else{
                            cout<<"ID khong hop le !\n";
                            int c;
                            cout<<"[1] Nhap lai\n";
                            cout<<"[2] Thoat\n";
                            cin>>c;
                            if(c==1){
                                continue;
                            }
                            else{
                                Menu_Admin(ad);
                            }
                        }
                    }
                }
            }
            else{
                cout<<"lua chon cua ban khong hop le\n";
                Tro_lai_Menu_Admin();
                Menu_Admin(ad);
            }
            Menu_Admin(ad);
        }
        break;
        case 2:{
            system("cls");
            int luachon;
            cout<<"[1] Tao tai khoan hoc vien\n";
            cout<<"[2] Tao tai khoan huan luyen vien\n";
            cout<<"nhap lua chon:";
            cin>>luachon;
            if(luachon == 1){
                system("cls");
                ad.showhv();
                Tao_Tai_Khoan_Hocvien(ad);
                ad.outputfilehv();
            }
            else if(luachon == 2){
                system("cls");
                ad.showpt();
                Tao_Tai_Khoan_Huanluyenvien(ad);
                ad.outputfilept();
            }
            else{
                cout<<"lua chon cua ban khong hop le\n";
                Tro_lai_Menu_Admin();
                Menu_Admin(ad);
            }
            Tro_lai_Menu_Admin();
            Menu_Admin(ad);
            break;
        }
        case 3:{
            system("cls");
            int luachon;
            cout<<"[1] Xoa tai khoan hoc vien\n";
            cout<<"[2] Xoa tai khoan huan luyen vien\n";
            cin>>luachon;
            if(luachon == 1){
                system("cls");
                ad.showhv();
                ad.removehv();
                ad.outputfilehv();
                ad.outputfilept();
            }
            else if(luachon == 2){
                system("cls");
                ad.showpt();
                ad.removept();
                ad.outputfilehv();
                ad.outputfilept();
            }
            else{
                cout<<"lua chon cua ban khong hop le\n";
                Tro_lai_Menu_Admin();
                Menu_Admin(ad);
            }
            Tro_lai_Menu_Admin();
            Menu_Admin(ad);
        }
            break;
        case 4:{
            system("cls");
            int luachon;
            cout<<"[1] Update Hoc vien\n";
            cout<<"[2] Update Huan luyen vien\n";
            cin>>luachon;
            if(luachon == 1){
                ad.updatehv();
                ad.outputfilehv();
            }
            else if(luachon == 2){
                ad.updatept();
                ad.outputfilept();
            }
            Tro_lai_Menu_Admin();
            Menu_Admin(ad);
        }
            break;
        case 5:{
            system("cls");
            ad.showtb();
            Tro_lai_Menu_Admin();
            Menu_Admin(ad);
        }
            break;
        case 6:{
            Addtb(ad);
            ad.outputfiletb();
            Tro_lai_Menu_Admin();
            Menu_Admin(ad);
        }
            break;
        case 7:{
            system("cls");
            ad.showtb();
            ad.removetb();
            ad.outputfiletb();
            Tro_lai_Menu_Admin();
            Menu_Admin(ad);
        }
            break;
        case 8:{
            system("cls");
            ad.showtb();
            ad.updatetb();
            ad.outputfiletb();
            Tro_lai_Menu_Admin();
            Menu_Admin(ad);
        }
            break;
        case 9:break;
        default:
            system("cls");
            cout<<"Lua chon khong hop le, tro ve Menu admin\n";
            Tro_lai_Menu_Admin();
            Menu_Admin(ad);
            break;
    }
}
#include <iostream>
#include <conio.h> // Thư viện này để sử dụng _getch() trong Windows

void Dang_Nhap_Admin(quanli ad){
    system("cls");
    std::string user;
    std::string pass;
    int option;
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "                       DANG NHAP ADMIN                       " << std::endl;
    std::cout << "=============================================================" << std::endl;
    while (true){
        std::cout << "User: "; std::cin >> user;

        // Ẩn mật khẩu khi nhập
        std::cout << "Mat Khau: ";
        char ch;
        pass = "";
        while ((ch = _getch()) != '\r') { // Dừng khi người dùng nhấn Enter
            if (ch == '\b') { // Xử lý khi người dùng nhấn Backspace
                if (pass.length() > 0) {
                    pass.pop_back();
                    std::cout << "\b \b"; // Xóa ký tự và dấu *
                }
            } else {
                pass.push_back(ch);
                std::cout << '*'; // In ra dấu *
            }
        }
        std::cout << std::endl;

        if ((user == "admin" && pass == "000000") ||
            (user == "admin1" && pass == "000000") ||
            (user == "admin2" && pass == "000000")){
            Menu_Admin(ad); 
            break;
        }
        else{
            system("cls");
            std::cout << "Sai User hoac Mat Khau. Vui long chon:\n";
            std::cout << "[1] Nhap lai" << std::endl;
            std::cout << "[2] Tro ve" << std::endl;
            std::cin >> option;
            switch (option) {
                case 1: continue;
                case 2: return;
                default:
                    system("cls");
                    std::cout << "Lua chon khong hop le, tro ve Menu chinh\n";
                    system("pause");
                    return;
            }
        }
    }
}


void Menu_Hocvien(quanli ad, int id){
    system("cls");
    int option;
    cout<<"MENU HOC VIEN"<<endl;
    cout<<"---------------------------------------------\n";
    cout<<"[1] Xem thong tin tai khoan\n";
    cout<<"[2] Dang ki lich tap\n";
    cout<<"[3] Dang ki huan luyen vien\n";
    cout<<"[4] Xem thong tin huan luyen vien dang theo hoc\n";
    cout<<"[5] Doi PIN\n";
    cout<<"[6] Xem danh sach thiet bi\n";
    cout<<"[7] Lien he tro giup\n";
    cout<<"[8] Dang xuat\n";
    cout<<"Nhap lua chon: ";
    cin>>option;
    switch (option){
        case 1:{
            system("cls");
            XuatTheoIdHv(ad,id);
            Tro_lai_Menu_Hocvien();
            Menu_Hocvien(ad,id);
        }
            break;
        case 2:{
            system("cls");
            DangKiLichTap(ad,id);
            ad.outputfilehv();
            Tro_lai_Menu_Hocvien();
            Menu_Hocvien(ad,id);
        }
            break;
        case 3:{
            system("cls");
            DangkiHuanLuyenVien(ad,id);
            ad.outputfilehv();
            ad.outputfilept();
            Tro_lai_Menu_Hocvien();
            Menu_Hocvien(ad,id);
        }
            break;
        case 4:{
            system("cls");
            XemThongTinHuanLuyenVien(ad,id);
            Tro_lai_Menu_Hocvien();
            Menu_Hocvien(ad,id);
        }
            break;
        case 5:{
            system("cls");
            nodehv* temp = ad.searchHv(id);
            int pin;
            cout<<"Nhap ma PIN moi:";
            cin>>pin;
            temp->data.setPin(pin);
            cout<<"Doi ma PIN thanh cong";
            ad.outputfilehv();
            Tro_lai_Menu_Hocvien();
            Menu_Hocvien(ad,id);
        }
            break;
        case 6:{
            system("cls");
            ad.showtb();
            Tro_lai_Menu_Hocvien();
            Menu_Hocvien(ad,id);
        }
        case 7:{
            system("cls");
            cout<<"https://www.facebook.com/profile.php?id=100028061493956"<<endl;
            cout<<"https://www.facebook.com/nhatsii512"<<endl;
            cout<<endl;
            Tro_lai_Menu_Hocvien();
            Menu_Hocvien(ad,id);
        }
            break;
        case 8:{
            break;
        }
        default:{
            system("cls");
            cout<<"Lua chon khong hop le\n";
            Tro_lai_Menu_Hocvien();
            Menu_Hocvien(ad,id);
            break;
        }
    }
}
void Menu_Huanluyenvien(quanli ad, int id){
    system("cls");
    int option;
    cout<<"MENU HUAN LUYEN VIEN"<<endl;
    cout<<"---------------------------------------------\n";
    cout<<"[1] Xem thong tin tai khoan\n";
    cout<<"[2] Xem hoc vien dang theo hoc\n";
    cout<<"[3] Doi PIN\n";
    cout<<"[4] Xem danh sach thiet bi\n";
    cout<<"[5] Dang xuat\n";
    cout<<"Nhap lua chon: ";
    cin>>option;
    switch(option){
        case 1:{
            system("cls");
            XuatTheoIdpt(ad, id);
            Tro_lai_Menu_Huanluyenvien();
            Menu_Huanluyenvien(ad,id);
        }
        break;
        case 2:{
            system("cls");
            XemThongTinHocVien(ad,id);
            Tro_lai_Menu_Huanluyenvien();
            Menu_Huanluyenvien(ad,id);
        }
            break;
        case 3:{
            system("cls");
            nodept *temp = ad.searchPt(id);
            int pin;
            cout<<"Nhap ma PIN moi:";
            cin>>pin;
            temp->data.setPin(pin);
            cout<<"Doi ma PIN thanh cong";
            ad.outputfilept();
            Tro_lai_Menu_Huanluyenvien();
            Menu_Huanluyenvien(ad,id);
        }
            break;
        case 4:{
            system("cls");
            ad.showtb();
            Tro_lai_Menu_Huanluyenvien();
            Menu_Huanluyenvien(ad,id);
        }
        case 5:{
            break;
        }
        default:{
            system("cls");
            cout<<"Lua chon khong hop le\n";
            Tro_lai_Menu_Huanluyenvien();
            Menu_Huanluyenvien(ad,id);
            break;
        }
    }
}
void Dang_Nhap_Huanluyenvien(quanli ad){
    system("cls");
    cout << "-------------------------------------------------------------" << endl;
    cout << "                         DANG NHAP USER                      " << endl;
    cout << "=============================================================" << endl;
    int id;
    cout << "ID: "; cin >> id;
    
    if (ad.searchPt(id)->data.getId()){
        int pin;
        cout << "PIN: ";
        
        // Ẩn mật khẩu khi nhập
        char ch;
        string enteredPin = "";
        while ((ch = _getch()) != '\r') { // Dừng khi người dùng nhấn Enter
            if (ch == '\b') { // Xử lý khi người dùng nhấn Backspace
                if (enteredPin.length() > 0) {
                    enteredPin.pop_back();
                    cout << "\b \b"; // Xóa ký tự và dấu *
                }
            } else {
                enteredPin.push_back(ch);
                cout << '*'; // In ra dấu *
            }
        }
        cout << endl;

        pin = stoi(enteredPin); // Chuyển đổi chuỗi thành số nguyên để so sánh

        if (ad.searchPt(id)->data.getPin() == pin) {
            Menu_Huanluyenvien(ad, id);
        } else {
            system("cls");
            int option;
            cout << "Sai Pin! \n";
            cout << "Bam [1] de dang nhap lai \n";
            cout << "Bam [0] de tro ve Menu Chinh \n";
            cout << "Nhap lua chon : ";
            cin >> option;
            switch (option) {
                case 1:
                    Dang_Nhap_Huanluyenvien(ad);
                    return;
                case 0: return;
                default:
                    system("cls");
                    cout << "Lua chon khong hop le, tro ve Menu Chinh\n";
                    system("pause");
                    return;
            }
        }
    } else {
        system("cls");
        int option;
        cout<<"ID khong hop le!\n";
        cout<<"Bam [1] de dang nhap lai \n";
        cout<<"Bam [0] de tro ve Menu Chinh \n";
        cout<<"Nhap lua chon : ";
        cin>>option;
        switch (option) {
            case 1:
                Dang_Nhap_Huanluyenvien(ad);
                return;
            case 0: return;
            default:
                system("cls");
                cout<<"Lua chon khong hop le, tro ve Menu Chinh \n";
                 system("pause");
                return;
        }
    }
}


void Dang_Nhap_Hocvien(quanli ad){
    system("cls");
    cout << "-------------------------------------------------------------" << endl;
    cout << "                         DANG NHAP USER                      " << endl;
    cout << "=============================================================" << endl;
    int id;
    cout << "ID: "; cin >> id;
    
    if (ad.searchHv(id)->data.getId()){
        int pin;
        cout << "PIN: ";
        
        // Ẩn mật khẩu khi nhập
        char ch;
        string enteredPin = "";
        while ((ch = _getch()) != '\r') { // Dừng khi người dùng nhấn Enter
            if (ch == '\b') { // Xử lý khi người dùng nhấn Backspace
                if (enteredPin.length() > 0) {
                    enteredPin.pop_back();
                    cout << "\b \b"; // Xóa ký tự và dấu *
                }
            } else {
                enteredPin.push_back(ch);
                cout << '*'; // In ra dấu *
            }
        }
        cout << endl;

        pin = stoi(enteredPin); // Chuyển đổi chuỗi thành số nguyên để so sánh

        if (ad.searchHv(id)->data.getPin() == pin) {
            Menu_Hocvien(ad, id);
        } else {
            system("cls");
            int option;
            cout << "Sai Pin! \n";
            cout << "Bam [1] de dang nhap lai \n";
            cout << "Bam [0] de tro ve Menu Chinh \n";
            cout << "Nhap lua chon : ";
            cin >> option;
            switch (option) {
                case 1:
                    Dang_Nhap_Hocvien(ad);
                    return;
                case 0: return;
                default:
                    system("cls");
                    cout << "Lua chon khong hop le, tro ve Menu Chinh\n";
                    system("pause");
                    return;
            }
        }
    } else {
        system("cls");
        int option;
        cout<<"ID khong hop le!\n";
        cout<<"Bam [1] de dang nhap lai \n";
        cout<<"Bam [0] de tro ve Menu Chinh \n";
        cout<<"Nhap lua chon : ";
        cin>>option;
        switch (option) {
            case 1:
                Dang_Nhap_Hocvien(ad);
                return;
            case 0: return;
            default:
                system("cls");
                cout<<"Lua chon khong hop le, tro ve Menu Chinh \n";
                 system("pause");
                return;
        }
    }
}


void Menu_chinh(quanli ad){
    system("cls");
    int option=0;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"|                 Quan ly phong GYM-FITNESS                  |"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"[1] DANG NHAP ADMIN\n";
    cout<<"[2] DANG NHAP HUAN LUYEN VIEN\n";
    cout<<"[3] DANG NHAP HOC VIEN\n";
    cout<<"[4] DONG CHUONG TRINH\n";
    cout<<"Chon chuc nang : ";
    cin>>option;
    switch (option) {
        case 1:
            Dang_Nhap_Admin(ad);
            break;
        case 2:
            Dang_Nhap_Huanluyenvien(ad);
            break;
        case 3:
            Dang_Nhap_Hocvien(ad);
            break;
        case 4:
            return;
        default:
            system("cls");
            cout<<"Lua chon khong hop le!! Vui long chon lai! \n";
            system("pause");
            break;
    }
    Menu_chinh(ad);
}