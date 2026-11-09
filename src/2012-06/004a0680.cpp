// from server: 43% by atomic.potato
extern "C" int* __cdecl func_004f3c90();
extern "C" int func_0049cf70(void*, int, int);

struct CScriptEditor
{
    int f(int);
};

int CScriptEditor::f(int value)
{
    int* p = func_004f3c90();
    int r = func_0049cf70(p, 2, 1);
    return value ? 1 : 0;
}
