// from server: 100% by atomic.potato
struct S_func_004b6080
{
    int __stdcall GetValue(void *p);
};

int __stdcall S_func_004b6080::GetValue(void *p)
{
    if (p == 0)
        return (int)0x80004003;

    unsigned char *source = (unsigned char *)this;
    unsigned char *destination = (unsigned char *)p;

    *(unsigned long *)(destination + 0) = *(unsigned long *)(source + 0x1c);
    *(unsigned long *)(destination + 4) = *(unsigned long *)(source + 0x20);
    *(unsigned long *)(destination + 8) = *(unsigned long *)(source + 0x24);
    *(unsigned long *)(destination + 0xc) = *(unsigned long *)(source + 0x28);
    return 0;
}
