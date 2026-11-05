// from server: 57% by atomic.potato
struct S
{
    int f(void *);
    int m38;
    int m3c;
};

extern "C" int sub_503a70(S *, int);

int S::f(void *p)
{
    int a;

    if (p)
        a = (int)p - 0x1c;
    else
        a = 0;

    return sub_503a70(
        (S *)((char *)a + *(int *)((char *)a + 0x98 + m3c) + m38 + 0x98),
        a);
}
