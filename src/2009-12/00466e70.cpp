// from server: 13% by atomic.potato
struct S {
    void f();
};

extern "C" void __stdcall sub_68CA50(int, int, int, int, int);
extern "C" void __stdcall sub_7F4878(int, int);

void S::f() {
    int* p = (int*)this;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    sub_68CA50(0, 0, 0, 0, 0);
    sub_7F4878(0, 0);
}
