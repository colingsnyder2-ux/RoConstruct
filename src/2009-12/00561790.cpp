// from server: 100% by atomic.potato
extern "C" void __cdecl sub_007F385A(int);

struct S
{
    void f();
};

void S::f()
{
    if (*((int *)((char *)this + 4)) != 0)
        sub_007F385A(*((int *)((char *)this + 8)));
}
