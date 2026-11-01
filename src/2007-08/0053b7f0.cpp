// from server: 100% by colin
struct RBX_Instance {
    char pad[0xbc];
    RBX_Instance* next;
};

extern "C" void* __cdecl sub_630D36(void* a, void* b, void* c, void* d, void* e);
extern "C" void* __fastcall sub_4554B0(void* self);

void* __cdecl sub_53B7F0(RBX_Instance* p)
{
    while (p) {
        void* r = sub_630D36(p, 0, (void*)0x881f4c, (void*)0x884e04, 0);
        if (r)
            return sub_4554B0(r);
        p = p->next;
    }
    return 0;
}
