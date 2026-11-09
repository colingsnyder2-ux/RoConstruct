// from server: 100% by atomic.potato
struct S {
    void **vtable;
    char pad[0x0c];
    int *p10;
    int *p14;
    char pad2[0x08];
    int *p20;
    int *p24;
    char pad3[0x08];
    int *p30;
    int *p34;
    char pad4[0x24];
    unsigned int flags;
    void func(int);
};

void S::func(int a)
{
    if (a == 1) {
        if ((flags & 2) == 0) {
            *p10 = 0;
            *p20 = 0;
            *p30 = 0;
            flags |= 2;
        }
    } else if (a == 2) {
        if ((flags & 4) == 0) {
            ((void (__thiscall *)(void *))vtable[0x30 / 4])(this);
            *p14 = 0;
            *p24 = 0;
            *p34 = 0;
            flags |= 4;
        }
    }
}
