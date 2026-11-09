// from server: 61% by atomic.potato
extern float g_00666d60;

struct S_00666d60 {
    char pad0[0xc4];
    int m_c4;
    float m_c8;
    void f_00664830(int, float);
    void f_00666d60(int, int, float);
};

void S_00666d60::f_00666d60(int a, int b, float c)
{
    float v = (float)a * m_c8 * c * g_00666d60;
    f_00664830(b, v);
    m_c4++;
}
