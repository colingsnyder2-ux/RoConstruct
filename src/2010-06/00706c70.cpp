// from server: 36% by atomic.potato
struct Sub {
    void* p0;
    char pad[8];
    int f0;
    int f1;
    int f2;
};

struct PlayerHUD {
    char pad0[0x34];
    Sub s34;
    char pad1[0x54 - 0x34 - 20];
    Sub s54;
    char pad2[0x74 - 0x54 - 20];
    Sub s74;
    char pad3[0x8c - 0x74 - 20];
    Sub s8c;
    char pad4[0xa4 - 0x8c - 20];
    Sub sa4;
    char pad5[0xbc - 0xa4 - 20];
    Sub sbc;
    char pad6[0xd4 - 0xbc - 20];
    Sub sd4;

    PlayerHUD* ctor(void* a, int b);
    void addAction(int idx, const char* name);
};

extern "C" void __stdcall sub_5c9830(const char*, const char*);
extern "C" void __stdcall sub_6608f0(void*, void*);
extern "C" void* __stdcall sub_7a79a0(int);

PlayerHUD* PlayerHUD::ctor(void* a, int b) {
    sub_5c9830((const char*)0xba0794, (const char*)0xa4bc14);
    *(int*)this = 0xa2aa64;
    sub_6608f0(&s34, &s34);
    sub_6608f0(&s54, &s54);

    void* p;
    p = sub_7a79a0(4);
    if (p) *(void**)p = &s74; else p = 0;
    s74.p0 = p;
    s74.f0 = 0;
    s74.f1 = 0;
    s74.f2 = 0;

    p = sub_7a79a0(4);
    if (p) *(void**)p = &s8c; else p = 0;
    s8c.p0 = p;
    s8c.f0 = 0;
    s8c.f1 = 0;
    s8c.f2 = 0;

    p = sub_7a79a0(4);
    if (p) *(void**)p = &sa4; else p = 0;
    sa4.p0 = p;
    sa4.f0 = 0;
    sa4.f1 = 0;
    sa4.f2 = 0;

    p = sub_7a79a0(4);
    if (p) *(void**)p = &sbc; else p = 0;
    sbc.p0 = p;
    sbc.f0 = 0;
    sbc.f1 = 0;
    sbc.f2 = 0;

    p = sub_7a79a0(4);
    if (p) *(void**)p = &sd4; else p = 0;
    sd4.p0 = p;
    sd4.f0 = 0;
    sd4.f1 = 0;
    sd4.f2 = 0;

    addAction(0, (const char*)0xa4bc0c);
    addAction(1, (const char*)0xa2a2d8);
    addAction(2, (const char*)0xa4bc04);
    addAction(3, (const char*)0xa4bbfc);
    addAction(4, (const char*)0xa4bbf8);
    return this;
}
