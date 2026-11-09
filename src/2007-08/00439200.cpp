// from server: 32% by colin
struct MVCXTPPropertyGridItem {
    float f();
};

extern "C" void* __stdcall sub_438e50(void*);
extern "C" bool __cdecl sub_580d70(void*, void*);

extern "C" {
    typedef void* (__stdcall *FnGetCurrentThread)(void);
    typedef void* (__stdcall *FnGetSomething)(void*);
    typedef void (__thiscall *FnDtor)(void*);
    typedef void (__thiscall *FnDtor2)(void*);
    extern FnGetCurrentThread g_fn1;
    extern FnGetSomething g_fn2;
    extern FnDtor g_fn3;
    extern FnDtor2 g_fn4;
}

float MVCXTPPropertyGridItem::f() {
    char buf[8];
    void* p;
    void* q = sub_438e50(&p);
    void* r = g_fn1();
    g_fn2(r);
    bool ok = sub_580d70(&buf[0], &buf[4]);
    g_fn3(&buf[4]);
    g_fn4(&buf[0]);
    if (ok) {
        return *(float*)&buf[4];
    }
    return 0.0f;
}
