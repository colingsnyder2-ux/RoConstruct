// from server: 38% by atomic.potato
struct S
{
    int *field;
    void f(void *, void *);
};

extern "C" int __cdecl helper(void *, void *);
extern "C" void invoke(void *, int, void *);

void S::f(void *a, void *b)
{
    int *p = field;
    int *q = (int *)((char *)*p + 16);
    int value = helper((char *)this + 8, a);
    invoke(p, value, b);
}
