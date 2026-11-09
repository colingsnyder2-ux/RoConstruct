// from server: 29% by atomic.potato
struct S_func_0046abe0 {
    char pad0[88];
    int m_x;
    int* f();
};

int* S_func_0046abe0::f()
{
    return &m_x;
}

struct CScriptEditor {
    void func_0046dce0(int);
};

extern "C" int __stdcall sub_98de74();
extern "C" int __stdcall sub_98d310(int, int, int);
extern "C" int __stdcall sub_98de80();
extern "C" int __stdcall sub_98dec0();

void CScriptEditor::func_0046dce0(int a)
{
    S_func_0046abe0* p = (S_func_0046abe0*)0;
    int* esi = p->f();
    int v1 = ((int (__thiscall*)(void*, int))0x469930)(esi, 1);
    int v2 = ((int (__thiscall*)(void*, int, int))0x46a420)(esi, v1, 1);
    int v3 = ((int (__thiscall*)(void*, int, int))0x46a8f0)(esi, v2, 1);
    int idx = (v3 & 0xfff) - 0x400;
    char buf[8];
    sub_98de74();
    sub_98d310((int)buf, 0xc9, idx);
    int* obj = (int*)*(int*)((char*)buf + 0x20);
    int* vtbl = (int*)*obj;
    sub_98de80();
    ((void (__thiscall*)(void*, int))vtbl[3])(obj, (int)buf);
    sub_98dec0();
}
