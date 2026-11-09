// from server: 65% by atomic.potato
extern "C" void __cdecl sub_80B15D(const void *);

int f()
{
    int value;
    value = 0;
    value &= 0xc03300cb;
    *(int *)0xcb25c4 = value;
    *(int *)0xcb25c8 = value;
    sub_80B15D((const void *)0xa30a90);
    return value;
}
