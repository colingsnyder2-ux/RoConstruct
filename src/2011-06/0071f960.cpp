// from server: 53% by atomic.potato
struct S_func_0066c140 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_0066c140::f()
{
    return &m_x;
}

extern "C" int* __stdcall func_0066c140(S_func_0066c140*);

extern "C" void __stdcall func_0075ece0(int*, int, int);

void __stdcall func_0071f960(int* p, int a, int b)
{
    S_func_0066c140* q;
    int* r;

    if (p)
        q = (S_func_0066c140*)((char*)p - 28);
    else
        q = 0;

    r = func_0066c140(q);
    func_0075ece0(r + 2, a, b);
}
