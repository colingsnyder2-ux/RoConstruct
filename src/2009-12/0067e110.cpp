// from server: 84% by atomic.potato
struct Sub {
    char pad0[0x144];
    struct VT {
        char pad0[0x10];
        void (__stdcall *fn)(void*);
    } *vt;
};

struct ModelInstance {
    char pad0[0xb4];
    void f(void*);
};

extern "C" void __stdcall sub_783000(void*, void*);
extern "C" Sub* __stdcall sub_6e55b0(void*);

void ModelInstance::f(void* a)
{
    Sub* s = (Sub*)((char*)this - 0xb4);
    sub_783000(s, a);
    Sub* r = sub_6e55b0(s);
    if (r) {
        Sub::VT* v = r->vt;
        v->fn(a);
    }
}
