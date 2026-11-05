// from server: 55% by atomic.potato
extern "C" void __cdecl sub_007e0b20(float, float, int);

struct S
{
    virtual void f();
    int value;
    void g(float);
};

void S::g(float x)
{
    f();
    sub_007e0b20(x, *(float *)((char *)this + 0x10), value);
}
