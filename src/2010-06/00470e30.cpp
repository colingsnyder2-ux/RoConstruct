// from server: 83% by atomic.potato
extern "C" int __stdcall FreeLibrary(void*);

extern int g_ActiveCount;
extern void* g_ModuleHandle;

struct CScriptEditor
{
    void f();
};

extern void __declspec(noreturn) CScriptEditor_fallback(CScriptEditor*);

void CScriptEditor::f()
{
    --g_ActiveCount;
    if (g_ActiveCount == 0)
        FreeLibrary(g_ModuleHandle);
    CScriptEditor_fallback(this);
}
