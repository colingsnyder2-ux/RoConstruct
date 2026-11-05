// from server: 59% by atomic.potato
struct S_func_006927a0
{
    char pad0[140];
    char m_data[32];
    void *f(void *arg);
};

extern "C" void std_string_copy(void *, const void *);

void *S_func_006927a0::f(void *arg)
{
    std_string_copy(arg, this + 140);
    *(int *)((char *)arg + 28) = *(int *)((char *)this + 168);
    return arg;
}
