// from server: 82% by atomic.potato
extern "C" void __stdcall sub_4f2860(int, int, int*);

struct S {
    void f(int, int);
};

void S::f(int a, int b) {
    int tmp[2];
    sub_4f2860(b, a, tmp);
}
