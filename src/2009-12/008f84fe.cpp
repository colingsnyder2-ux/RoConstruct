// from server: 37% by atomic.potato
extern "C" void __stdcall sub_008fb2b4(int);

typedef int (__stdcall *FunctionType)(float, int, int, int, int);

FunctionType g_function = (FunctionType)0;

int __stdcall sub_008f84fe(float value, int a, int b, int c, int d)
{
    sub_008fb2b4(1);
    return g_function(value, a, b, c, d);
}
