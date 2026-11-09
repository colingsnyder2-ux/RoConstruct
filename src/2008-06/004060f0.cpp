// from server: 100% by atomic.potato
extern "C" void __stdcall Function006A095C(int, int);

struct S
{
    int a;
    int b;
    int c;
    int d;
    void f();
};

void S::f()
{
    if (b != 0)
        *(int *)(b + 4) = a;
    if (d != 0)
        Function006A095C(0, c);
}
