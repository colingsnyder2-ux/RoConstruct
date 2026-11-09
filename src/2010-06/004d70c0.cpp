// from server: 26% by atomic.potato
extern "C" void* __stdcall make_desc_004d1490(const char*, int);
extern "C" void __stdcall free_007a799a(void*);
extern "C" void* __stdcall alloc_007a79a0(unsigned int);
extern "C" void __stdcall func_004096c0();

struct Descriptor_004d1490 {
    void attach(void*);
};

struct Prop {
    void* f_0;
    void* f_4;
    void* f_8;
    void* f_c;
    void* f_10;
    void* f_14;
    void* f_18;
    void* f_1c;
    void set(void*, void*, void*, void*, void*);
};

void Prop::set(void* a, void* b, void* c, void* d, void* e) {
    void* p = make_desc_004d1490((const char*)&a, 0);
    func_004096c0();
    free_007a799a(0);
    f_0 = (void*)0xa00b54;
    void* q = alloc_007a79a0(0x18);
    if (q) {
        *(void**)((char*)q + 8) = d;
        *(void**)q = (void*)0xa19e7c;
        *(void**)((char*)q + 4) = this;
        *(void**)((char*)q + 0x10) = 0;
        *(void**)((char*)q + 0x14) = 0;
    } else {
        q = 0;
    }
    void* old = f_1c;
    if (q != old) {
        free_007a799a(old);
    }
    f_1c = q;
}
