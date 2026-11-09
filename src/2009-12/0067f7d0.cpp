// from server: 46% by atomic.potato
struct S
{
    int __cdecl f(int, int, int);
};

typedef void (__cdecl *FunctionType)(int *, int, int);

extern "C" FunctionType function_0067e550;

int S::f(int a, int b, int c)
{
    int result = 0;
    function_0067e550(&result, a, b);
    return result;
}
