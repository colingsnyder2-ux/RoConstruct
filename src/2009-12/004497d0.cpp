// from server: 100% by atomic.potato
struct S
{
    int value;
    void set(int);
};

extern "C" void __stdcall G1_func_0040c080(int);

void S::set(int value)
{
    if (value == *(int *)((char *)this + 0xa0))
        return;

    *(int *)((char *)this + 0xa0) = value;
    G1_func_0040c080(0xb7afc0);
}
