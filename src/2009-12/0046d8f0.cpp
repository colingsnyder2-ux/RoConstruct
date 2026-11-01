// from server: 60% by atomic.potato
struct S_func_0046abe0 {
    char pad0[88];
    int m_x;
    int* f();
};

struct CScriptEditor {
    int f();
};

int CScriptEditor::f()
{
    S_func_0046abe0* p = (S_func_0046abe0*)0;
    int* r = p->f();
    int a = ((int (__thiscall*)(void*, int))0x469930)(r, 1);
    int b = ((int (__thiscall*)(void*, int, int))0x46a420)(r, a, 1);
    return ((int (__thiscall*)(void*, int, int, int))0x469c10)(r, b, 0, 1);
}
