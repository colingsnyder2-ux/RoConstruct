// from server: 73% by Intel
extern "C" int* __cdecl func_004f3c90(void*);
extern "C" int __cdecl func_0049cf70(void*, int, int);

struct CScriptEditor
{
    int (__thiscall *callback)(CScriptEditor*, int);
    int f(int);
};

int CScriptEditor::f(int value)
{
    int* p = func_004f3c90(this);
    int result = func_0049cf70(p, 0, 1);
    result = result != 0;
    return callback(this, result);
}
