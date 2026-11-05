// from server: 37% by atomic.potato
extern "C" void* __stdcall make_desc_004d1490(const char*, int);
extern "C" void __stdcall free_007a799a(void*);
extern "C" void* __stdcall alloc_007a79a0(unsigned int);

struct Descriptor_004d1490 {
    void attach(void*);
};

extern Descriptor_004d1490 global_desc_004d1490;
extern void register_desc_004d1490(void(*)());
extern int name_004d1490;
extern int callback_impl;

struct Init_004d1490 {
    Init_004d1490() {
        void* p = make_desc_004d1490((const char*)&name_004d1490, 0);
        global_desc_004d1490.attach(p);
        register_desc_004d1490((void(*)())&callback_impl);
    }
};

Init_004d1490* func_004d1490() {
    static Init_004d1490 init;
    return &init;
}

struct X_004d6e90 {
    char pad_0[0x1c];
    void* f_1c;
    void ctor_impl(void* a, void* b, void* c, void* d, void* e);
};

void X_004d6e90::ctor_impl(void* a, void* b, void* c, void* d, void* e) {
    void* p = make_desc_004d1490((const char*)a, (int)b);
    void* q = make_desc_004d1490((const char*)c, (int)d);
    (void)q;
    (void)e;
    f_1c = 0;
}

void X_004d6e90_ctor(X_004d6e90* self, void* a, void* b, void* c, void* d, void* e) {
    self->ctor_impl(a, b, c, d, e);
}
