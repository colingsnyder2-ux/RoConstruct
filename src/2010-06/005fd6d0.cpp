// from server: 72% by atomic.potato
struct S
{
    int (__thiscall *get)(void *, void *);
    void *data;
    void *context;
    int f(void *, void *);
};

extern "C" void *string_copy(void *, const void *);

int S::f(void *result, void *value)
{
    void *p = 0;
    if (value != 0)
        p = (char *)value - 0x1c;

    int r = get((char *)context + (int)p, 0);
    string_copy(result, (const void *)r);
    return (int)result;
}
