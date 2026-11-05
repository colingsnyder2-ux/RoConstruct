// from server: 18% by atomic.potato
struct S {
    void f();
};

extern "C" void __stdcall sub_718ff6();

void S::f() {
    *(int*)this = 0x8aebd8;
    sub_718ff6();
}
