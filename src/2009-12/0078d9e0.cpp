// from server: 100% by atomic.potato
extern "C" void __cdecl call_006a5730(int, int, int, int);

struct S
{
    void f(int, int);
};

void S::f(int a, int b)
{
    call_006a5730(*(int *)((char *)this + 0x10),
                  *(int *)((char *)this + 0x0c) + a,
                  b,
                  1);
}
