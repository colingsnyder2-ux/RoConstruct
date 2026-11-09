// from server: 100% by atomic.potato
extern "C" void __stdcall G1_func_0040c080(int);

struct S
{
    int padding[54];
    int value;
    void f(int);
};

void S::f(int value)
{
    if (value != this->value)
    {
        this->value = value;
        G1_func_0040c080(0x00b7b1e0);
    }
}
