// from server: 57% by atomic.potato
extern "C" void std_string_copy(void *, const void *);

struct S_func_0070f360
{
    char pad0[552];
    void f(const void *);
};

void S_func_0070f360::f(const void *source)
{
    char *target = pad0 + 552;
    std_string_copy(target, source);
}
