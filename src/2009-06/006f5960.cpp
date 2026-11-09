// from server: 4% by atomic.potato
struct S_func_0067e6b0 {
    char pad0[180];
    int m_x;
    int f();
};
int S_func_0067e6b0::f()
{
    return m_x;
}

extern "C" void __stdcall _invalid_parameter_noinfo();

struct Inner {
    char pad0[16];
    int m_count;
};

struct Outer {
    char pad0[12];
    int m_a;
    char pad1[4];
    Inner m_inner;
    void f(int);
};

void Outer::f(int)
{
}
