// from server: 47% by atomic.potato
struct S {
    void f();
};

extern "C" void __cdecl sub_a814d5(int);
extern "C" void __stdcall func_e085a8();

void S::f() {
    sub_a814d5(1);
    func_e085a8();
}
