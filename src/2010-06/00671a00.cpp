// from server: 57% by atomic.potato
struct S
{
    void f(int, int);
};

extern "C" void *__cdecl sub_7a8bea(void *, void *, void *, void *, void *);
extern "C" void *__cdecl sub_7a89b2(void *, void *);
extern "C" void *__stdcall sub_9ea89c(void *);
extern "C" void __fastcall sub_671940(void *, void *, void *);

struct bad_cast
{
    bad_cast(const char *);
};

void S::f(int a, int b)
{
    void *p = sub_7a8bea((void *)a, 0, (void *)0xb79040, (void *)0xb87d34, 0);
    if (!p)
    {
        char buf[4];
        sub_9ea89c(buf);
        sub_7a89b2(buf, (void *)0xb12290);
    }
    sub_671940(this, p, (char *)&b + 4);
}
