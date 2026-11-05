// from server: 59% by atomic.potato
extern "C" void __stdcall helper(int);
extern "C" void __cdecl imported(const char *, float, float, float);

struct S
{
    void f(const char *, float, float, float);
};

void S::f(const char *a, float b, float c, float d)
{
    helper(1);
    imported(a, b, c, d);
}
