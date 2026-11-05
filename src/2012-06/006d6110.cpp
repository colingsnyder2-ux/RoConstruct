// from server: 100% by atomic.potato
extern "C" void __fastcall Call97BD60(void *);
extern "C" void __cdecl Call982114(void *);

struct S
{
    char padding[12];
    void *field0C;
    void f();
};

void S::f()
{
    void *p = field0C;
    if (p != 0)
    {
        Call97BD60((char *)p + 4);
        Call97BD60(p);
        Call982114(p);
    }
}
