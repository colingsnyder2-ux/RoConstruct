// from server: 100% by atomic.potato
typedef int FunctionType(int, int, int);

extern FunctionType g_function;
extern int g_value;

struct S
{
};

int __cdecl f(int a, int b)
{
    int result = g_function(a, b, 0);
    if (!result)
        result = g_value;
    return result;
}
