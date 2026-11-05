// from server: 100% by tester
struct VCXTPReportRows {
    char pad0[0x20];
    int field20;
    int field24;
    int field28;
    char pad2c[0x14];
    int field40;
    int field44;
    int init(int);
};

extern "C" void __fastcall sub_9CC5CA(void*);
extern "C" void __fastcall sub_843370(void*);

int VCXTPReportRows::init(int arg) {
    sub_9CC5CA(this);
    *(int*)this = 0xac6264;
    field20 = arg;
    sub_843370((char*)this + 0x2c);
    field28 = 0;
    field40 = 0;
    field44 = 0;
    field24 = -1;
    return (int)this;
}
