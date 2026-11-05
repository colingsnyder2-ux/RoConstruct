// from server: 59% by atomic.potato
struct GetSetImpl {
    char pad[0x18];
    int (__stdcall *fn)(int, int);
    int offset1c;
    int offset20;
    int method(int, int);
};

int GetSetImpl::method(int a, int b)
{
    int *p;
    if (a != 0)
        p = (int *)(a - 0x1c);
    else
        p = 0;

    unsigned char idx = *(unsigned char *)b;
    int base = *(int *)((char *)p + 0x138);
    int val = *(int *)(base + offset20);
    val += offset1c;
    int (__stdcall *f)(int, int) = fn;
    return f(val + (int)p + 0x138, idx);
}
