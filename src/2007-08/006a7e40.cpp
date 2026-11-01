// from server: 100% by colin
struct CXTPRibbonBar {
    void sub_738580();
    void* sub_6a79e0();
    void sub_6a7e40();
};

void CXTPRibbonBar::sub_6a7e40()
{
    sub_738580();
    void* p = sub_6a79e0();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vtbl[0xa8 / 4];
    fn(p);
    char* base = (char*)this;
    char* esi = *(char**)(base + 0x264);
    void** vtbl2 = *(void***)(esi + 0x178);
    void (__thiscall *fn2)(void*) = (void (__thiscall *)(void*))vtbl2[2];
    fn2(esi + 0x178);
}
