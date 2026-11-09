// from server: 67% by atomic.potato
extern "C" void __stdcall sub_65af30(void *, void *, int);

struct S
{
    int f(void *);
};

int S::f(void *p)
{
    sub_65af30(*(void **)((char *)this + 0xac), p, 0);
    return (int)p;
}
