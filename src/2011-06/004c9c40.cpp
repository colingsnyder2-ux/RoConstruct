// from server: 59% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void callee(void *, int *, int *);

int S::f(int value)
{
    int result = 0;
    callee((char *)this + 0x1d4, &result, &value);
    return value;
}
