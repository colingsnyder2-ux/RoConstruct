// from server: 53% by atomic.potato
struct S
{
    void __cdecl f(void *);
};

struct T
{
    char data[1];
};

extern "C" void sub_7043a0(T *, void *, int, int);

void S::f(void *p)
{
    T *v = *(T **)p;
    char x = 0;
    sub_7043a0((T *)((char *)v + 8), &x, 0, 0);
}
