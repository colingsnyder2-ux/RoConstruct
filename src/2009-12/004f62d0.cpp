// from server: 95% by atomic.potato
extern "C" void __cdecl G1_func_007f3b06(void *);

struct S
{
    void *value;
    int unknown;
    int size;
    void f();
};

void S::f()
{
    if (size <= 8)
    {
        if (value != 0)
            G1_func_007f3b06(value);
    }
}
