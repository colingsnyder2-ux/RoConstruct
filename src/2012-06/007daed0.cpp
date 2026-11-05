// from server: 61% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" int sub_7856a0(void *);

int S::f(void *p)
{
    char *base = *(char **)((char *)this + 0x2c);
    if (p != 0)
        return sub_7856a0(base + ((char *)p - (char *)0x1c));
    return sub_7856a0(base);
}
