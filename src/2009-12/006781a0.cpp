// from server: 60% by atomic.potato
struct S
{
    int f();
};

extern "C" void CallTarget(void *, int);

int S::f()
{
    void *p = *(void **)((char *)this + 12);
    void *q = *(void **)((char *)p + 0x120);
    void (*fn)(void *) = (void (*)(void *))(*(void **)((char *)q + 8));
    fn((void *)((char *)p + 0x120));
    CallTarget(q, 1);
    return 0;
}
