// from server: 100% by colin
struct CXTPControlButtonColor {
    void* f(unsigned int);
};

extern "C" void* __fastcall sub_672A80(void*);

void* CXTPControlButtonColor::f(unsigned int arg) {
    void* p = sub_672A80(this);
    void** vt = *(void***)p;
    void (__thiscall *fn)(void*, void*, unsigned int) = (void (__thiscall *)(void*, void*, unsigned int))vt[0x38];
    fn(p, this, arg);
    return p;
}
