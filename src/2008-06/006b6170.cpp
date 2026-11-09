// from server: 100% by tester
struct CXTPCommandBar
{
    void m(int, int, int);
};

extern "C" int (__stdcall *SetRectEmpty)(void*);

void CXTPCommandBar::m(int a, int b, int c)
{
    SetRectEmpty((char*)this + 0x13c);
    void** vt = *(void***)this;
    void (__thiscall *fn)(CXTPCommandBar*, int, int, int) = (void (__thiscall *)(CXTPCommandBar*, int, int, int))vt[0x178 / 4];
    fn(this, a, b, c);
}
