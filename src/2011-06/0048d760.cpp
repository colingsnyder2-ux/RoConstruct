// from server: 67% by atomic.potato
typedef unsigned long DWORD;
typedef int BOOL;

extern "C" BOOL __stdcall FreeLibrary(void*);

extern DWORD g_00cb4140;
extern long g_00cb4144;

struct CScriptEditor
{
    void f();
};

void CScriptEditor::f()
{
    if (--g_00cb4144 == 0)
        FreeLibrary((void*)g_00cb4140);
}
