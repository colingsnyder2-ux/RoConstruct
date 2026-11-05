// from server: 51% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl Function_009831f5(DWORD);

int Function_007a0430()
{
    if (*(unsigned char*)0x00e4a298 == 1)
        return 0;

    *(DWORD*)0x00e4a298 |= 1;
    *(DWORD*)0x00e4a290 = 0;
    *(DWORD*)0x00e4a294 = 0;
    Function_009831f5(0x00b1bed0);
    return 0;
}
