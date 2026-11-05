// from server: 100% by tester
struct CXTPPopupBar {
    void* GetSite();
    void* GetPopupSite(int);
};

void* CXTPPopupBar::GetPopupSite(int n)
{
    void* p = GetSite();
    void* vtable = *(void**)p;
    void (__thiscall* fn)(void*, void*, int) = *(void (__thiscall**)(void*, void*, int))((char*)vtable + 0x1dc);
    fn(p, this, n);
    return p;
}
