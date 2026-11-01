// from server: 100% by colin
struct RBX_VModelInstance {
    char pad[0xbc];
    void* field_bc;
    void FactoryProduct();
};

extern "C" void* __cdecl sub_630d36(void*, void*, void*, void*, void*);

void RBX_VModelInstance::FactoryProduct()
{
    void* p = sub_630d36(field_bc, 0, (void*)0x881f4c, (void*)0x898fc0, 0);
    if (p) {
        void** vt = *(void***)p;
        void* fn = vt[0x54 / 4];
        typedef void (__thiscall *Fn)(void*);
        ((Fn)fn)(p);
    }
}
