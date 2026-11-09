// from server: 44% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int* __cdecl G1_func_0046e6f0();
extern "C" void G1_func_0046d930(int*, int, int);

int S::f(int x)
{
    int* p = G1_func_0046e6f0();
    G1_func_0046d930(p, 1, 1);
    return x;
}
