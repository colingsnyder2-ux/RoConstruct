// from server: 100% by why2
struct S {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    void method();
};

void S::method() {
    S* p = (S*)field_c;
    if (p) {
        void** vtbl = *(void***)p;
        void (__thiscall *fn)(S*, int) = (void (__thiscall *)(S*, int))vtbl[0x98 / 4];
        fn(p, 1);
    }
}
