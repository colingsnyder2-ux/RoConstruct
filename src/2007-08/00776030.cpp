// from server: 100% by atomic.potato
extern "C" void __cdecl sub_630D23(void*);

struct T {
    void g(void*, void*);
};

void f() {
    T* p = (T*)0x8C81FC;
    p->g((void*)0x7C3C18, (void*)0x7C3C20);
    sub_630D23((void*)0x77C9E0);
}
