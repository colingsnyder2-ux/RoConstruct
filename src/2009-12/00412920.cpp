// from server: 32% by atomic.potato
extern "C" void __stdcall sub_410D60();
extern "C" void __stdcall sub_4126E0();

struct S {
    void f();
};

void S::f() {
    sub_410D60();
    sub_4126E0();
}
