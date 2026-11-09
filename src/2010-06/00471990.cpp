// from server: 93% by atomic.potato
struct S_func_0046e6f0 {
    char pad0[88];
    int m_x;
    int* f();
};

int* S_func_0046e6f0::f()
{
    return &m_x;
}

extern "C" int* __cdecl func_0046e6f0();

struct S_func_0046e3c0 {
    int f(int);
};

struct S_func_0046e390 {
    int f(int);
};

void func_00471990()
{
    int* p = func_0046e6f0();
    if (((S_func_0046e3c0*)p)->f(1))
        ((S_func_0046e390*)p)->f(1);
}
