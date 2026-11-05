// from server: 85% by atomic.potato
extern "C" void* G1_func_0067bed0(int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    void* p = G1_func_0067bed0(value + 4);
    int v = *(int*)p;
    return ((int (__thiscall *)(S*, int&))0x76a190)(this, v);
}
