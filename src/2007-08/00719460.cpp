// from server: 100% by colin
struct CXTPRibbonGroupPopupToolBar {
    void* m_pUnknown; // placeholder for offset 0x24c
    void* sub_00719460(void* arg);
};

void* CXTPRibbonGroupPopupToolBar::sub_00719460(void* arg)
{
    void* p = *(void**)((char*)this + 0x24c);
    void** vtbl = *(void***)p;
    typedef void* (__thiscall *Fn)(void*, void*);
    Fn fn = (Fn)vtbl[0x150 / 4];
    fn(p, arg);
    return arg;
}
