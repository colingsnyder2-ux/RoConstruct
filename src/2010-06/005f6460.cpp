// from server: 100% by atomic.potato
extern "C" void __cdecl func_005f5d30(void*, void*, int);

void func_005f6460(void* a, void* b, int c)
{
    if (c != 4)
    {
        func_005f5d30(a, b, c);
        return;
    }

    *(unsigned long*)b = 0x00bac4e0;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
