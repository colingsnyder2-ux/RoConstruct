// from server: 36% by atomic.potato
extern "C" void* __stdcall make_desc_0058f130(const char*, int);
extern "C" void* __stdcall sub_0058cdb0(int, int, int, int, int, int, int);
extern "C" void __stdcall sub_0080a058(void*);
extern "C" void __stdcall sub_004e3060();

struct Descriptor_0058f130 { void attach(void*); };
extern Descriptor_0058f130 global_desc_0058f130;
extern void register_desc_0058f130(void(*)());
extern int name_0058f130;
extern int callback_impl;

struct Init_0058f130 {
    Init_0058f130() {
        void* p = make_desc_0058f130("TaskScheduler", 27);
        global_desc_0058f130.attach(p);
        register_desc_0058f130((void(*)())&callback_impl);
    }
};

Init_0058f130* func_0058f130() {
    static Init_0058f130 init;
    return &init;
}

struct S {
    void* vtable;
    int f(int, int, int, int, int, int, int);
};

int S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    void* p = sub_0058cdb0(a1, a2, a3, a4, a5, a6, a7);
    int saved = *(int*)p;
    *(int*)p = 0;
    int local = saved;
    void* q = func_0058f130();
    sub_004e3060();
    if (local)
        sub_0080a058((void*)local);
    this->vtable = (void*)0xa89030;
    return (int)this;
}
