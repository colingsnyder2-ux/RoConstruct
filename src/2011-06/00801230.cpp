// from server: 93% by atomic.potato
extern "C" void *__cdecl malloc(unsigned int);

extern unsigned char g_flag;

void G1_func_007faa40();

void *func_00801230(unsigned int size)
{
    unsigned int n = size;
    if (size <= 0)
        n = 1;

    void *p = malloc(n);
    if (p == 0 && size != 0 && g_flag == 0)
        G1_func_007faa40();

    return p;
}
