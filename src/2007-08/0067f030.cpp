// from server: 100% by colin
struct CXTPControlRadioButton {
    void* getSite();
    void* OnCalcDynamicSize(int);
};

void* CXTPControlRadioButton::OnCalcDynamicSize(int n) {
    void* site = getSite();
    void* p = *(void**)site;
    void* (__thiscall *fn)(void*, void*, int) = *(void* (__thiscall **)(void*, void*, int))((char*)p + 0xe0);
    fn(site, this, n);
    return site;
}
