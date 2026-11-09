// from server: 54% by atomic.potato
extern "C" void __cdecl fn_a814d5(int);

extern "C" int __cdecl fn_e085e8(int, int, float);

struct S
{
    int f(int, int, float);
};

int S::f(int a, int b, float c)
{
    fn_a814d5(1);
    return fn_e085e8(a, b, c);
}
