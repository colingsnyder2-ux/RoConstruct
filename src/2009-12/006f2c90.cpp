// from server: 48% by atomic.potato
struct S_func_006cb2b0
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

extern "C" int* f_006cb2b0(S_func_006cb2b0*);

extern "C" void f_0071d610(int*, int, int);

struct S
{
    void f(int*, int, int);
};

void S::f(int* p, int a, int b)
{
    int* x;
    if (p)
        x = f_006cb2b0((S_func_006cb2b0*)((char*)p - 28));
    else
        x = f_006cb2b0(0);
    f_0071d610(x + 10, a, b);
}
