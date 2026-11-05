// from server: 75% by atomic.potato
extern "C" void __stdcall SetValue(void *, int *);

struct S
{
    char padding[0x2f4];
    int value;
    void f(int *);
};

void S::f(int *p)
{
    if (value != (int)p)
    {
        value = (int)p;
        SetValue(this, (int *)0x00c20ea4);
    }
}
