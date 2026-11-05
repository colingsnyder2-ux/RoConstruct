// from server: 26% by atomic.potato
extern "C" void* __cdecl sub_7A79A0(unsigned int size);
extern "C" void __cdecl sub_654D40(void* self, int flag);
extern "C" void __cdecl sub_469D00(void* self, void* a, void* b);

struct RBX_VCamera_FactoryProduct_Creator {
    void* __cdecl create(void* arg);
};

void* RBX_VCamera_FactoryProduct_Creator::create(void* arg) {
    void* mem = sub_7A79A0(0x290);
    void* obj = 0;
    if (mem != 0) {
        sub_654D40(mem, 1);
        obj = mem;
    }
    sub_469D00(this, obj, arg);
    return this;
}
