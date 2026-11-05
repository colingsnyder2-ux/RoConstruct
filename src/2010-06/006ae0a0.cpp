// from server: 41% by atomic.potato
extern "C" void* __stdcall make_desc_005b7280(const char*, int);
extern "C" void __stdcall free_007a799a(void*);
extern "C" void* __stdcall alloc_007a79a0(unsigned int);
extern "C" void __stdcall sub_004096c0(void*, void*);

struct VNetworkSettings {
    char pad0[0x1c];
    void* field_1c;
    void* construct(void* a, void* b, void* c, void* d, void* e, void* f, void* g);
};

void* VNetworkSettings::construct(void* a, void* b, void* c, void* d, void* e, void* f, void* g)
{
    void* desc = make_desc_005b7280((const char*)0, 0);
    sub_004096c0(this, desc);
    free_007a799a(0);
    this->field_1c = 0;
    *(void**)this = (void*)0xa00b54;
    void* p = alloc_007a79a0(0x18);
    if (p) {
        *(void**)p = (void*)0xa412cc;
        *((void**)p + 1) = this;
        *((void**)p + 2) = a;
        *((void**)p + 4) = b;
        *((void**)p + 5) = c;
    } else {
        p = 0;
    }
    void* old = this->field_1c;
    if (p != old) {
        free_007a799a(old);
    }
    this->field_1c = p;
    return this;
}
