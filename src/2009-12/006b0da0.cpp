// from server: 76% by atomic.potato
extern "C" int call_006b0d20(void *);
extern "C" int call_006f6c70(void *, void *);

struct S
{
    int f();
};

int S::f()
{
    int a = call_006b0d20(this);
    int b = call_006f6c70((void *)(a + 0xa8), 0);
    return *(int *)b;
}
