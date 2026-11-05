// from server: 43% by colin
extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl construct_at(void* dest, void* src);

struct Vsignal_base_impl_sp_counted_impl_p {
    void* create(void* a, void* b, void* c);
};

void* Vsignal_base_impl_sp_counted_impl_p::create(void* a, void* b, void* c) {
    void* p = operator_new(0x18);
    if (p) {
        *(void**)p = a;
    }
    void* q = (char*)p + 4;
    if (q) {
        *(void**)q = b;
    }
    construct_at((char*)p + 8, c);
    return p;
}
