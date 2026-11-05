// from server: 75% by atomic.potato
extern "C" int __cdecl function_00561a60(int);

extern "C" int __stdcall function_00561d50(unsigned char value)
{
    if (value == 4)
        return function_00561a60(*(int *)0x00d88950);
    return function_00561a60(*(int *)0x00d8894c);
}
