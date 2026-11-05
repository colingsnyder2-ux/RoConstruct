// from server: 67% by atomic.potato
struct S
{
    int f(void *, void *);
    void *field;
};

int S::f(void *a, void *b)
{
    void *p = a ? (char *)a + 0x1c : 0;
    void *q = *(void **)((char *)this + 0x12c);
    return ((int (__thiscall *)(void *, void *, void *))(*(unsigned char **)q + 0x24))(q, p, b);
}
