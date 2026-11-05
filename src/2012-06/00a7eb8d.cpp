// from server: 59% by atomic.potato
extern "C" void __stdcall helper(int);
extern "C" int __stdcall target(int, float, float, float);

int __stdcall func_00a7eb8d(int a, float b, float c, float d)
{
    helper(1);
    return target(a, b, c, d);
}
