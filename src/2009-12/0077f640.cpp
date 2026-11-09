// from server: 65% by atomic.potato
extern "C" void __cdecl CallAt6ed620(void *);

struct S
{
    void **vftable;
    int unused0;
    int unused1;
    int unused2;
    void *first;
    void *second;
    void f(float value);
};

void S::f(float value)
{
    CallAt6ed620(first);
    CallAt6ed620(second);
    ((void (__thiscall *)(S *, float))vftable[7])(this, value);
}
