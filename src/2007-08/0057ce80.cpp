// from server: 100% by colin
struct Workspace {
    char pad[0x31c];
    void* field_31c;
    void func_57c3e0(int);
    void func_57ce80();
};

void Workspace::func_57ce80()
{
    void* p = field_31c;
    if (p) {
        void** vtable = *(void***)p;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vtable[0x2c / 4];
        fn(p, 1);
    }
    field_31c = 0;
    func_57c3e0(0);
}
