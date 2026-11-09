// from server: 56% by atomic.potato
extern "C" void __cdecl helper(int);
extern "C" int __cdecl target(int, float, float, float);

int __stdcall function_008abfe9(int a, float b, float c, float d)
{
    helper(1);
    return target(a, b, c, d);
}
