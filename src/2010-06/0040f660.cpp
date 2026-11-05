// from server: 18% by atomic.potato
struct S {
    void f();
};

extern "C" void __stdcall sub_7a7f5e();

void S::f() {
    *(int*)this = 0xa0241c;
    sub_7a7f5e();
}
