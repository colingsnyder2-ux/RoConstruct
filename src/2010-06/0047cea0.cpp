// from server: 50% by atomic.potato
struct S
{
    void f(int);
};

extern "C" void G1_func_00409630(void *, void *);

void S::f(int value)
{
    G1_func_00409630((char *)this + 0x154, &value);
}
