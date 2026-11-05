// from server: 59% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl sub_8f0910(void *, DWORD, DWORD, DWORD);
extern "C" void __fastcall sub_62c2e0(void *, void *, DWORD);

DWORD __stdcall Function_0091f9c0(DWORD value)
{
    char buffer[12];
    sub_8f0910(buffer, 0, value, 2);
    sub_62c2e0(buffer, buffer, 0);
    return value;
}
