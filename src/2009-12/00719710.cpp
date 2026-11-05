// from server: 38% by atomic.potato
struct Sub1 { void f(); };
struct Sub2 { void g(); };
struct Sub3 { void h(); };

extern "C" void __stdcall sub_540ae0();
extern "C" void __stdcall sub_7f385a(void*);
extern "C" void __stdcall sub_41af50();
extern "C" void __stdcall sub_98b6e4();
extern "C" void __stdcall sub_668630();
extern "C" void __stdcall sub_637b00();

struct S {
    void* vt0;
    void* vt1;
    char pad0[0x10];
    void* vt18;
    void* vt1c;
    char pad1[0x78];
    char sub98[0x0c];
    char suba4[0x20];
    char subc4[0x08];
    char subcc[0x08];
    void* ptrd4;
    void* ptrd8;
    void dtor();
};

void S::dtor()
{
    vt0 = (void*)0x9cee34;
    vt1 = (void*)0x9cee28;
    vt18 = (void*)0x9cee1c;
    vt1c = (void*)0x9cee14;

    void* p = ptrd8;
    if (p) {
        sub_540ae0();
        sub_7f385a(p);
    }
    p = ptrd4;
    if (p) {
        sub_540ae0();
        sub_7f385a(p);
    }
    sub_41af50();
    sub_41af50();
    sub_98b6e4();
    sub_668630();
    sub_637b00();
}
