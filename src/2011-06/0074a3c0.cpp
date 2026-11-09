// from server: 100% by atomic.potato
struct S_func_0074a3c0 {
    int m_pad0[4];
    int m_value;
    int f(void *p);
};

int S_func_0074a3c0::f(void *p)
{
    int value;
    int adjusted;

    adjusted = p ? (int)p - 8 : 0;
    value = *((int *)((char *)this - 0x10));
    if (adjusted == value)
        value = *((int *)((char *)this - 0x0c));
    return value ? value + 8 : 0;
}
