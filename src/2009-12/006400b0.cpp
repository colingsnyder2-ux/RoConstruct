// from server: 24% by atomic.potato
struct S {
    void f();
};

extern "C" void __stdcall sub_98b6f0();
extern "C" void __stdcall sub_98b6e4();
extern "C" void __fastcall sub_63f9d0(void*);
extern "C" void __stdcall sub_6400b0();

void S::f() {
    sub_98b6f0();
    sub_63f9d0(this);
    sub_98b6e4();
    sub_98b6e4();
}
