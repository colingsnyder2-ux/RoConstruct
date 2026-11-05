// from server: 59% by atomic.potato
extern "C" void __stdcall helper(int);

extern "C" void __stdcall imported_call(int, float, float, float);

struct S
{
    void f(int, float, float, float);
};

void S::f(int a, float b, float c, float d)
{
    helper(1);
    imported_call(a, d, c, b);
}
