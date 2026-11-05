// from server: 60% by atomic.potato
struct S
{
    int f(int, float, float, float);
};

extern "C" void __stdcall helper(int);
extern "C" void __stdcall target(int, float, float, float);

int S::f(int a, float b, float c, float d)
{
    helper(1);
    target(a, d, c, b);
    return 0;
}
