// from server: 37% by atomic.potato
struct S
{
    void f();
};

typedef void (__cdecl Fn)(void *);

void S::f()
{
    Fn *fn = (Fn *)0x004d62e0;
    fn((void *)0x00b7dcd0);
}
