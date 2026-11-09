// from server: 23% by atomic.potato
extern "C" {
    void __stdcall G1_func_009ea410();
    void __stdcall G1_func_009ea400();
}
extern void G1_func_005e3830();

struct S {
    void f(int);
};

void S::f(int a)
{
    char buf[8];
    G1_func_009ea410();
    G1_func_005e3830();
    G1_func_009ea400();
}
