// from server: 64% by atomic.potato
float g_00651990_value;

struct S_func_00651990
{
    float m_value;
    unsigned short m_code;
    void f(void *);
};

void S_func_00651990::f(void *p)
{
    float *out_value = (float *)p;
    unsigned short *out_code = (unsigned short *)((char *)p + 4);
    *out_value = g_00651990_value - m_value;
    *out_code = (unsigned short)(0 - m_code);
}
