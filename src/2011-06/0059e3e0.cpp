// from server: 61% by atomic.potato
extern "C" void basic_string_copy(void *, const void *);

struct S_func_0059e3e0 {
    char pad0[156];
    void *m_string;
    void *f(void *);
};

void *S_func_0059e3e0::f(void *arg)
{
    basic_string_copy(arg, (char *)this + 156);
    *(void **)((char *)arg + 28) = *(void **)((char *)this + 184);
    return arg;
}
