// from server: 34% by atomic.potato
typedef int (__cdecl *FunctionType)(int, int, int, int);
extern "C" int __cdecl CallTarget(int, int, int, int);

int Function007e1c7c()
{
    FunctionType function = (FunctionType)0x00b79400;
    return function(0, 0, 0, 0);
}
