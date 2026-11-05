// from server: 60% by atomic.potato
struct S_func_007a2e50 {
    char pad[204];
    float m_x;
    float f();
};

struct S_func_007a3560 {
    char pad[204];
    void g(float);
};

struct S {
    char pad[0xb4];
    S_func_007a3560* m_p;
    void h(float);
};

extern void G1_func_00411f60();

void S::h(float a)
{
    float v = ((S_func_007a2e50*)m_p)->f();
    if (a == v)
        return;
    m_p->g(a);
    G1_func_00411f60();
}
