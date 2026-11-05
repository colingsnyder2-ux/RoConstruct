// from server: 100% by atomic.potato
extern "C" void G1_func_00505990(int, int, int);

void func_00505b40(int a0, int a1, int a2)
{
    if (a2 != 4)
        G1_func_00505990(a0, a1, a2);
    else
    {
        *(int*)a1 = 0x00b155f0;
        *((unsigned char*)a1 + 4) = 0;
        *((unsigned char*)a1 + 5) = 0;
    }
}
