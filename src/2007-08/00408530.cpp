// from server: 100% by EspClaude
// from server: 53% by colin
// roc 2007-08 00408530  unit: VCApp::?$CComObject  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00408530
//
// 00408530  6aff                 push -1
// 00408532  6878af7600           push 0x76af78
// 00408537  64a100000000         mov eax, dword ptr fs:[0]
// 0040853d  50                   push eax
// 0040853e  83ec10               sub esp, 0x10
// 00408541  56                   push esi
// 00408542  a188518b00           mov eax, dword ptr [0x8b5188]
// 00408547  33c4                 xor eax, esp
// 00408549  50                   push eax
// 0040854a  8d442418             lea eax, [esp + 0x18]
// 0040854e  64a300000000         mov dword ptr fs:[0], eax
// 00408554  e8eb792200           call 0x62ff44
// 00408559  50                   push eax
// 0040855a  8d4c240c             lea ecx, [esp + 0xc]
// 0040855e  e8db792200           call 0x62ff3e
// 00408563  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0040856b  e892792200           call 0x62ff02
// 00408570  8b4004               mov eax, dword ptr [eax + 4]
// 00408573  6a00                 push 0
// 00408575  8bc8                 mov ecx, eax
// 00408577  e8a4fb0300           call 0x448120
// 0040857c  8bf0                 mov esi, eax
// 0040857e  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00408582  f7de                 neg esi
// 00408584  1bf6                 sbb esi, esi
// 00408586  81e6fbbfff7f         and esi, 0x7fffbffb
// 0040858c  81c605400080         add esi, 0x80004005
// 00408592  85c0                 test eax, eax
// 00408594  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0040859c  7407                 je 0x4085a5
// 0040859e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004085a2  894804               mov dword ptr [eax + 4], ecx
// 004085a5  837c241400           cmp dword ptr [esp + 0x14], 0
// 004085aa  740c                 je 0x4085b8
// 004085ac  8b542410             mov edx, dword ptr [esp + 0x10]
// 004085b0  52                   push edx
// 004085b1  6a00                 push 0
// 004085b3  e880792200           call 0x62ff38
// 004085b8  8bc6                 mov eax, esi
// 004085ba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004085be  64890d00000000       mov dword ptr fs:[0], ecx
// 004085c5  59                   pop ecx
// 004085c6  5e                   pop esi
// 004085c7  83c41c               add esp, 0x1c
// 004085ca  c20400               ret 4

typedef long HRESULT;
struct AFX_MODULE_STATE;
struct _AFX_THREAD_STATE { void* _v; AFX_MODULE_STATE* m_pModuleState; };
class CWinApp;
struct AFX_MODULE_STATE { void* _v; CWinApp* m_pCurrentWinApp; };   // +4
AFX_MODULE_STATE* __stdcall AfxGetAppModuleState();
AFX_MODULE_STATE* __stdcall AfxGetModuleState();
void __stdcall AfxDeactivateActCtx(unsigned long, unsigned long);
struct AFX_MAINTAIN_STATE2 {
    AFX_MAINTAIN_STATE2(AFX_MODULE_STATE*);
    ~AFX_MAINTAIN_STATE2() {
        if (m_pThreadState) m_pThreadState->m_pModuleState = m_pPrevModuleState;
        if (m_bValidActCtxCookie) AfxDeactivateActCtx(0, m_ulActCtxCookie);
    }
    AFX_MODULE_STATE* m_pPrevModuleState;
    _AFX_THREAD_STATE* m_pThreadState;
    unsigned long m_ulActCtxCookie;
    int m_bValidActCtxCookie;
};
#define AFX_MANAGE_STATE(p) AFX_MAINTAIN_STATE2 _ctlState(p);
class CWinApp { public: virtual ~CWinApp(); };
inline CWinApp* AfxGetApp() { return AfxGetModuleState()->m_pCurrentWinApp; }
class CRobloxApp : public CWinApp { public: int command(int); };   // 0x448120, thiscall

class VCApp {
public:
    HRESULT __stdcall Method();
};

HRESULT __stdcall VCApp::Method()
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    return static_cast<CRobloxApp*>(AfxGetApp())->command(0) ? 0 : 0x80004005;
}
