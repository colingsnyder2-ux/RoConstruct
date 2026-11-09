// from server: 100% by atomic.potato
extern "C" void* (__cdecl* malloc)(unsigned int);
extern void G1_func_00974670();
extern unsigned char g_byte_e02724;

void* __cdecl func_0097c220(unsigned int size)
{
    void* p;
    unsigned int n = size;
    if (n <= 0)
        n = 1;
    p = malloc(n);
    if (p == 0 && size != 0 && g_byte_e02724 != 0)
        G1_func_00974670();
    return p;
}
