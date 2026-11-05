// from server: 76% by atomic.potato
extern "C" int* __cdecl G1_func_0046e6f0();
extern "C" int G1_func_0046d930(void*, int, int);

struct CScriptEditor {
    typedef void (__thiscall *Callback)(CScriptEditor*, int);
    Callback* vtable;
    void f(int);
};

void CScriptEditor::f(int value)
{
    int* p = G1_func_0046e6f0();
    int result = G1_func_0046d930(p, 0, 1) != 0;
    vtable[1](this, result);
}
