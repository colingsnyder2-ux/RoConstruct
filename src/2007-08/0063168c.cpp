// from server: 61% by colin
extern "C" void __stdcall sub_631620(int);

struct S {
    void f();
};

void S::f() {
    sub_631620(0xc);
    *(int *)((char *)this - 4) = 0;
    *(int *)((char *)this - 0x1c) = 1;
}
