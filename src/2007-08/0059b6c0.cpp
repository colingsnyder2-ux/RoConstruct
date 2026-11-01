// from server: 100% by colin
struct FactoryProduct {
    char pad[0x18c];
    int field_18c;
    void setValue(int value);
};

void FactoryProduct::setValue(int value) {
    if (field_18c != value) {
        field_18c = value;
        extern void __stdcall sub_444710(int);
        sub_444710(0x8c505c);
        extern void* __fastcall sub_599480(FactoryProduct*);
        void* p = sub_599480(this);
        if (p) {
            void** vtbl = *(void***)p;
            void (__fastcall *fn)(void*) = (void (__fastcall *)(void*))vtbl[3];
            fn(p);
        }
    }
}
