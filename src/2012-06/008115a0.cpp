// from server: 85% by atomic.potato
extern "C" void __stdcall sub_008f1f00(void *);
extern "C" void __stdcall sub_00982114(void *);

struct S
{
    int f(int);
};

int S::f(int value)
{
    S *p = this;
    *(unsigned long *)p = 0x00bc5c1c;
    *(unsigned long *)((char *)p + 0x1c) = 0x00bc5c00;
    sub_008f1f00(p);
    if (value & 1)
        sub_00982114(p);
    return (int)p;
}
