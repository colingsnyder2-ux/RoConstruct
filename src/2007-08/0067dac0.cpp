// from server: 100% by colin
struct CXTPControlWindowList {
    void* GetSite();
    void* CreateControl(void*);
};

void* CXTPControlWindowList::CreateControl(void* arg) {
    void* p = GetSite();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, void*, void*) = (void (__thiscall *)(void*, void*, void*))vtbl[0xe0 / 4];
    fn(p, this, arg);
    return p;
}
