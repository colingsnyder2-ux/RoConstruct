// from server: 34% by colin
struct CXTPRibbonControlSystemPopupBarListItem {
    char pad0[0x20];
    int m_field20;
    char pad24[0x15c - 0x24];
    int m_field15c;
    int m_field160;
    void method71a470(int);
};

extern "C" int __stdcall sub_77dcc8(int, int);
extern "C" int __stdcall sub_77dd98(int, int);
extern "C" int __stdcall sub_77ddbc(int);

void CXTPRibbonControlSystemPopupBarListItem::method71a470(int arg)
{
    int local30;
    int local14;
    int local10;
    int local20;
    int local24;
    int local28;

    local10 = arg;
    local14 = (int)this;
    local20 = 0;

    int (*fn)(void*, int*) = *(int (**)(void*, int*))(*(int*)this + 0x58);
    fn(this, &local30);

    int* p = (int*)local30;
    int v = sub_77dcc8(0x24, (int)&local14);
    v = sub_77dd98(v, 0);
    int (*fn2)(void*, int) = *(int (**)(void*, int))(*(int*)p + 0x70);
    fn2(p, v);

    sub_77ddbc((int)&local30);
}
