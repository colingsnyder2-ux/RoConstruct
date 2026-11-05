// from server: 100% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl G1_func_00761c30(DWORD, DWORD, DWORD);

void func_00762030(DWORD a1, DWORD* a2, DWORD a3)
{
    if (a3 != 4)
    {
        G1_func_00761c30(a1, (DWORD)a2, a3);
        return;
    }

    *a2 = 0x00db8f78;
    ((unsigned char*)a2)[4] = 0;
    ((unsigned char*)a2)[5] = 0;
}
