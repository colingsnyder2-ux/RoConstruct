// from server: 89% by atomic.potato
struct S_func_006ce6a0
{
    int f(int a1, int a2);
};

extern "C" int func_006cdb40(void *, int, int);
extern "C" int __cdecl func_007e17f0(int);

int S_func_006ce6a0::f(int a1, int a2)
{
    int result = func_006cdb40((char *)this - 0xb0, a1, a2);
    return func_007e17f0(result);
}
