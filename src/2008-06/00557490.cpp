// from server: 100% by tester
struct RBX_VInstance_NonFactoryProduct {
    void func_0053e2a0(int, int);
};

void RBX_VInstance_NonFactoryProduct::func_0053e2a0(int a, int b)
{
    struct VTable { char pad[0x3c]; void (__thiscall *fn)(void*, int, int); };
    void* p = *(void**)((char*)this + 0x104);
    if (p) {
        VTable* vt = *(VTable**)p;
        vt->fn(p, a, b);
    }
}
