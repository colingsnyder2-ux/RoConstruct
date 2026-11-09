// from server: 25% by atomic.potato
extern "C" void* __stdcall make_desc_00590d30(const char*, int);
extern "C" void* __stdcall alloc_0058e790(int);
extern "C" void __stdcall free_00591007(void*);
extern "C" void __stdcall func_007a799a(void*);

struct Descriptor_00590d30 { void attach(void*); };
extern Descriptor_00590d30 global_desc_00590d30;
extern void register_desc_00590d30(void(*)());
extern int name_00590d30;
extern int callback_impl;

struct Init_00590d30 {
    Init_00590d30() {
        void* p = make_desc_00590d30((const char*)&name_00590d30, 0);
        global_desc_00590d30.attach(p);
        register_desc_00590d30((void(*)())&callback_impl);
    }
};

struct S {
    void* f(void*, void*, void*, void*, void*, void*, void*, void*);
};

void* S::f(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7, void* a8)
{
    void* p = alloc_0058e790(0x10);
    void* q = *(void**)p;
    *(void**)p = 0;
    void* r = &q;
    void* s = make_desc_00590d30((const char*)a3, 0);
    free_00591007(a4);
    *(void**)this = (void*)0xa28f14;
    return this;
}
