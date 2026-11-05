// from server: 37% by Intel
struct std_string {
    char _buf[28];
};

extern "C" void __stdcall std_string_ctor(std_string*, const char*);
extern "C" void __stdcall std_string_dtor(std_string*);

extern "C" void __cdecl sub_7d2160(void*);
extern "C" void __cdecl sub_684840(void*, std_string*);
extern "C" void __stdcall dword_b22648(void*);
extern "C" void __stdcall dword_b2263c(void*);

struct VSkin_FactoryProduct {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    int f_84;
    int f_88;
    int f_8c;
    int f_90;
    int f_94;
    int f_98;
    char pad_9c[36];
    VSkin_FactoryProduct* init();
};

VSkin_FactoryProduct* VSkin_FactoryProduct::init() {
    sub_7d2160(this);
    f_0 = (void*)0xbc021c;
    f_4 = (void*)0xbc0210;
    f_18 = (void*)0xbc0204;
    f_1c = (void*)0xbc01f8;
    f_80 = (void*)0xbc01f0;
    f_84 = 0xe2;
    f_88 = 0xe2;
    f_8c = 0xe2;
    f_90 = 0x1c;
    f_94 = 0x17;
    f_98 = 0x17;

    std_string s;
    std_string_ctor(&s, "Body Colors");
    dword_b22648(&s);
    sub_684840(this, &s);
    dword_b2263c(&s);
    std_string_dtor(&s);

    return this;
}
