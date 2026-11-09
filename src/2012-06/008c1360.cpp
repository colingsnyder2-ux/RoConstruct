// from server: 75% by atomic.potato
extern "C" void sub_684660(void *, int);
extern "C" void sub_675c40(void *);

struct S_func_008c1360 {
    char pad0[132];
    void f(int);
};

void S_func_008c1360::f(int value)
{
    sub_684660(this, value);
    sub_675c40((char *)this + 132);
}
