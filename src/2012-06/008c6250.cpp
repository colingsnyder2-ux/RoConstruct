// from server: 60% by atomic.potato
struct RBX_VirtualHardwareDevice {
    char pad_0[0x88];
    char pad_88[8];
    char pad_90[0x88];
    char pad_118[8];
    void f();
};

extern "C" void __cdecl sub_9756f0(void*);
extern "C" void* __cdecl sub_975560(void*, void*, void*);
extern "C" void* __cdecl sub_44d230(void*, const char*);

extern void* g_b224bc;

void RBX_VirtualHardwareDevice::f() {
    char buf[16];
    sub_9756f0(buf);
    char* edi;
    if ((char*)this + 0x88) {
        edi = (char*)this + 0x90;
    } else {
        edi = 0;
    }
    void* esi = (char*)this + 0x118;
    void* p = sub_975560(buf, (char*)this + 0x118, buf);
    double d = *(double*)p;
    void* r = sub_44d230(edi, (const char*)0xbe65fc);
    void* q = sub_44d230(r, (const char*)0xbe6604);
    (void)q;
    typedef void* (__stdcall *FnT)(void*, double);
    FnT fn = *(FnT*)&g_b224bc;
    fn(r, d);
    void* r2 = sub_44d230(r, (const char*)0xbe65fc);
    (void)r2;
    *(void**)((char*)this + 0x118) = *(void**)buf;
    *(void**)((char*)this + 0x11c) = *(void**)(buf + 4);
}
