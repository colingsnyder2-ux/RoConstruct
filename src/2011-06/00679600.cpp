// from server: 100% by atomic.potato
extern "C" char __cdecl func_64fac0(void* a, void* b);

struct SpecialShape {
    char pad0[0xbc];
    char field_bc[0x40];
    int field_fc;
    void method_6790c0(void* arg);
    void method_411f60(void* arg);
    void update(void* arg);
};

void SpecialShape::update(void* arg) {
    if (func_64fac0(field_bc, arg)) {
        method_6790c0(arg);
        int v = 5;
        if (field_fc != v) {
            field_fc = v;
            method_411f60((void*)0xcce5ac);
        }
    }
}
