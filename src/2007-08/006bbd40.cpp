// from server: 41% by colin
struct CXTPOffice2007Theme {
    void Init();
};

extern "C" void __stdcall sub_77DDB8(void*);
extern float g_797E9C;
extern void* sub_6BA7A0();
extern void* sub_710820();
extern void sub_6684F0();
extern void sub_6C0AC0();
extern void sub_630A1E();

void CXTPOffice2007Theme::Init()
{
    char buf[0x160];
    void* p;

    sub_77DDB8(buf);
    p = sub_6BA7A0();
    *(void**)((char*)this + 0x3E8) = sub_710820();

    sub_77DDB8(buf);
    p = sub_6BA7A0();
    *(void**)((char*)this + 0x3C4) = sub_710820();

    sub_77DDB8(buf);
    p = sub_6BA7A0();
    *(void**)((char*)this + 0x3C4) = sub_710820();

    sub_77DDB8(buf);
    p = sub_6BA7A0();
    *(void**)((char*)this + 0x3C4) = sub_710820();

    sub_77DDB8(buf);
    p = sub_6BA7A0();
    *(void**)((char*)this + 0x3C4) = sub_710820();

    sub_6684F0();
    sub_6C0AC0();
    sub_630A1E();
}
