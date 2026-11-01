// from server: 100% by colin
struct CXTPRibbonControlTab {
    void* getSite();
    void OnTabChanged(int);
    void* f(int);
};

void* CXTPRibbonControlTab::f(int arg)
{
    void* p = getSite();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, void*, int) = (void (__thiscall *)(void*, void*, int))vtbl[0xe0 / 4];
    fn(p, this, arg);
    return p;
}
