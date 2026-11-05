// from server: 86% by atomic.potato
struct VerbWidget_0070a820 {
    struct VTable {
        int (__thiscall *f68)(VerbWidget_0070a820*);
    };
    struct Subobject {
        struct VTable {
            int (__thiscall *f8)(Subobject*);
        };
        VTable* vtable;
    };
    VTable* vtable;
    char pad_4[168];
    Subobject* field_ac;
    int f();
};

int VerbWidget_0070a820::f() {
    if (vtable->f68(this) && field_ac && field_ac->vtable->f8(field_ac))
        return 1;
    return 0;
}
