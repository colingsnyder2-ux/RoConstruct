// from server: 93% by atomic.potato
extern "C" void *__cdecl malloc(unsigned int size);
extern void func_007e1df0();
extern unsigned char byte_B44670;

void *sub_006F0E30(unsigned int size)
{
    unsigned int n = size;
    if (n <= 0)
        n = 1;
    void *p = malloc(n);
    if (p == 0 && size != 0 && byte_B44670 != 0)
        func_007e1df0();
    return p;
}
