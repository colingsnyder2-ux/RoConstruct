// from server: 75% by atomic.potato
typedef int (*Fn)(void *, void *);

struct S_func_005f6490 {
    char pad0[380];
    char field17c[40];
    char field1a4[1];
    void f(void *arg);
};

extern "C" void sub_006f7df0(void *, void *);

void S_func_005f6490::f(void *arg)
{
    sub_006f7df0(field17c, arg);
    sub_006f7df0(field1a4, arg);
}
