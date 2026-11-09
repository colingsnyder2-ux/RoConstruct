// from server: 100% by atomic.potato
extern "C" void G1_func_004f8810(void *, void *, int);

void func_004fc980(void *a, void *b, int c)
{
    if (c != 4)
    {
        G1_func_004f8810(a, b, c);
        return;
    }

    *(int *)b = 0x00b131c0;
    *((unsigned char *)b + 4) = 0;
    *((unsigned char *)b + 5) = 0;
}
