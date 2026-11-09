// from server: 100% by atomic.potato
extern "C" void __stdcall sub_861f90(int);

struct S
{
    void f(int, int);
};

void S::f(int a, int b)
{
    sub_861f90(b);
}
