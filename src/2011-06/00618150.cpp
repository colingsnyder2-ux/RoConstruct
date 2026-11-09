// from server: 100% by atomic.potato
extern "C" void __cdecl sub_7631e0(int, int, int);

struct S
{
    char padding[0x98];
    int value;
    void f();
};

void S::f()
{
    if (value)
        sub_7631e0(value, 2, 0);
}
