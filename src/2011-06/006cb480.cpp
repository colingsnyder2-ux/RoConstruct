// from server: 80% by atomic.potato
extern "C" void __cdecl Call6a5fc0(void *);
extern "C" void __cdecl Call411f60(void *, const void *);

struct S
{
    void f();
};

void S::f()
{
    Call6a5fc0(this);
    Call411f60(this, (const void *)0xcd1164);
    Call411f60(this, (const void *)0xcd1120);
}
