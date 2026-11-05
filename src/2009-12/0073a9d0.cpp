// from server: 100% by atomic.potato
extern "C" void __cdecl G1_func_0078a200(int, int, int);

struct S
{
    void f();
    int value;
    int count;
};

void S::f()
{
    if (value)
    {
        G1_func_0078a200(value, -10000, count);
        count = 0;
        value = 0;
    }
}
