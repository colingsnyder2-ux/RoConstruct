// from server: 48% by atomic.potato
struct S_func_0066c140 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_0066c140::f()
{
    return &m_x;
}

struct S {
    int f(void*, int, int);
};

extern "C" int* __cdecl call_0066c140(S_func_0066c140*);

extern "C" int __stdcall call_0075ece0(int*, int, int);

int S::f(void* p, int a, int b)
{
    int* q = p ? call_0066c140((S_func_0066c140*)((char*)p - 28)) : call_0066c140(0);
    return call_0075ece0(q + 4, a, b);
}
