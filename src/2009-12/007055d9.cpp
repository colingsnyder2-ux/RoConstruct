// from server: 37% by atomic.potato
extern "C" void __cdecl G1_func_006c7390(void *);

struct S
{
    void *value;
    void *context;
    unsigned char enabled;
    void *f();
};

void *S::f()
{
    if (enabled)
    {
        G1_func_006c7390(value);
        return (void *)0x7055f5;
    }
    return 0;
}
