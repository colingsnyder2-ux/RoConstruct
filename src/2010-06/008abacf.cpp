// from server: 59% by atomic.potato
extern "C" void __stdcall helper(int);
extern "C" int __stdcall imported(int, float, float, float);

int __stdcall function_008abacf(int value, float a, float b, float c)
{
    helper(1);
    return imported(value, a, b, c);
}
