// from server: 66% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void G1_func_0084e3c0(void *, int, int);

int S::f(int value)
{
    G1_func_0084e3c0((char *)this + 4, value, 0);
    return value;
}
