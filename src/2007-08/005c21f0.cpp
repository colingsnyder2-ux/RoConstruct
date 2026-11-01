// from server: 100% by colin
struct LuaArguments {
    int offset;
    void* L;
    int construct(void* a, int b);
};

extern "C" void* __cdecl sub_586810(void*);
extern "C" void* __cdecl sub_5be5b0(void*, int);
extern "C" void __cdecl sub_5bde00(void*, int, void*);
extern "C" void __cdecl sub_5be160(void*, int);

extern void* dword_8ABE7C;

int __cdecl construct_impl(void* a, int b) {
    void* local;
    void* r = sub_586810(&local);
    void* v = *(void**)r;
    void* p = sub_5be5b0(a, 4);
    if (p) {
        *(void**)p = v;
    }
    sub_5bde00(a, -10000, dword_8ABE7C);
    sub_5be160(a, -2);
    return 1;
}

int LuaArguments::construct(void* a, int b) {
    return construct_impl(a, b);
}
