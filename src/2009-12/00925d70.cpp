// from server: 33% by atomic.potato
extern "C" void __cdecl sub_00925bc0(int, int, int, int);

struct S
{
    void f();
};

void S::f()
{
    sub_00925bc0(0, *(int *)((char *)this - 8), *(int *)((char *)this - 16), 0);
}
