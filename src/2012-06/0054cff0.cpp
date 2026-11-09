// from server: 60% by atomic.potato
typedef unsigned char BYTE;
typedef unsigned int DWORD;

extern "C" void __cdecl sub_9831f5(const char*);

void f()
{
    if (*(BYTE*)0x00e21d70 != 0)
        return;

    *(DWORD*)0x00e21d70 |= 1;
    *(DWORD*)0x00e21d68 = 0;
    *(DWORD*)0x00e21d6c = 0;
    sub_9831f5("8csm");
}
