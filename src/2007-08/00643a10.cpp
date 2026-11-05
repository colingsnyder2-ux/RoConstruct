// from server: 100% by colin
struct CXTPCommandBar
{
    char pad[0x164];
    void* field_164;
    void SetCommandBar(void* p);
};

void CXTPCommandBar::SetCommandBar(void* p)
{
    if (field_164 != 0)
    {
        extern void __fastcall func_006301e4(void*);
        func_006301e4(field_164);
    }
    field_164 = p;
    if (p != 0)
    {
        void** vtbl = *(void***)p;
        void (__fastcall *fn)(void*) = (void (__fastcall *)(void*))vtbl[0x2a];
        fn(p);
    }
}
