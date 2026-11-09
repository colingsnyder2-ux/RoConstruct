// from server: 72% by atomic.potato
struct S
{
    void f();
};

extern "C" void call_664370(void *);
extern "C" void call_6ec4e0(void *, int);
extern "C" void call_5395b0(void *);

void S::f()
{
    char *p = (char *)this;
    call_664370(p + 0x58);
    int *q = *(int **)(p + 0x48);
    if (q != 0)
    {
        call_6ec4e0(*(void **)(q + 0x5a), 0);
        call_5395b0(p + 0x48);
    }
}
