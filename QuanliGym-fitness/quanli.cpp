#include "quanli.h"
#include<iostream>
using namespace std;

nodehv *makenodehv(hocvien hv){
    nodehv *newnode=new nodehv;
    newnode->data=hv;
    newnode->next=NULL;
    return newnode;
}
nodept *makenodept(huanluyenvien pt){
    nodept *newnode=new nodept;
    newnode->data=pt;
    newnode->next=NULL;
    return newnode;
}
nodetb *makenodetb(thietbi tb){
    nodetb *newnode = new nodetb;
    newnode->data = tb;
    newnode->next = NULL;
    return newnode;
}
quanli::quanli(){
    dshv=NULL;
    dspt=NULL;
    dstb=NULL;
}
void quanli::addhv(hocvien hv){
    nodehv* newnode= makenodehv(hv);
    if(dshv == NULL){
        dshv = newnode;
        return;
    }
    nodehv *temp = dshv;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void quanli::addpt(huanluyenvien pt){
    nodept* newnode= makenodept(pt);
    if(dspt == NULL){
        dspt = newnode;
        return;
    }
    nodept *temp = dspt;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void quanli::addtb(thietbi tb){
    nodetb* newnode= makenodetb(tb);
    if(dstb == NULL){
        dstb = newnode;
        return;
    }
    nodetb* temp = dstb;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;

}
void quanli::showhv(){
    nodehv *temp=dshv;
    while(temp != NULL){
        temp->data.show();
        temp=temp->next;
    }
}
void quanli::showpt(){
    nodept *temp=dspt;
    while(temp != NULL){
        temp->data.show();
        temp=temp->next;
    }
}
void quanli::showtb(){
    nodetb *temp=dstb;
    while(temp != NULL){
        temp->data.show();
        temp=temp->next;
    }
}
void quanli::inputfilehv(){
    ifstream file("danhsachhv.txt");
    if(file.fail()){
        cout<<"Failed\n";
        return;
    }
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string ho, tendem, ten;
        int id,pin,gioitinh;
        string sdt,ngaysinh,ngaydk,ngayhethan;
        int lichtap[7];
        ss>>id>>pin>>ho>>tendem>>ten>>gioitinh>>ngaysinh>>sdt>>ngaydk>>ngayhethan;
        for (int i=0;i<7;i++){
            ss>>lichtap[i];
        }
        int idpt;
        ss>>idpt;
        string hoten = ho + " " + tendem + " " + ten;
        hocvien hv;
        hv.setId(id);
        hv.setPin(pin);
        hv.setTen(hoten);
        hv.setGioitinh(gioitinh);
        hv.setNgaysinh(ngaysinh);
        hv.setSdt(sdt);
        hv.setNgaydk(ngaydk);
        hv.setNgayhethan(ngayhethan);
        hv.setLichtap(lichtap);
        hv.setIdPt(idpt);
        addhv(hv);
    }
    file.close();
} 
void quanli::inputfilept(){
    ifstream file("danhsachpt.txt");
    if(file.fail()){
        cout<<"Failed\n";
        return;
    }
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string ho, tendem, ten;
        int id,pin,gioitinh,slhv;
        string sdt,ngaysinh,ngayvaolam;
        int idhv[10];
        ss>>id>>pin>>ho>>tendem>>ten>>gioitinh>>ngaysinh>>sdt>>slhv>>ngayvaolam;
        string hoten = ho + " " + tendem + " " + ten;
        for (int i=0;i<10;i++){
            ss>>idhv[i];
        }
        huanluyenvien pt;
        pt.setId(id);
        pt.setPin(pin);
        pt.setTen(hoten);
        pt.setGioitinh(gioitinh);
        pt.setNgaysinh(ngaysinh);
        pt.setSdt(sdt);
        pt.setSlhv(slhv);
        pt.setNgayvaolam(ngayvaolam);
        pt.setIdhv(idhv);
        addpt(pt);
    }
    file.close();
}
void quanli::inputfiletb(){
    ifstream file("danhsachtb.txt");
    if(file.fail()){
        cout<<"Failed\n";
        return;
    }
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string ho, tendem, ten;
        int id,slhong,soluong;
        string ngaynhap;
        ss>>id>>ho>>tendem>>ten>>soluong>>slhong>>ngaynhap;
        string hoten = ho + " " + tendem + " " + ten;
        thietbi tb;
        tb.setId(id);
        tb.setTentb(hoten);
        tb.setSlhong(slhong);
        tb.setSoluong(soluong);
        tb.setNgaynhap(ngaynhap);
        addtb(tb);
    }
    file.close();
}
void quanli::outputfilehv(){
    ofstream file("danhsachhv.txt");
    if(dshv != NULL){
        nodehv *temp = dshv;
        while(temp != NULL){
            file<<temp->data.getId()<<"\t";
            file<<temp->data.getPin()<<"\t";
            file<<temp->data.getTen()<<"\t";
            file<<temp->data.getGioitinh()<<"\t";
            file<<temp->data.getNgaysinh()<<"\t";
            file<<temp->data.getSdt()<<"\t";
            file<<temp->data.getNgaydk()<<"\t";
            file<<temp->data.getNgayhethan()<<"\t";
            int *tam = temp->data.getLichtap();
            for (int i=0 ;i<7;i++){
                file<<tam[i]<<" ";
            }
            file<<"\t";
            file<<temp->data.getIdpt()<<"\t";
            temp=temp->next;
            file<<endl;
        }
    }
    file.close();
}
void quanli::outputfilept(){
    ofstream file("danhsachpt.txt");
    if(dspt != NULL){
        nodept *temp = dspt;
        while(temp != NULL){
            file<<temp->data.getId()<<"\t";
            file<<temp->data.getPin()<<"\t";
            file<<temp->data.getTen()<<"\t";
            file<<temp->data.getGioitinh()<<"\t";
            file<<temp->data.getNgaysinh()<<"\t";
            file<<temp->data.getSdt()<<"\t";
            file<<temp->data.getSlhv()<<"\t";
            file<<temp->data.getNgayvaolam()<<"\t";
            for (int i=0;i<10;i++){
                file<<temp->data.getIdhv()[i]<<" ";
            }
            temp=temp->next;
            file<<endl;
        }
    }
    file.close();
}
void quanli::outputfiletb(){
    ofstream file("danhsachtb.txt");
    if(dstb != NULL){
        nodetb *temp = dstb;
        while(temp != NULL){
            file<<temp->data.getId()<<"\t";
            file<<temp->data.getTentb()<<"\t";
            file<<temp->data.getSoluong()<<"\t";
            file<<temp->data.getSlhong()<<"\t";
            file<<temp->data.getNgaynhap()<<"\t";
            temp=temp->next;
            file<<endl;
        }
    }
    file.close();
}
void quanli::updatehv(){
    system("cls");
    showhv();
    int id;
    cout<<"nhap ID hoc vien can update: ";
    cin>>id;
    cout<<"Nhap thong tin can doi:\n";
    nodehv *temp = searchHv(id);
    if(temp == NULL){
        cout<<"ID khong hop le\n";
        cout<<"[1] Nhap lai\n";
        cout<<"[2] Thoat\n";
        int c;
        cin>>c;
        if(c==1){
            updatehv();
        }
        else{
            return;
        }
    }
    else{
        system("cls");
        temp->data.show();
        cout<<"[1] Doi ten\n";
        cout<<"[2] Doi Pin\n";
        cout<<"[3] Doi sdt\n";
        cout<<"[4] Doi ngay sinh\n";
        cout<<"[5] Gia han\n";
        int c;
        cin>>c;
        if(c==1){
            string s;
            cin.ignore();
            cout<<"Nhap ten:";
            getline(cin,s);
            temp->data.setTen(s);
        }
        else if(c==2){
            int pin;
            cout<<"Nhap ma pin:";
            cin>>pin;
            temp->data.setPin(pin);
        }
        else if(c==3){
            string sdt;
            cout<<"Nhap sdt:";
            cin>>sdt;
            temp->data.setSdt(sdt);
        }
        else if(c==4){
            string ngaysinh;
            string ngay,thang,nam;
            cout<<"Nhap ngay:";cin>>ngay;
            cout<<"Nhap thang:";cin>>thang;
            cout<<"Nhap nam:";cin>>nam;
            ngaysinh=ngay+"/"+thang+"/"+nam;
            temp->data.setNgaysinh(ngaysinh);
        }
        else if(c==5){
            cout<<"Nhap ngay het han:\n";
            string ngayhh;
            string ngay,thang,nam;
            cout<<"Nhap ngay:";cin>>ngay;
            cout<<"Nhap thang:";cin>>thang;
            cout<<"Nhap nam:";cin>>nam;
            ngayhh=ngay+"/"+thang+"/"+nam;
            temp->data.setNgayhethan(ngayhh);
        }
        else{
            cout<<"Lua chon khong hop le !\n";
            int lc;
            cout<<"[1] Nhap lai\n";
            cout<<"[2] Thoat";
            cin>>lc;
            if(lc == 1)
            updatehv();
            else{
                return;
            }
        }
        cout<<"Update thanh cong ID: "<<id<<"\n";
    }
}
void quanli::removehv() {
    int id;
    cout << "Nhap ID hoc vien can xoa: ";
    cin >> id;
    nodehv* temp = dshv;
    nodehv* prev = NULL;
    if (temp != NULL && temp->data.getId() == id) {
        dshv = temp->next;
        if(temp->data.getIdpt() != 0){
            nodept *pt = searchPt(temp->data.getIdpt());
            for (int i = 0; i<10; i++){
                if(pt->data.getIdhv()[i] == temp->data.getId()){
                    pt->data.getIdhv()[i] = 0;
                    break;
                }
            }
        }
        delete temp;
        cout << "Da xoa hoc vien co ID " << id << endl;
        return;
    }
    while (temp != NULL && temp->data.getId() != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Khong tim thay hoc vien co ID " << id << endl;
        return;
    }
    prev->next = temp->next;
    if(temp->data.getIdpt() != 0){
            nodept *pt = searchPt(temp->data.getIdpt());
            for (int i = 0; i<10; i++){
                if(pt->data.getIdhv()[i] == temp->data.getId()){
                    pt->data.getIdhv()[i] = 0;
                    break;
                }
            }
        }
    delete temp;
    cout << "Da xoa hoc vien co ID " << id << endl;
}
void quanli::updatept(){
    system("cls");
    showpt();
    int id;
    cout<<"nhap ID huan luyen vien can update: ";
    cin>>id;
    cout<<"Nhap thong tin can doi:\n";
    nodept *temp = searchPt(id);
    if(temp == NULL){
        cout<<"ID khong hop le\n";
        cout<<"[1] Nhap lai\n";
        cout<<"[2] Thoat\n";
        int c;
        cin>>c;
        if(c==1){
            updatept();
        }
        else{
            return;
        }
    }
    else{
        system("cls");
        temp->data.show();
        cout<<"[1] Doi ten\n";
        cout<<"[2] Doi Pin\n";
        cout<<"[3] Doi sdt\n";
        cout<<"[4] Doi ngay sinh\n";
        int c;
        cin>>c;
        if(c==1){
            string s;
            cin.ignore();
            cout<<"Nhap ten:";
            getline(cin,s);
            temp->data.setTen(s);
        }
        else if(c==2){
            int pin;
            cout<<"Nhap ma pin:";
            cin>>pin;
            temp->data.setPin(pin);
        }
        else if(c==3){
            string sdt;
            cout<<"Nhap sdt:";
            cin>>sdt;
            temp->data.setSdt(sdt);
        }
        else if(c==4){
            string ngaysinh;
            string ngay,thang,nam;
            cout<<"Nhap ngay:";cin>>ngay;
            cout<<"Nhap thang:";cin>>thang;
            cout<<"Nhap nam:";cin>>nam;
            ngaysinh=ngay+"/"+thang+"/"+nam;
            temp->data.setNgaysinh(ngaysinh);
        }
        else{
            cout<<"Lua chon khong hop le !\n";
            int lc;
            cout<<"[1] Nhap lai\n";
            cout<<"[2] Thoat";
            cin>>lc;
            if(lc == 1)
            updatept();
            else{
                return;
            }
        }
        cout<<"Update thanh cong ID: "<<id<<"\n";
    }
}
void quanli::removept() {
    int id;
    cout << "Nhap ID huan luyen vien can xoa: ";
    cin >> id;
    nodept* temp = dspt;
    nodept* prev = NULL;
    if (temp != NULL && temp->data.getId() == id) {
        dspt = temp->next;
        for (int i = 0; i<10 ;i++){
            if(temp->data.getIdhv()[i] != 0){
                nodehv *hv = searchHv(temp->data.getIdhv()[i]);
                hv->data.setIdPt(0);
            }
        }
        delete temp;
        cout << "Da xoa huan luyen vien co ID " << id << endl;
        return;
    }
    while (temp != NULL && temp->data.getId() != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Khong tim thay huan luyen vien co ID " << id << endl;
        return;
    }
    prev->next = temp->next;
    for (int i = 0; i<10 ;i++){
            if(temp->data.getIdhv()[i] != 0){
                nodehv *hv = searchHv(temp->data.getIdhv()[i]);
                hv->data.setIdPt(0);
            }
        }
    delete temp;
    cout << "Da xoa huan luyen vien co ID " << id << endl;
}
void quanli::updatetb(){
    system("cls");
    showtb();
    int id;
    cout<<"nhap ID thiet bi can update: ";
    cin>>id;
    cout<<"Nhap thong tin thiet bi vien:\n";
    nodetb *temp = searchTb(id);
    if(temp == NULL){
        cout<<"ID khong hop le\n";
        cout<<"[1] Nhap lai\n";
        cout<<"[2] Thoat\n";
        int c;
        cin>>c;
        if(c==1){
            updatetb();
        }
        else{
            return;
        }
    }
    else{
        temp->data.nhap();
        cout<<"Update thanh cong ID: "<<id<<"\n";
    }
}
void quanli::removetb(){
    int id;
    cout << "Nhap ID thiet bi can xoa: ";
    cin >> id;
    nodetb* temp = dstb;
    nodetb* prev = NULL;
    if (temp != NULL && temp->data.getId() == id) {
        dstb = temp->next;
        delete temp;
        cout << "Da xoa thiet bi co ID: " << id << endl;
        return;
    }
    while (temp != NULL && temp->data.getId() != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Khong tim thiet bi co ID: " << id << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Da xoa thiet bi co ID: " << id << endl;
}
int quanli::kiemtraIdhv(int id){
    if(dshv != NULL){
        nodehv *temp = dshv;
        while(temp != NULL){
            if(temp->data.getId() == id){
                return 0;
            }
            temp=temp->next;
        }
        return 1;
    }
    return 1;
}
int quanli::kiemtraIdpt(int id){
    if(dspt != NULL){
        nodept *temp = dspt;
        while(temp != NULL){
            if(temp->data.getId() == id){
                return 0;
            }
            temp=temp->next;
        }
        return 1;
    }
    return 1;
}
int quanli::kiemtraIdtb(int id){
    if(dstb != NULL){
        nodetb *temp = dstb;
        while(temp != NULL){
            if(temp->data.getId() == id){
                return 0;
            }
            temp=temp->next;
        }
        return 1;
    }
    return 1;
}

bool quanli::getIdpt(int id){
    nodept* temp = dspt;
    while(temp != NULL){
        if(id == temp->data.getId()){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
bool quanli::getIdhv(int id){
    nodehv* temp = dshv;
    while(temp != NULL){
        if(id == temp->data.getId()){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void quanli::xuattheoidpt(int id){
    nodept *temp = dspt;
    while(temp != NULL){
        if(temp->data.getId() == id){
            temp->data.show();
        }
        temp = temp->next;
    }
    return;
}
nodehv* quanli::searchHv(int id){
    nodehv *temp = dshv;
    while(temp != NULL){
        if(temp->data.getId() == id){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
void quanli::bubbleSort(nodehv* start) {
    int swapped;
    nodehv* ptr1;
    nodehv* lptr = NULL;

    // Kiểm tra nếu danh sách rỗng
    if (start == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            // So sánh giá trị id của hai nút liên tiếp
            if (ptr1->data.getId() > ptr1->next->data.getId()) {
                // Hoán đổi giá trị id giữa hai nút
                swapNode(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Hàm hoán đổi dữ liệu giữa hai node
void quanli::swapNode(nodehv* node1, nodehv* node2) {
    int tempId = node1->data.getId();
    // Thực hiện việc hoán đổi dữ liệu giữa hai node
    node1->data.setId(node2->data.getId());
    node2->data.setId(tempId);
}

nodehv* quanli::searchhv(int id) {
    bubbleSort(dshv);

    // Sử dụng thuật toán tìm kiếm nhị phân
    nodehv* left = dshv;
    nodehv* right = NULL;

    while (left != right) {
        nodehv* mid = left;
        int steps = 0;
        // Tìm mid của phần tử nằm giữa left và right
        while (mid != right) {
            mid = mid->next;
            steps++;
        }
        
        // Chia đôi steps cho 2 để di chuyển mid về giữa left và right
        steps /= 2;
        mid = left;
        for (int i = 0; i < steps; ++i) {
            mid = mid->next;
        }

        // Kiểm tra mid có phải là node cần tìm không
        if (mid->data.getId() == id) {
            return mid;
        } else if (mid->data.getId() < id) {
            left = mid->next;
        } else {
            right = mid;
        }
    }

    return NULL; // Trả về NULL nếu không tìm thấy node có id tương ứng
}

nodept* quanli::searchPt(int id){
    nodept *temp = dspt;
    while(temp != NULL){
        if(temp->data.getId() == id){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
nodetb* quanli::searchTb(int id){
    nodetb *temp = dstb;
    while(temp != NULL){
        if(temp->data.getId()==id){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


