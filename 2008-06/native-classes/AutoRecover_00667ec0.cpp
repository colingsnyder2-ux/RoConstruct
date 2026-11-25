// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0084cf28[];
extern "C" char g_0084cf30[];
extern "C" char g_0097a630[];

// INFERRED: no class header was available, so file-local layout types are used.
// The target is the GettingUp destructor body. It has no exported name, so it is
// written as a C-linkage function with the fn_<addr> name. The base destructor
// call runs from a scope guard so the EH frame (state 0 -> -1) matches.

struct Local_00667ec0
{
    void* vptr0;
    void* vptr1;
};

extern "C" void* __fastcall fn_00793d50(Local_00667ec0* self, int unusedEdx);          // getHumanoid
extern "C" void* __fastcall fn_0056b620(void* sigDesc, int unusedEdx, void* source);   // findSignalInstance
extern "C" void __fastcall fn_005e1f00(void* sig, int unusedEdx, char* tag, int flag); // signal1::operator()
extern "C" void __fastcall fn_006435c0(Local_00667ec0* self, int unusedEdx);           // ~HumanoidState

struct Local_00667ec0_Guard
{
    Local_00667ec0* s;
    ~Local_00667ec0_Guard() { fn_006435c0(s, 0); }
};

extern "C" void __fastcall fn_00667ec0(Local_00667ec0* self, int unusedEdx)
{
    self->vptr0 = reinterpret_cast<void*>(g_0084cf30);
    self->vptr1 = reinterpret_cast<void*>(g_0084cf28);
    Local_00667ec0_Guard guard = { self };

    void* p = fn_00793d50(self, 0);
    void* key = p ? static_cast<char*>(p) + 20 : 0;
    void* found = fn_0056b620(reinterpret_cast<void*>(g_0097a630), 0, key);
    if (found)
    {
        char tag;
        fn_005e1f00(static_cast<char*>(found) + 16, 0, &tag, 0);
    }
}
