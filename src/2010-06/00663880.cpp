// from server: 80% by atomic.potato
extern "C" void G1_func_0040C470();

struct S
{
    unsigned char padding[149];
    unsigned char value;
    void f(unsigned char);
};

void S::f(unsigned char v)
{
    if (value != v)
    {
        value = v;
        G1_func_0040C470();
    }
}
