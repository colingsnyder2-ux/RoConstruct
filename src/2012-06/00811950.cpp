// from server: 73% by atomic.potato
struct S
{
    void f(float, float, float);
};

extern "C" void __stdcall sub_0091e680(float, float, float, int);

void S::f(float a, float b, float c)
{
    sub_0091e680(c, b, a, *(int *)((char *)this - 4));
}
