// from server: 69% by atomic.potato
struct S
{
    int pad[53];
    void f(int);
};

extern "C" void __declspec(noreturn) G1_func_0040c080(int, int);

void S::f(int value)
{
    if (this->pad[53] != value)
    {
        this->pad[53] = value;
        G1_func_0040c080(0x00B7B1A0, value);
    }
}
