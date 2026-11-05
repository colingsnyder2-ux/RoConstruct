// from server: 84% by atomic.potato
extern "C" void Call4883b0(void *);
extern "C" void __cdecl Call7f385a(void *);

struct S
{
    void *value;
    void f();
};

void S::f()
{
    void *p = value;
    if (p)
    {
        Call4883b0(p);
        Call7f385a(p);
        value = 0;
    }
}
