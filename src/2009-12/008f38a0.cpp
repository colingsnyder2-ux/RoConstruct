// from server: 84% by atomic.potato
extern "C" int __stdcall G1_func_00926af0(int, int*);

struct CXTWndHook
{
    int f(int);
};

int CXTWndHook::f(int value)
{
    int result = 0;
    G1_func_00926af0(value, &result);
    return result;
}
