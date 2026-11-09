// from server: 67% by atomic.potato
extern "C" void __stdcall sub_74F980(void *, void *, int);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    void *p = *(void **)((char *)this + 0x9c);
    sub_74F980(p, arg, 0);
    return (int)arg;
}
