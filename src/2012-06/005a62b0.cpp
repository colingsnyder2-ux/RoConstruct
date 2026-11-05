// from server: 68% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __stdcall sub_9779e0(double, void *, void *);

struct S
{
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    double value = *(float *)((char *)this + 0x220);
    sub_9779e0(value, b, a);
}
