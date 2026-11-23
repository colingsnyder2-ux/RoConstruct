// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no project headers are available, so every type here is a local
// stand-in and every callee is an fn_<address> extern.

extern "C" __declspec(dllimport) unsigned int __stdcall glGetError(void);

// Callees (the thiscall ones are declared __fastcall with a dummy edx).
extern "C" int  __fastcall fn_00442cd0(void* self, int unusedEdx, int a1);        // List<RegisteredCommand>::Size
extern "C" void __cdecl    fn_004763d0(void* out, unsigned int size, int hint);   // VARArea::create
extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);                // zeroPointer
extern "C" void* __fastcall fn_00502ab0(void* self, int unusedEdx, const void* src); // VAR::operator=

// INFERRED: ReferenceCountedPointer<VARArea> stand-in, one pointer wide.
struct RefPtr {
    void* p;
};
extern "C" RefPtr* __fastcall fn_004f0820(RefPtr* self, int unusedEdx, const RefPtr* src); // copy ctor
extern "C" void*   __fastcall fn_00502910(void* self, int unusedEdx, const void* arr, RefPtr area); // VAR ctor from Array
extern "C" int     __fastcall fn_00551400(void* self, int unusedEdx, int a1, RefPtr a2);

struct AreaRef {
    RefPtr r;
    AreaRef() { r.p = 0; }
    AreaRef(const AreaRef& o) { fn_004f0820(&r, 0, &o.r); }
    ~AreaRef() { fn_00502a70(&r, 0); }
};

// INFERRED: by-value RefPtr arguments are copy-constructed via fn_004f0820 at the call site.
struct RefPtrArg : RefPtr {
    RefPtrArg(const AreaRef& a) { fn_004f0820(this, 0, &a.r); }
};

// INFERRED: temporary VAR, at most 0x28 bytes (the stack slots are 0x28 apart).
struct VarTmp {
    char b[0x28];
    ~VarTmp() { fn_00502a70(this, 0); }
};

// INFERRED: global names and types are guesses; addresses are in the comments.
extern unsigned char g_renderBatchDirty;   // 0x9738a1
extern char g_batchVerts[];                // 0x9738f0
extern char g_batchArrayB[];               // 0x9738fc
extern char g_batchArrayC[];               // 0x973934
extern char g_batchArrayD[];               // 0x973928
extern char g_varA[];                      // 0x9738d0
extern char g_varB[];                      // 0x973940
extern char g_varC[];                      // 0x973960
extern char g_varD[];                      // 0x973908

extern "C" void fn_00548cb0()
{
    if (!g_renderBatchDirty) {
        return;
    }

    // Drain the GL error queue.
    unsigned int err = glGetError();
    while (err != 0) {
        err = glGetError();
    }

    AreaRef area;
    {
        int n = fn_00442cd0(g_batchVerts, 0, 0);
        fn_004763d0(&area.r, (unsigned int)(n * 0x2c + 0x400), 0);
    }

    {
        VarTmp t;
        fn_00502ab0(g_varA, 0, fn_00502910(&t, 0, g_batchVerts, RefPtrArg(area)));
    }
    {
        VarTmp t;
        fn_00502ab0(g_varB, 0, fn_00502910(&t, 0, g_batchArrayB, RefPtrArg(area)));
    }
    {
        VarTmp t;
        fn_00502ab0(g_varC, 0, (void*)fn_00551400(&t, 0, (int)g_batchArrayC, RefPtrArg(area)));
    }
    {
        VarTmp t;
        fn_00502ab0(g_varD, 0, fn_00502910(&t, 0, g_batchArrayD, RefPtrArg(area)));
    }

    g_renderBatchDirty = 0;
}
