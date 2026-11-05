// from server: 20% by Intel
struct S {
    void f();
};

extern "C" void __stdcall call1();
extern "C" void __stdcall call2();

void S::f() {
    char padding[4];
    *(int*)padding = 0;
    *(int*)((char*)this + 0) = *(int*)0xabaf88;
    call1();
    call2();
}
