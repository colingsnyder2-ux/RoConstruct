// from server: 65% by atomic.potato
extern "C" void __stdcall std_string_copy(void *, const void *);

struct S {
    int f(void *);
};

int S::f(void *arg)
{
    char *source = (char *)this + 0xf4;
    std_string_copy(arg, source);
    *(int *)((char *)arg + 0x1c) = *(int *)(source + 0x1c);
    return (int)arg;
}
