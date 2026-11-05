// from server: 55% by atomic.potato
extern "C" void __cdecl f_009831f5(const void*);

unsigned char g_00e48e38;
void*& g_00e48e30 = *(void**)0x00e48e30;
void*& g_00e48e34 = *(void**)0x00e48e34;

void f_007891d0()
{
    if (*(unsigned char*)0x00e48e38 != 0)
        return;

    *(unsigned long*)0x00e48e38 |= 1;
    g_00e48e30 = 0;
    g_00e48e34 = 0;
    f_009831f5((const void*)0x00b1b640);
}
