#include "hocvien.h"
#include "huanluyenvien.h"
#include "thietbi.h"
#include <fstream>
#include <sstream>
struct nodehv
{
    hocvien data;
    nodehv* next;
};
struct nodept
{
    huanluyenvien data;
    nodept* next;
};
struct nodetb{
    thietbi data;
    nodetb* next;
};
class quanli{
    private:
        nodehv *dshv;
        nodept *dspt;
        nodetb *dstb;
    public:
        quanli();
        void addhv(hocvien hv);
        void addpt(huanluyenvien pt);
        void addtb(thietbi tb);
        void updatehv();
        void updatept();
        void updatetb();
        void removehv();
        void removept();
        void removetb();
        void showhv();
        void showpt();
        void showtb();
        void inputfilept();
        void outputfilept();
        void inputfiletb();
        void outputfiletb();
        void inputfilehv();
        void outputfilehv();
        int kiemtraIdhv(int id);
        int kiemtraIdpt(int id);
        int kiemtraIdtb(int id);
        nodehv *searchHv(int id);
        nodept *searchPt(int id);
        nodetb *searchTb(int id);
        bool getIdpt(int id);
        bool getIdhv(int id);
        void xuattheoidpt(int id);
        void bubbleSort(nodehv* );
        void swapNode(nodehv *, nodehv*);
        nodehv *searchhv(int id);
};

