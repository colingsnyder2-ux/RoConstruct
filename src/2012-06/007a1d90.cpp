// from server: 100% by atomic.potato
typedef unsigned int DWORD;
typedef unsigned char BYTE;

extern "C" void __cdecl Function_007a1bf0(DWORD, DWORD, DWORD);

void Function_007a1d90(DWORD a, DWORD b, DWORD c)
{
    if (c != 4)
    {
        Function_007a1bf0(a, b, c);
        return;
    }

    *(DWORD*)b = 0x00dc58b8;
    *(BYTE*)(b + 4) = 0;
    *(BYTE*)(b + 5) = 0;
}
