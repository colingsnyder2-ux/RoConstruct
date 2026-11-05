// from server: 68% by atomic.potato
extern "C" void __stdcall call_00432d60(int);

struct S
{
    int **vtable;
    void f(int);
};

void S::f(int value)
{
    call_00432d60(value);
    ((void (__thiscall *)(S *))vtable[24])(this);
}
