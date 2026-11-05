// from server: 100% by atomic.potato
extern "C" int __cdecl function_005a22c0(const void *, int, int);

int function_00561910(const char *p)
{
    int a = function_005a22c0(p + 2, 2, 2);
    int b = function_005a22c0(p + 4, 4, a);
    return b;
}
