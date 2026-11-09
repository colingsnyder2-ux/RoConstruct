// from server: 76% by atomic.potato
struct S
{
    float value;
    int f(int a, int b);
};

extern "C" int __cdecl Call977d20(double, int, int);

int S::f(int a, int b)
{
    Call977d20((double)*(float *)((char *)this + 0x228), b, a);
    return b;
}
