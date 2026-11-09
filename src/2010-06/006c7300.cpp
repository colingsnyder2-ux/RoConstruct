// from server: 40% by atomic.potato
struct S
{
    int (*fn)(int, int *);
    int offset;
    int Invoke(int *out, int *value);
};

int S::Invoke(int *out, int *value)
{
    int *p = value ? (int *)((char *)value - 0x1c) : 0;
    int *result = (int *)((char *)this + offset + (int)p);
    result = (int *)((int (__cdecl *)(int *, int *))((int *)this)[2])((int *)value, value);
    *out = *result;
    return 0;
}
