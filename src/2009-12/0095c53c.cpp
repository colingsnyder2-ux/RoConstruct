// from server: 62% by atomic.potato
extern "C" void __cdecl f007f539a(int, int);

struct S
{
    void f(int);
};

void S::f(int value)
{
    f007f539a(*(int *)(value - 4) ^ value, value);
}
