// from server: 74% by atomic.potato
extern "C" void __cdecl sub_00745730(void *);
extern "C" void sub_007451C0(void *);

struct S
{
    void f(void *);
};

void S::f(void *arg)
{
    sub_00745730(arg);
    sub_007451C0(arg);
}
