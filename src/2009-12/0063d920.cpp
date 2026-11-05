// from server: 100% by atomic.potato
extern "C" void __stdcall target(int);

struct S
{
    void f(int);
    int value[38];
};

void S::f(int x)
{
    if (value[37] == x)
        return;

    value[37] = x;
    target(0xb85aec);
}
