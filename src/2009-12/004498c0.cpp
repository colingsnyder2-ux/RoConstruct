// from server: 100% by atomic.potato
extern "C" void __stdcall G1_func_0040c080(int);

struct S
{
    void __thiscall f(int);
    char padding[0xc0];
    int value;
};

void __thiscall S::f(int value)
{
    if (value != this->value)
    {
        this->value = value;
        G1_func_0040c080(0x00b7b0d8);
    }
}
