// from server: 100% by atomic.potato
extern "C" void __stdcall G1_func_0040C080(int);

struct S
{
    void f(int);
};

void S::f(int value)
{
    if (value == *(int*)((char*)this + 0x9c))
        return;
    *(int*)((char*)this + 0x9c) = value;
    G1_func_0040C080(0xb7af98);
}
