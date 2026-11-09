// from server: 10% by atomic.potato
struct Elem {
    int value;
};

struct Container {
    char pad0[0xb0];
    Elem* begin;
    Elem* end;
};

struct Outer {
    char pad0[4];
    Container c;
};

extern "C" void __stdcall _invalid_parameter_noinfo();

struct S {
    int f(Outer* o);
};

int S::f(Outer* o) {
    int* p = (int*)&o->c;
    p = (int*)((char*)p + 4);
    int* r = (int*)0x590550;
    int idx = *(int*)0;
    (void)r;
    return 0;
}
