// from server: 100% by atomic.potato
extern "C" int __cdecl sub_007f4aaa(void *, void *, void *, void *, void *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    return !!sub_007f4aaa(arg, (void *)0, (void *)0xaffe40, (void *)0xb533ec, (void *)0);
}
