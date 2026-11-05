// from server: 25% by atomic.potato
extern "C" void* __cdecl sub_7A79A0(unsigned int size);
extern "C" void __cdecl sub_5C72D0(void* p);
extern "C" void __cdecl sub_5C2AD0(void* self, void* a, void* b);

struct RBX_VObjectValue_FactoryProduct_Creator {
    void* __cdecl method(void* arg);
};

void* RBX_VObjectValue_FactoryProduct_Creator::method(void* arg) {
    void* p = sub_7A79A0(0xA4);
    void* q = 0;
    if (p != 0) {
        sub_5C72D0(p);
        q = p;
    }
    sub_5C2AD0(this, q, arg);
    return this;
}
