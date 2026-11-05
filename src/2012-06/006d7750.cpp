// from server: 82% by atomic.potato
extern "C" void sub_006d7620(void *);
extern "C" void __cdecl sub_00982114(void *);

struct S
{
    S *f(int);
};

S *S::f(int flags)
{
    S *p = (S *)((char *)this - 12);
    sub_006d7620(p);
    if (flags & 1)
        sub_00982114(p);
    return p;
}
