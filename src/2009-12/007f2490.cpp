// from server: 91% by atomic.potato
extern "C" char __cdecl sub_7f2370();

typedef int (__cdecl *FunctionPointer)();

extern FunctionPointer g_00b9a9f0;

int __cdecl function_007f2490()
{
    if (sub_7f2370())
    {
        FunctionPointer f = g_00b9a9f0;
        if (f)
            return f();
    }
    return 0;
}
