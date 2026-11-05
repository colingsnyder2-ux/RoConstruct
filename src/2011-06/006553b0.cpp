// from server: 76% by atomic.potato
extern "C" void __cdecl destroy_string(void *);
extern "C" void __cdecl operator_delete(void *);

struct S
{
    void f();
    void *pad;
    void *member;
};

void S::f()
{
    void *p = member;
    if (p)
    {
        destroy_string(p);
        operator_delete(p);
    }
}
