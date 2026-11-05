// from server: 45% by atomic.potato
struct Sub1 {
    void f();
};

struct Sub2 {
    void f();
};

struct Sub3 {
    void f();
};

struct Sub4 {
    void f();
};

struct Obj {
    char pad0[0x8c];
    void* ptr8c;
    char pad90[0x38];
    Sub3 sub_c8;
    Sub2 sub_cc;
    Sub1 sub_d0;
    void g();
};

extern "C" void __cdecl free_982114(void* p);

void Obj::g()
{
    sub_d0.f();
    sub_cc.f();
    sub_c8.f();
    void* p = ptr8c;
    if (p) {
        void* q = *(void**)((char*)p + 4);
        if (q) {
            free_982114(q);
        }
        *(void**)((char*)p + 4) = 0;
        *(void**)((char*)p + 8) = 0;
        *(void**)((char*)p + 0xc) = 0;
        free_982114(p);
    }
    ((void (__thiscall*)(Obj*))0x685090)(this);
}
