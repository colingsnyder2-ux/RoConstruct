// from server: 25% by atomic.potato
extern "C" void* __stdcall make_desc_005b74b0(const char*, int);

struct Descriptor_005b74b0 { void attach(void*); };
extern Descriptor_005b74b0 global_desc_005b74b0;
extern void register_desc_005b74b0(void(*)());
extern int name_005b74b0;
extern int callback_impl;

struct Init_005b74b0 {
    Init_005b74b0() {
        void* p = make_desc_005b74b0((const char*)&name_005b74b0, 0);
        global_desc_005b74b0.attach(p);
        register_desc_005b74b0((void(*)())&callback_impl);
    }
};

Init_005b74b0* func_005b74b0();

extern "C" void __stdcall sub_00599fb0();

extern int dword_C18688;

struct S {
    void* vtbl0;
    void* vtbl4;
    char pad8[0x10];
    void* field18;
    void* field1C;
    void* field20;
    S* ctor();
};

S* S::ctor() {
    sub_00599fb0();
    this->vtbl0 = (void*)0xa2c0f4;
    this->vtbl4 = (void*)0xa2c0e8;
    this->field18 = (void*)0xa2c0dc;
    this->field1C = (void*)0xa2c0d0;
    this->field20 = func_005b74b0();
    dword_C18688++;
    return this;
}
