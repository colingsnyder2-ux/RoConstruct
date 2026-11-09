// from server: 31% by atomic.potato
struct Point
{
    int pad0[3];
    struct Owner
    {
        int pad1[12];
        int value;
    } *owner;

    void f();
};

extern "C" void __cdecl Function758D30(void *, void *);

void Point::f()
{
    Owner *a = owner;
    int *b = *(int **)((char *)a + 0x30);
    void *c = *(void **)((char *)b + 0x38);
    if (c)
        Function758D30((char *)this + 0x28, (char *)this + 0x1c);
}
