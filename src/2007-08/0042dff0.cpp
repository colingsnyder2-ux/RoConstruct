// from server: 65% by EspClaude
// from server: 54% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_9846f0a43f1644e7.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog of an MFC 8 COM stub: AFX_MANAGE_STATE(...) then E_NOTIMPL (0x80004001).
// Read off the target bytes: MFC80 #1072 returns the module state, #314 is the out-of-line
// AFX_MAINTAIN_STATE2 constructor (object at esp+0xc: prev +0, thread state +4, cookie +8,
// valid-cookie flag +0xc), the inline destructor restores [threadstate+4] and calls
// #6754 (AfxDeactivateActCtx(0, cookie)).  A 4-byte local with a destructor is zeroed
// (EH state 1).  The out parameter receives the result of the cdecl helper 00412090(0).
struct AFX_MODULE_STATE;
struct _AFX_THREAD_STATE {
    void* m_vfptr;
    AFX_MODULE_STATE* m_pModuleState;
};

AFX_MODULE_STATE* __stdcall AfxGetModuleState();
int __stdcall AfxDeactivateActCtx(unsigned long dwFlags, unsigned long ulCookie);

struct AFX_MAINTAIN_STATE2 {
    explicit AFX_MAINTAIN_STATE2(AFX_MODULE_STATE* pModuleState);
    ~AFX_MAINTAIN_STATE2()
    {
        if (m_pThreadState)
            m_pThreadState->m_pModuleState = m_pPrevModuleState;
        if (m_bValidActCtxCookie)
            AfxDeactivateActCtx(0, m_ulActCtxCookie);
    }
    AFX_MODULE_STATE* m_pPrevModuleState;
    _AFX_THREAD_STATE* m_pThreadState;
    unsigned long m_ulActCtxCookie;
    int m_bValidActCtxCookie;
};

struct IUnknownLike {
    virtual long __stdcall QueryInterface(const void* iid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct LocalPtr {
    IUnknownLike* p;
    LocalPtr() : p(0) {}
    ~LocalPtr() { if (p) p->Release(); }
};

void* __cdecl helper_00412090(void* p);

struct S {
    long __stdcall method(long unused, void** result);
};

long __stdcall S::method(long, void** result)
{
    AFX_MAINTAIN_STATE2 _ctlState(AfxGetModuleState());
    LocalPtr local;
    if (result)
        *result = helper_00412090(0);
    return 0x80004001L;
}
