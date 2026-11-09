// from server: 100% by tester
struct CXTColorSelectorCtrl {
    void SetColor(unsigned int color);
};

void CXTColorSelectorCtrl::SetColor(unsigned int color) {
    typedef void (__thiscall *Fn)(CXTColorSelectorCtrl *, unsigned int, int);
    Fn fn = *(Fn *)(*(char **)this + 0x14c);
    fn(this, color, 0);
}
