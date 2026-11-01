// from server: 72% by atomic.potato
struct Inner {
    char pad0[8];
    char m_flag;
    char pad1[0x84 - 9];
    float m_x;
    float m_y;
    float m_z;
    void method();
};

struct Middle {
    char pad0[0x38];
    Inner* m_inner;
};

struct Outer {
    char pad0[0x30];
    Middle* m_mid;
    void f(float* v);
};

void Outer::f(float* v)
{
    Inner* p = m_mid->m_inner;
    if (p != 0) {
        if (p->m_flag != 0) {
            p->method();
        }
        p->m_x += v[0];
        p->m_y += v[1];
        p->m_z += v[2];
    }
}
