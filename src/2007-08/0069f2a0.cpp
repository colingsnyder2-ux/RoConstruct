// from server: 100% by colin
struct CSelectionCaption {
    void method(int, int);
};

extern "C" void* __cdecl sub_710f90();

void CSelectionCaption::method(int a, int b) {
    void* p = sub_710f90();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, int, void*, int) = (void (__thiscall *)(void*, int, void*, int))vtbl[4];
    fn(p, a, this, b);
}
