// from server: 100% by colin
struct CXTPCommandBar
{
    void m(int, int, int);
};

extern "C" int (__stdcall *SetRectEmpty)(void*);

void CXTPCommandBar::m(int a, int b, int c)
{
    SetRectEmpty((char*)this + 0x138);
    void** vt = *(void***)this;
    void (__thiscall *fn)(CXTPCommandBar*, int, int, int) = (void (__thiscall *)(CXTPCommandBar*, int, int, int))vt[0x170 / 4];
    fn(this, a, b, c);
}
