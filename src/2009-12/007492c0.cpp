// from server: 75% by atomic.potato
extern "C" void __stdcall Function7490f(void*, int, int, float);

struct S
{
    int value8;
    void* valueC;
    void f(int, float);
};

void S::f(int a, float b)
{
    Function7490f(valueC, a, value8, b);
}
