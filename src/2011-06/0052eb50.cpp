// from server: 80% by atomic.potato
struct S_func_0052eb50
{
};

unsigned short __cdecl f(unsigned short *value, S_func_0052eb50 *peer)
{
    unsigned short a = *value;
    unsigned short b = *(unsigned short *)((char *)*(unsigned long *)((char *)*(unsigned long *)peer + 0x0c) + 0x0a);
    if (a < b)
        return (unsigned short)-1;
    return a != b;
}
