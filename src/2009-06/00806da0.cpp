// from server: 100% by why2
struct CXTColorSelectorCtrl {
    void SetColor(unsigned int color);
};

void CXTColorSelectorCtrl::SetColor(unsigned int color)
{
    typedef void (__thiscall *Fn)(void *, unsigned int, int);
    Fn fn = *(Fn *)(*(unsigned int *)this + 0x14c);
    fn(this, color, 0);
}
