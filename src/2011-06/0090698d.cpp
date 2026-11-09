// from server: 56% by atomic.potato
extern "C" void __cdecl helper(int);
extern "C" void __cdecl imported(int, float, float, float);

struct S
{
    void f(int, float, float, float);
};

void S::f(int a, float b, float c, float d)
{
    helper(1);
    imported(a, b, c, d);
}
