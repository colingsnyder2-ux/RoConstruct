// from server: 26% by colin
struct CRenderSettings {
    void construct();
    char pad[0x120];
};

extern "C" {
    void __stdcall sub_447870();
    int __cdecl sub_472F80();
    void __stdcall sub_541BF0();
    void __stdcall sub_77E6A4();
    void __stdcall sub_77E698();
    void __stdcall sub_77E6AC();
}

extern float g_78fa38;
extern float g_78fa40;
extern int g_888558;
extern int g_897a60;

void CRenderSettings::construct()
{
    sub_447870();
    *(float*)((char*)this + 0xe8) = g_78fa38;
    *(float*)((char*)this + 0xec) = g_78fa38;
    *(float*)((char*)this + 0xf0) = g_78fa40;
    *(float*)((char*)this + 0xf4) = g_78fa40;
    *(int*)((char*)this + 0x00) = 0x7900fc;
    *(int*)((char*)this + 0x04) = 0x7900f0;
    *(int*)((char*)this + 0x10) = 0x7900e8;
    *(int*)((char*)this + 0x14) = 0x7900d8;
    *(int*)((char*)this + 0x2c) = 0x7900c8;
    *(int*)((char*)this + 0x44) = 0x7900b8;
    *(int*)((char*)this + 0x5c) = 0x7900a8;
    *(int*)((char*)this + 0x74) = 0x790098;
    *(int*)((char*)this + 0x8c) = 0x790088;
    *(unsigned char*)((char*)this + 0xf8) = 1;
    sub_77E6A4();
    if (sub_472F80() >= 0xf42400) {
        *(unsigned short*)((char*)this + 0x118) = 0x400;
        *(unsigned short*)((char*)this + 0x11a) = 0x300;
    } else {
        *(unsigned short*)((char*)this + 0x118) = 0x320;
        *(unsigned short*)((char*)this + 0x11a) = 0x258;
    }
    *(int*)((char*)this + 0x11c) = g_888558;
    sub_77E698();
    sub_541BF0();
    sub_77E6AC();
    g_897a60 = 1;
}
