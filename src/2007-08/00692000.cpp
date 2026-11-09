// from server: 100% by colin
struct CXTThemeManager
{
    void* field_0;
    void* field_4;
    void* field_8;
    void destroy();
};

struct Helper_00738b32
{
    void method(void* p);
};

extern void* __cdecl helper_00691fa0();

void CXTThemeManager::destroy()
{
    field_0 = (void*)0x7d0898;
    if (field_4 != 0)
    {
        void** vtable = *(void***)field_4;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vtable[0];
        fn(field_4, 1);
        field_4 = 0;
    }
    char* p = (char*)helper_00691fa0();
    p += 0x24;
    ((Helper_00738b32*)p)->method(this);
    field_8 = 0;
}
