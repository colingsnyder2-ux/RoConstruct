// from server: 44% by colin
struct CXTPTabPaintManager_CColorSetOffice2007 {
    char pad0[4];
    char m_brush1[0x20];
    char m_brush2[0x20];
    char pad48[0x30];
    int m_nTextColor;
    int m_nTextColor2;
    char pad7c[0x18];
    int m_nHighlight;
    char pad98[0x14];
    int m_nSelectedText;
    char padb0[0x1c];
    int m_nTabNormalText;
    char padd0[0x10];
    int m_nTabSelectedText;
    char pade4[0x1c];
    int m_nWindowText;
    char pad104[0x38];
    int m_nWindowFrame;
    char pad140[0x14];
    int m_nBorder;
    char pad158[0x14];
    int m_nBorder2;
    char pad170[0x14];
    int m_nBorder3;
    char pad188[0x8c];
    int m_nFlag;

    void Init();
};

extern "C" void* __stdcall sub_77ddb8(void*);
extern "C" void* __stdcall sub_710f20();
extern "C" void* __stdcall sub_710820(void*);
extern "C" void* __stdcall sub_668f70();
extern "C" void* __stdcall sub_668770(void*, int);
extern "C" void __stdcall sub_668ec0(void*, int);
extern "C" void __stdcall sub_6684f0(void*, int, int, float);
extern float g_797e9c;

void CXTPTabPaintManager_CColorSetOffice2007::Init()
{
    char* p;
    void* v;

    p = (char*)sub_77ddb8((void*)0x7d69fc);
    *(int*)((char*)this + 0x78) = (int)p;

    p = (char*)sub_77ddb8((void*)0x787950);
    *(int*)((char*)this + 0x2c) = 0xc;
    *(char*)((char*)this + 0x28) = 0xd;

    v = sub_710f20();
    *(int*)((char*)this + 0x28) = 0;
    v = sub_710820(v);
    *(int*)((char*)this + 0x84) = (int)v;

    p = (char*)sub_77ddb8((void*)0x7d6ae4);
    p = (char*)sub_77ddb8((void*)0x787950);
    *(int*)((char*)this + 0x2c) = 0xe;
    *(char*)((char*)this + 0x28) = 0xf;

    v = sub_710f20();
    *(int*)((char*)this + 0x28) = 0;
    v = sub_710820(v);
    *(int*)((char*)this + 0x20c) = (int)v;

    p = (char*)sub_77ddb8((void*)0x7d5660);
    p = (char*)sub_77ddb8((void*)0x7d5670);
    *(int*)((char*)this + 0x2c) = 0x10;
    *(char*)((char*)this + 0x28) = 0x11;

    v = sub_710f20();
    *(int*)((char*)this + 0x28) = 0;
    v = sub_710820(v);
    *(int*)((char*)this + 0xcc) = (int)v;

    p = (char*)sub_77ddb8((void*)0x7d5660);
    p = (char*)sub_77ddb8((void*)0x7d5670);
    *(int*)((char*)this + 0x2c) = 0x12;
    *(char*)((char*)this + 0x28) = 0x13;

    v = sub_710f20();
    *(int*)((char*)this + 0x28) = 0;
    v = sub_710820(v);
    *(int*)((char*)this + 0xa8) = (int)v;

    p = (char*)sub_77ddb8((void*)0x7d5650);
    p = (char*)sub_77ddb8((void*)0x7d5670);
    *(int*)((char*)this + 0x2c) = 0x14;
    *(char*)((char*)this + 0x28) = 0x15;

    v = sub_710f20();
    *(int*)((char*)this + 0x28) = 0;
    v = sub_710820(v);
    *(int*)((char*)this + 0xc0) = (int)v;

    v = sub_668f70();
    v = sub_668770(v, 0x21);
    *(int*)((char*)this + 0x90) = (int)v;

    v = sub_668f70();
    v = sub_668770(v, 0x12);
    *(int*)((char*)this + 0xcc) = (int)v;

    *(int*)((char*)this + 0x48) = 0x9c613b;
    if (*(int*)((char*)this + 0x4c) != -1)
        *(int*)((char*)this + 0x154) = *(int*)((char*)this + 0x48);
    else
        *(int*)((char*)this + 0x154) = *(int*)((char*)this + 0x4c);

    *(int*)((char*)this + 0x13c) = 0x9a3500;
    *(int*)((char*)this + 0x148) = 0x9a3500;
    *(int*)((char*)this + 0x130) = 0xf1a675;
    *(int*)((char*)this + 0x160) = 0xf1a675;
    *(int*)((char*)this + 0x16c) = 0xffffff;

    sub_668ec0((char*)this + 0xe0, 0x6fc0ff);
    sub_668ec0((char*)this + 0x100, 0x800000);

    sub_6684f0((char*)this + 4, 0xfadac4, 0xfefdfc, g_797e9c);
    *(int*)((char*)this + 0x9c) = 0xf6c0a2;
    *(int*)((char*)this + 0x78) = 0x73c2ff;
    *(int*)((char*)this + 0x84) = 0xc9f0ff;
    sub_6684f0((char*)this + 0x24, 0xf5be9e, 0xfadac4, g_797e9c);
    *(int*)((char*)this + 0x20c) = 0x800000;

    *(int*)((char*)this + 0x214) = 1;
}
