// from server: 73% by atomic.potato
struct S_func_00684090 {
    char pad0[44];
    void *m_data;
    void f(void *p);
};

extern "C" void sub_0046A960(void *);

void S_func_00684090::f(void *p)
{
    if (p)
        sub_0046A960((char *)m_data + ((char *)p - (char *)0x1c));
    else
        sub_0046A960(m_data);
}
