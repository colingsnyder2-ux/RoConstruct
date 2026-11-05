// from server: 23% by atomic.potato
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

struct CScriptEditor
{
    int (**vtable)(CScriptEditor*, int);
    int f();
};

S_func_0046abe0* __cdecl func_0046abe0();

int CScriptEditor::f()
{
    S_func_0046abe0* p = func_0046abe0();
    int* v = p->f();
    return vtable[1](this, v != 0);
}
