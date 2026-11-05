// from server: 100% by colin
// roc 2007-08 005687f0  unit: RBX::RootInstance  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005687f0

struct Instance {
    char pad[0xbc];
    Instance* field_bc;
};

extern "C" Instance* __cdecl sub_630D36(Instance* self, int a, const char* b, const char* c, int d);
extern "C" Instance* __fastcall sub_4B0920(Instance* self);

Instance* __cdecl findFirstChildByName(Instance* inst) {
    Instance* cur = inst;
    while (cur) {
        Instance* result = sub_630D36(cur, 0, (const char*)0x881f4c, (const char*)0x884e04, 0);
        if (result) {
            return sub_4B0920(result);
        }
        cur = cur->field_bc;
    }
    return 0;
}
