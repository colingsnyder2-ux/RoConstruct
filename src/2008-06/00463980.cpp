// from server: 100% by king_originala
extern int libraryReferences;
extern void* libraryHandle;
extern "C" int (__stdcall* FreeLibrary)(void*);

struct CScriptEditor
{
    void cleanup();
    void func_00463980();
};

void CScriptEditor::func_00463980()
{
    if (--libraryReferences == 0)
        FreeLibrary(libraryHandle);
    cleanup();
}
