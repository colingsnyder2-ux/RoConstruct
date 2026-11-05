// from server: 70% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" void *__stdcall std_string_copy(void *, const void *);

int S::f(void *arg)
{
    std_string_copy((char *)this + 0xc94, arg);
    return (int)arg;
}
