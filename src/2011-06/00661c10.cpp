// from server: 100% by atomic.potato
extern "C" void __cdecl f(void *, void *);

struct S
{
    int f();
};

int S::f()
{
    ::f((void *)0xccdb18, (void *)0x661100);
    return 0xccdb1c;
}
