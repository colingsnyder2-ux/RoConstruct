// from server: 100% by atomic.potato
struct S {
    int value[43];
    void f(int);
};

extern "C" void __stdcall g(const char *);

void S::f(int x)
{
    if (x != value[42]) {
        value[42] = x;
        g(0);
    }
}
