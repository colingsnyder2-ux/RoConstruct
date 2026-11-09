// from server: 100% by atomic.potato
typedef unsigned char BYTE;
typedef unsigned long DWORD;

extern DWORD g_00E48E3C;
extern DWORD g_00E48E40;
extern DWORD g_00E48E44;

extern "C" void __cdecl f_009831F5(const void*);

void f_00789200()
{
    if (!(g_00E48E44 & 1))
    {
        g_00E48E44 |= 1;
        g_00E48E3C = 0;
        g_00E48E40 = 0;
        f_009831F5((const void*)0x00B1B620);
    }
}
