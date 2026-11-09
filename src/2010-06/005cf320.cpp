// from server: 100% by atomic.potato
struct S {
    char pad[12];
    void* p;

    void f();
};

extern "C" void __fastcall f795310(void*);
extern "C" void __cdecl f7a799a(void*);

void S::f() {
    void* p = this->p;
    if (p != 0) {
        f795310((char*)p + 4);
        f795310(p);
        f7a799a(p);
    }
}
