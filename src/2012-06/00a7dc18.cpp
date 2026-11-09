// from server: 59% by atomic.potato
extern "C" void __stdcall helper(int);
extern "C" int __stdcall target(int, float, float, float);

int __stdcall function_00a7dc18(int a, float b, float c, float d)
{
    helper(1);
    return target(a, b, c, d);
}
