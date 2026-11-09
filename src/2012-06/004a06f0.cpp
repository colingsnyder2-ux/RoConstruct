// from server: 65% by atomic.potato
extern "C" int* __cdecl func_004f3c90();

struct CScriptEditor
{
    int (**vtable)(CScriptEditor*, int);
    int f(int);
};

extern "C" int func_0049cf70(void*, int, int);

int CScriptEditor::f(int value)
{
    int* p = func_004f3c90();
    int result = func_0049cf70(p, 1, 1) != 0;
    return vtable[1](this, result);
}
