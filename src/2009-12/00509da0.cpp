// from server: 41% by atomic.potato
struct S
{
    char pad[0x34];
    int field34;
    void f(void*, int);
};

extern "C" void __stdcall sub_506eb0(int, int);

void S::f(void* a, int b)
{
    if (a != 0)
    {
        sub_506eb0(field34 + ((int)a - 0x1c), b);
    }
    else
    {
        sub_506eb0(field34, b);
    }
}
