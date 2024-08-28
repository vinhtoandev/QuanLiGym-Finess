#include<iostream>
using namespace std;
#include "thaotac.h"
int main(){
    quanli ad;
    ad.inputfilehv();
    ad.inputfilept();
    ad.inputfiletb();
    Menu_chinh(ad);
    return 0;
}