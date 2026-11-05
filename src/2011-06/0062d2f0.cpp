// from server: 64% by atomic.potato
struct S
{
    void f(int);
};

extern "C" char G1_func_006c70f0(int);
extern "C" void G1_func_00598250(int);

void S::f(int a)
{
    if (!G1_func_006c70f0(a))
        G1_func_00598250(a);
}
