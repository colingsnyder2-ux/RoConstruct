// from server: 36% by colin
struct COleException {
    char pad0[4];
    char pad4[0x28];
    void* field2c;
    char pad30[0x30];
    void method();
};

extern "C" void* __stdcall sub_5806D0();
extern "C" void* __stdcall sub_62FEF6();
extern "C" void __stdcall sub_62FC62(void*);
extern "C" void __stdcall sub_498CF0(void*);
extern "C" void __stdcall sub_630A1E();
extern "C" void __stdcall sub_427950();
extern "C" void __stdcall sub_4277D0();

extern "C" void* __stdcall MSVCP80_0x77e698();
extern "C" void* __stdcall MSVCP80_0x77e664();
extern "C" void* __stdcall MSVCP80_0x77e640();
extern "C" void* __stdcall MSVCP80_0x77e63c();
extern "C" void* __stdcall MSVCP80_0x77dd98();
extern "C" void* __stdcall MSVCP80_0x77e6a8();
extern "C" void* __stdcall MSVCP80_0x77ddbc();
extern "C" void* __stdcall MSVCP80_0x77e6ac();

void COleException::method() {
    char buf[0x14];
    char buf2[0x14];
    void* p;
    void* q;
    void* r;
    int flag = 0;

    MSVCP80_0x77e698();
    sub_5806D0();
    MSVCP80_0x77e664();
    MSVCP80_0x77e640();
    MSVCP80_0x77e640();
    p = sub_62FEF6();
    if (p != 0) {
        sub_427950();
        flag = 1;
        q = MSVCP80_0x77dd98();
        MSVCP80_0x77e6a8();
        sub_4277D0();
    } else {
        q = 0;
    }
    r = field2c;
    field2c = q;
    sub_62FC62(r);
    if (flag & 1) {
        MSVCP80_0x77ddbc();
    }
    sub_498CF0(field2c);
    MSVCP80_0x77e6ac();
    sub_630A1E();
}
