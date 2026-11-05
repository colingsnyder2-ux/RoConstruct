// from server: 65% by atomic.potato
struct S_func_0046abe0
{
    char pad0[88];
    int m_x;
    int* f();
};

int* S_func_0046abe0::f()
{
    return &m_x;
}

extern "C" int func_00469e30(void*, int, int);
extern "C" int* func_0046abe0();

struct CScriptEditor
{
    int (**vtable)(CScriptEditor*, int);
    int f(int);
};

int CScriptEditor::f(int value)
{
    int* p = func_0046abe0();
    int result = func_00469e30(p, 2, 1);
    result = result != 0;
    return vtable[1](this, result);
}
