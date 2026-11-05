// from server: 19% by atomic.potato
typedef int (__cdecl *FunctionType)(int, int, int);

int __stdcall Function00909946(int a, int b, int c)
{
    FunctionType f = (FunctionType)0x00909610;
    f(a, b, c);
    return a;
}
