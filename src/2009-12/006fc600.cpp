// from server: 60% by atomic.potato
struct S
{
    void f(void *arg);
};

extern "C" void call_7bbf80(S *, void *, void *, void *);

void S::f(void *arg)
{
    void *slot;
    call_7bbf80((S *)((char *)this - 0x98), &slot, (void *)0x6fc070, arg);
}
