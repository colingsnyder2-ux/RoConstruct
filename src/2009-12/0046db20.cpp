// from server: 74% by atomic.potato
extern "C" int* __cdecl func_0046abe0();
extern "C" int func_00469e30(void*, int, int);

struct CScriptEditor
{
    int (*vtable[2])(CScriptEditor*, int);
    int f(int);
};

int CScriptEditor::f(int value)
{
    int* p = func_0046abe0();
    int result = func_00469e30(p, 1, 1);
    result = result != 0;
    return vtable[1](this, result);
}
