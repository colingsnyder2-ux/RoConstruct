// from server: 100% by colin
struct RBX_Instance {
    char pad[0xbc];
    RBX_Instance* field_bc;
};

extern "C" void* __cdecl sub_630d36(RBX_Instance* p, int a, void* b, void* c, int d);
extern "C" void* __fastcall sub_45a430(void* p);

void* __cdecl sub_57d4d0(RBX_Instance* p)
{
    while (p != 0) {
        void* r = sub_630d36(p, 0, (void*)0x881f4c, (void*)0x884e04, 0);
        if (r != 0) {
            return sub_45a430(r);
        }
        p = p->field_bc;
    }
    return 0;
}
