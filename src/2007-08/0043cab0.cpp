// from server: 100% by colin
struct MVCXTPPropertyGridItem {
    bool f();
};

extern "C" void* __stdcall sub_438e50(void*);

extern "C" {
    typedef bool (__thiscall *Fn1)(void*);
    typedef void (__thiscall *Fn2)(void*);
    extern Fn1 g_fn1;
    extern Fn2 g_fn2;
}

bool MVCXTPPropertyGridItem::f() {
    void* p;
    void* q = sub_438e50(&p);
    bool r = g_fn1(q);
    g_fn2(&p);
    return r;
}
