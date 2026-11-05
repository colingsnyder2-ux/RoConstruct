// from server: 100% by tester
struct VAuthoringSettings_FactoryProduct {
    char pad[0x44];
    void* field_0x48;
    void method(int, int);
};

void VAuthoringSettings_FactoryProduct::method(int a, int b) {
    void* p = field_0x48;
    if (p) {
        void** vtbl = *(void***)p;
        typedef void (__thiscall *Fn)(void*, int, int);
        Fn f = (Fn)vtbl[0x4c / 4];
        f(p, a, b);
    }
}
