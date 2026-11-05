// from server: 87% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl sub_78ab20(DWORD, DWORD, DWORD);
extern "C" void __cdecl sub_79e7c0(DWORD);

int sub_0079e820(DWORD value)
{
    sub_78ab20(value, 0x9cc9dc, 0x9eaff0);
    sub_79e7c0(value);
    return 1;
}
