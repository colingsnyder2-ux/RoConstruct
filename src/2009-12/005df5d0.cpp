// from server: 55% by atomic.potato
extern "C" void __cdecl sub_007f4878(const char *, const char *, int);

struct S
{
    void f();
};

void S::f()
{
    const char *p = (const char *)0x009c163c;
    sub_007f4878("shouldn't be here", (const char *)&p, 0);
}
