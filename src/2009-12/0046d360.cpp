// from server: 67% by atomic.potato
extern "C" int __stdcall FreeLibrary(void *);

extern int g_00b7bb30;
extern void *g_00b7bb2c;

struct CScriptEditor
{
    void f();
};

void CScriptEditor::f()
{
    if (--g_00b7bb30 == 0)
        FreeLibrary(g_00b7bb2c);
}
