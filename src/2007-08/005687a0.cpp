// from server: 100% by colin
struct Instance {
    char pad[0xbc];
    Instance* field_bc;
};

extern "C" Instance* __cdecl sub_630D36(Instance* self, int a, const char* b, const char* c, int d);
extern "C" Instance* __fastcall sub_4B0720(Instance* self);

Instance* __cdecl findFirstChildByName(Instance* inst) {
    Instance* cur = inst;
    while (cur) {
        Instance* result = sub_630D36(cur, 0, (const char*)0x881f4c, (const char*)0x884e04, 0);
        if (result) {
            return sub_4B0720(result);
        }
        cur = cur->field_bc;
    }
    return 0;
}
