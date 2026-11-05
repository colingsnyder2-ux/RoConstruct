// from server: 50% by atomic.potato
extern "C" void __cdecl sub_00410330(void *, void *);
extern "C" void sub_005038d0(void *);

struct S_func_00636a50
{
    char data[0x80];
    void f(void *);
};

void S_func_00636a50::f(void *arg)
{
    char local[8];
    sub_00410330(arg, local);
    sub_005038d0(data);
}
