// from server: 78% by atomic.potato
extern "C" int __cdecl function_00877990(int, int, int);
extern "C" int __cdecl function_00878680(int);

struct S
{
    void f(int, int);
};

void S::f(int a, int b)
{
    int x = function_00877990(a, b, 0);
    function_00878680(x);
}
