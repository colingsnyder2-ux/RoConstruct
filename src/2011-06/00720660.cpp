// from server: 38% by atomic.potato
struct Prop {
    char pad0[0x20];
    void* obj;
};

extern "C" void* __stdcall sub_592E10(void*);

struct S {
    char pad0[0x20];
    Prop* p;
    char f(void* a, void* b);
};

extern "C" char __fastcall sub_5A8570(void*, void*);

char S::f(void* a, void* b) {
    void* v;
    if (!sub_5A8570(this, sub_592E10(&v))) return 0;
    void* o = p->obj;
    void* vt = *(void**)o;
    void (*fn)(void*, void*, void*) = *(void (**)(void*, void*, void*))((char*)vt + 0xc);
    fn(o, a, b);
    return 1;
}
