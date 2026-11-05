// from server: 53% by atomic.potato
extern "C" void __cdecl helper(int);
extern "C" int __stdcall imported(int, float, float, float);

int __stdcall func_00a7db8a(int value, float a, float b, float c)
{
    helper(1);
    return imported(value, a, b, c);
}
