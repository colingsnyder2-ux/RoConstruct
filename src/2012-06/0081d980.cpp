// from server: 53% by atomic.potato
struct S {
    void __cdecl f(int, int);
};

extern "C" void __stdcall function_008e2eb0(int*);

void S::f(int a, int b)
{
    function_008e2eb0(&a);
}
