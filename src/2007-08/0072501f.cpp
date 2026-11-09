// from server: 52% by colin
struct CXTIconHandle {
    int field0;
    int field4;
    int field8;
    char fieldC;
    char padD[3];
    int field10;
    int field14;
    char pad18[8];
    int field20;
    int field24;
    int field28;
    CXTIconHandle* construct();
};

struct Sub724f73 {
    void method();
};

struct Sub4018d0 {
    int method();
};

extern "C" int __stdcall sub_630b8c(void*, int, int);
extern "C" int __stdcall sub_630a1e();
extern "C" int __stdcall GetVersionExA(void*);

extern "C" void __stdcall sub_724f73();

CXTIconHandle* CXTIconHandle::construct()
{
    char buf[0x94];
    ((Sub724f73*)this)->method();
    field8 = 0x400000;
    field4 = 0x400000;
    field0 = 0x3c;
    fieldC = 0;
    sub_630b8c(buf, 0, 0x94);
    *(int*)buf = 0x94;
    GetVersionExA(buf);
    if (*(int*)(buf + 0x10) == 2) {
        if (*(unsigned int*)(buf + 4) < 5) {
            fieldC = 1;
        }
    } else if (*(int*)(buf + 0x10) == 1) {
        if (*(unsigned int*)(buf + 4) > 4) {
            fieldC = 1;
        } else if (*(unsigned int*)(buf + 4) == 4) {
            if (*(unsigned int*)(buf + 8) > 0) {
                fieldC = 1;
            }
        }
    }
    field10 = 0x800;
    field14 = 0x7e50c0;
    if (((Sub4018d0*)((char*)this + 0x18))->method() < 0) {
        *(char*)0x8bbe98 = 1;
    }
    return this;
}
