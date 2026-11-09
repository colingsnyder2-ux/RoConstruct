// from server: 44% by colin
struct CXTPRibbonBar {
    void Construct();
    void SetVisible(int);
    void SetInnerValue(int);
};

struct CXTPCommandBar {
    void SetVisible(int bVisible);
    void SetInnerValue(int value);
};

struct CXTPControlQuickAccessMorePopup {
    char pad_0[0x1c4];
    int field_1c4;
    char pad_1c8[0x98];
    int field_260;
    char pad_264[0x14];
    int field_278;
    char pad_27c[0x10];
    int field_28c;
    char pad_290[0x30];
    int field_2c0;

    void Construct();
};

extern "C" void* __cdecl sub_62fef6(unsigned int);
extern "C" void __cdecl sub_6301e4(int);
extern "C" void __cdecl sub_67a640(void*, void*);
extern "C" void* __cdecl sub_67d1e0(void*, void*, int, int, int, int);
extern "C" void __cdecl sub_6a6600();
extern "C" void __cdecl sub_6a7870();
extern "C" void __cdecl sub_6a7940();
extern "C" void __cdecl sub_6a87f0();
extern "C" void __cdecl sub_7165d0();
extern "C" void __cdecl sub_717480();
extern "C" void __cdecl sub_718d10();
extern "C" void __cdecl sub_718df0();
extern "C" void __cdecl sub_6437f0();
extern "C" void __cdecl sub_643820();

extern "C" void* __stdcall SetRectEmpty(void*);

void CXTPControlQuickAccessMorePopup::Construct()
{
    sub_6a6600();
    field_1c4 = 0x7d4eb0;
    *(int*)this = 0x7d51dc;
    *(int*)((char*)this + 0x54) = 0x7d51cc;
    *(int*)((char*)this + 0x5c) = 0x7d516c;
    *(int*)((char*)this + 0x1c4) = 0x7d5160;

    void* p1 = sub_62fef6(0x40);
    if (p1) {
        sub_718df0();
    } else {
        p1 = 0;
    }
    field_260 = (int)p1;
    sub_67a640(p1, this);

    sub_6301e4(*(int*)((char*)this + 0xf8));

    void* p2 = sub_62fef6(0x40);
    if (p2) {
        sub_718d10();
    } else {
        p2 = 0;
    }
    *(int*)((char*)this + 0xf8) = (int)p2;
    sub_67a640(p2, this);

    void* (*fn)(void*) = (void* (*)(void*))0x77ee14;
    fn((char*)this + 0x1d8);
    fn((char*)this + 0x1e8);
    fn((char*)this + 0x1f8);
    fn((char*)this + 0x208);
    fn((char*)this + 0x218);

    sub_6a87f0();

    void* p3 = sub_62fef6(0x178);
    if (p3) {
        sub_6a7870();
    } else {
        p3 = 0;
    }
    *(int*)((char*)this + 0x268) = (int)sub_67d1e0(*(void**)((char*)this + 0xf8), p3, 0, 0x2583, -1, 0);

    void* p4 = sub_62fef6(0x178);
    if (p4) {
        sub_6a7940();
    } else {
        p4 = 0;
    }
    *(int*)((char*)this + 0x26c) = (int)sub_67d1e0(*(void**)((char*)this + 0xf8), p4, 0, 0x258b, -1, 0);

    void* p5 = sub_62fef6(0x208);
    if (p5) {
        sub_717480();
    } else {
        p5 = 0;
    }
    *(int*)((char*)this + 0x264) = (int)sub_67d1e0(*(void**)((char*)this + 0xf8), p5, 0, 0x2584, -1, 0);

    *(int*)((char*)this + 0xf4) = 3;
    *(int*)((char*)this + 0xe8) = 0x440;
    *(int*)((char*)this + 0x134) = 0;
    *(int*)((char*)this + 0x23c) = 1;
    *(int*)((char*)this + 0x240) = 1;
    *(int*)((char*)this + 0x278) = 0xfa;
    *(int*)((char*)this + 0x160) = 0;
    *(int*)((char*)this + 0x288) = 0;
    *(int*)((char*)this + 0x27c) = 0;
    *(int*)((char*)this + 0x270) = 0;
    *(int*)((char*)this + 0x238) = 1;
    *(int*)((char*)this + 0x254) = 0;
    *(int*)((char*)this + 0x244) = 0;
    *(int*)((char*)this + 0x248) = 1;

    void* p6 = sub_62fef6(0x14);
    if (p6) {
        sub_7165d0();
    } else {
        p6 = 0;
    }
    *(int*)((char*)this + 0x280) = (int)p6;
    *(int*)((char*)this + 0x16c) = 1;
    *(int*)((char*)this + 0x24c) = 0;
    *(int*)((char*)this + 0x250) = 1;
    *(int*)((char*)this + 0x284) = 0;
    *(int*)((char*)this + 0x258) = 0;
    *(int*)((char*)this + 0x1c8) = 0;
    *(int*)((char*)this + 0x25c) = 1;

    sub_643820();
    sub_6437f0();
}
