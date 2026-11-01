// from server: 100% by colin
struct CXTPToolBar_CControlButtonHide
{
    void* method_006ca550();
    void* method_006ca5c0(void* arg);
};

void* CXTPToolBar_CControlButtonHide::method_006ca5c0(void* arg)
{
    void* result = method_006ca550();
    void** vtable = *(void***)result;
    void (__thiscall *fn)(void*, void*, void*) = (void (__thiscall *)(void*, void*, void*))vtable[0xe0 / 4];
    fn(result, this, arg);
    return result;
}
