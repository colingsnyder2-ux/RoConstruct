// from server: 72% by atomic.potato
struct S
{
    void f();
};

extern void G1_func_007b1f10(void *, void *);

void S::f()
{
    void *p = this;
    *(void **)this = (void *)0x00a5b6a0;
    G1_func_007b1f10((void *)0x00cb15a0, &p);
}
