// from server: 100% by atomic.potato
struct CXTPPopupBar {
    void* GetSite();
    void* GetPopupSite(int);
};

void* CXTPPopupBar::GetPopupSite(int n)
{
    void* p = GetSite();
    void* vtable = *(void**)p;
    void (__thiscall* fn)(void*, void*, int) = *(void (__thiscall**)(void*, void*, int))((char*)vtable + 0x1c8);
    fn(p, this, n);
    return p;
}
