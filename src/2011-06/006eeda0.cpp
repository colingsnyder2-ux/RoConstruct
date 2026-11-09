// from server: 52% by atomic.potato
struct S
{
    unsigned char pad0[0x58];
    unsigned char flag;
    unsigned char pad1[0xAF];
    S *base;
    unsigned char pad2[0x60];
    void (__thiscall *callback)(S *, void *, int);
    int f(int);
};

int S::f(int value)
{
    if (flag)
        callback(base, (char *)this + 0x24, 0);
    return value;
}
