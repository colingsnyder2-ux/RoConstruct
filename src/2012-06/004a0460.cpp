// from server: 78% by atomic.potato
typedef void* HMODULE;

extern "C" int __stdcall FreeLibrary(HMODULE);

extern HMODULE g_module;
extern long g_referenceCount;

struct CScriptEditor
{
    void Release();
};

extern "C" void __cdecl CScriptEditor_Destroy(CScriptEditor*);

void CScriptEditor::Release()
{
    if (--g_referenceCount == 0)
        FreeLibrary(g_module);
    CScriptEditor_Destroy(this);
}
