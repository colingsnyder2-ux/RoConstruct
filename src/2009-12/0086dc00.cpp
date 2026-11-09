// from server: 84% by atomic.potato
struct S
{
    char pad[0x2c];
    void *m_2c;

    void *f(void *);
};

void *sub_86ac70(void *, void *, void *);

void *S::f(void *arg)
{
    void *value = m_2c;
    sub_86ac70((char *)this + 0x24, value, arg);
    return value;
}
