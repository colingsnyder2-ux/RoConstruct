// from server: 47% by atomic.potato
struct S_func_007b2f20 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct S_func_007b8fc0 {
    char pad0[4];
    void f(int a1);
};

struct S_func_007daf10 {
    char pad0[4];
    void f(int a1);
};

struct S {
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007b2f20::f(int a1)
{
    m_x = (int)a1;
}

void S::f(int a1)
{
    ((S_func_007b2f20*)this)->f(a1);
    ((S_func_007b8fc0*)m_x)->f(a1);
    ((S_func_007daf10*)(a1 + 8))->f(m_x);
}
