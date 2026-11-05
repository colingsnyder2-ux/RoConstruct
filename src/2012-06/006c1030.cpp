// from server: 64% by atomic.potato
extern "C" void sub_006f1960(void *);

struct S
{
    int pad[10];
    int f(void *);
};

int S::f(void *arg)
{
    void *p = *(void **)((char *)this + 0x28);
    int value = (*(int (**)(void *, void *))(*(char **)p + 8))(p, arg);
    char *q = (char *)this + 0x10;
    sub_006f1960(q);
    *(int *)(q + 8) = value;
    *(int *)(q + 4) = 5;
    return 0;
}
