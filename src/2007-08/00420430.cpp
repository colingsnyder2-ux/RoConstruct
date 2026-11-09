// from server: 54% by colin
struct CRobloxTreeCtrl {
    void sub_41FC50(int);
    void sub_420430();
};

extern "C" void* __stdcall sub_668F70();
extern "C" void* __stdcall sub_668770(void*, int);
extern "C" void __stdcall sub_6689D0(void*, int, int);

void CRobloxTreeCtrl::sub_420430() {
    void* p1 = sub_668F70();
    int v1 = (int)sub_668770(p1, 0xF);
    void* p2 = sub_668F70();
    int v2 = (int)sub_668770(p2, 0xD);

    unsigned char b1 = (unsigned char)((unsigned int)v1 >> 16);
    unsigned char b2 = (unsigned char)((unsigned int)v2 >> 16);
    int avg1 = (int)((b1 + b2) / 2);

    unsigned char b3 = (unsigned char)((unsigned int)v1 >> 8);
    unsigned char b4 = (unsigned char)((unsigned int)v2 >> 8);
    int avg2 = (int)((b3 + b4) / 2);

    unsigned char b5 = (unsigned char)v1;
    unsigned char b6 = (unsigned char)v2;
    int avg3 = (int)((b5 + b6) / 2);

    int packed = (avg1 << 16) | (avg2 << 8) | avg3;

    void* p3 = sub_668F70();
    sub_6689D0(p3, 0xF, packed);

    sub_41FC50(v1);

    void* p4 = sub_668F70();
    sub_6689D0(p4, 0xF, v1);
}
