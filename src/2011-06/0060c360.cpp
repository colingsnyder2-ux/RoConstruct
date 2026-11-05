// from server: 52% by atomic.potato
struct S
{

    void __stdcall f(void *a, void *b, void *c);
};

extern "C" void __stdcall f(void *, void *, void *);

void __stdcall S::f(void *a, void *b, void *c)
{
    char x[8];
    f(x, (void *)0x60af90, (char *)x + 12);
}
