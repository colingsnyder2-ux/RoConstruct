// from server: 100% by tester
struct CXTPDialogBar
{
    void* sub_71EBF0();
    void* method_71EC60(void* arg);
};

void* CXTPDialogBar::method_71EC60(void* arg)
{
    void* p = sub_71EBF0();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, void*, void*) = (void (__thiscall *)(void*, void*, void*))vtbl[0x1dc / 4];
    fn(p, this, arg);
    return p;
}
