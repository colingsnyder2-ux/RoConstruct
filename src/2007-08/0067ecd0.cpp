// from server: 100% by colin
struct CXTPControlWorkspaceActions {
    void* f_0067ec60();
    void* f_0067ecd0(void* arg);
};

void* CXTPControlWorkspaceActions::f_0067ecd0(void* arg)
{
    void* p = f_0067ec60();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, void*, void*) = (void (__thiscall *)(void*, void*, void*))vtbl[0xe0 / 4];
    fn(p, this, arg);
    return p;
}
