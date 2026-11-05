// from server: 100% by atomic.potato
extern "C" void __cdecl CallFunction(void *);

struct S
{
    void f();
    int unused;
    int field4;
    void *field8;
};

void S::f()
{
    if (field4 != 0)
        CallFunction(field8);
}
