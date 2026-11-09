// from server: 64% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void __stdcall Target(int);

int S::f(int value)
{
    if (value < 0)
        value = 1;
    if (value == *(int *)((char *)this + 0x168))
        return value;
    *(int *)((char *)this + 0x168) = value;
    Target(0xb7eb88);
    return value;
}
