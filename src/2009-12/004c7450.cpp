// from server: 62% by atomic.potato
extern "C" void __cdecl fn004c6840();
extern "C" void __cdecl fn007f4878(const char *, void *);

struct S {
    void f();
};

void S::f()
{
    fn004c6840();
    fn007f4878("D$ P", (void *)0);
}
