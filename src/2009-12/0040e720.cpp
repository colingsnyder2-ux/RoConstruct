// from server: 100% by atomic.potato
extern "C" int __stdcall sub_405560(void *, void *, void *, void *);

struct S
{
    int f(void *, void *, void *);
};

int S::f(void *a, void *b, void *c)
{
    return sub_405560(a, (void *)0x009a0cc4, b, c);
}
