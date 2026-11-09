// from server: 66% by atomic.potato
struct S_func_008dfa90;
struct T_func_008dede0;

extern "C" T_func_008dede0* func_008dede0(S_func_008dfa90*);
extern "C" void func_00684200(T_func_008dede0*, int, int);

struct S_func_008dfa90
{
    void f();
};

void S_func_008dfa90::f()
{
    T_func_008dede0* p = func_008dede0(this);
    while (p != 0)
    {
        func_00684200(p, 0, 0);
        p = func_008dede0(this);
    }
}
