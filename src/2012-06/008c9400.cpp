// from server: 73% by atomic.potato
extern "C" void sub_00683ab0(void *);

struct S_func_008c9400 {
    char pad0[44];
    char *m_data;
    void f(void *);
};

void S_func_008c9400::f(void *arg)
{
    if (arg)
        sub_00683ab0(m_data + ((char *)arg - (char *)0) - 28);
    else
        sub_00683ab0(m_data);
}
