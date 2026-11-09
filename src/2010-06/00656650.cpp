// from server: 76% by atomic.potato
struct S_func_00656650
{
    char pad[76];
    void *m_value;
    void *f();
};

extern "C" void *__cdecl sub_007a8bea(void *, void *, void *, void *, void *);

void *S_func_00656650::f()
{
    void *v = sub_007a8bea(m_value, 0, (void *)0xb78e40, (void *)0xbb56cc, 0);
    return v;
}
