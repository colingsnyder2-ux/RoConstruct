// from server: 59% by atomic.potato
extern "C" int * G1_func_0046e6f0();
extern "C" int G1_func_0046d930(void *, int, int);

struct CScriptEditor
{
    int (**vtable)(void *, int);
    int f();
};

int CScriptEditor::f()
{
    int *p = G1_func_0046e6f0();
    int result = G1_func_0046d930(p, 2, 1) != 0;
    return vtable[1](this, result);
}
