// from server: 100% by colin
struct RBX_Instance;

struct RBX_InstanceVtbl {
    void* pad[0x13];
    void (__thiscall *fn4c)(RBX_Instance*);
    void (__thiscall *fn50)(RBX_Instance*);
};

struct RBX_Instance {
    RBX_InstanceVtbl* vtbl;
};

extern "C" RBX_Instance* __cdecl sub_630d36(int, int, void*, void*, int);

void __stdcall sub_5baf60(int a1)
{
    RBX_Instance* p = sub_630d36(a1, 0, (void*)0x881f4c, (void*)0x898fc0, 0);
    if (p) {
        p->vtbl->fn4c(p);
        p->vtbl->fn50(p);
    }
}
