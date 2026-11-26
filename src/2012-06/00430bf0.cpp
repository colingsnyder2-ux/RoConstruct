// from server: 100% by Xemicl
// roc 2012-06 00430bf0  unit: CSelectionTreeCtrl  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00430bf0
//
// 00430bf0  6aff                 push -1
// 00430bf2  6898b8ad00           push 0xadb898
// 00430bf7  64a100000000         mov eax, dword ptr fs:[0]
// 00430bfd  50                   push eax
// 00430bfe  64892500000000       mov dword ptr fs:[0], esp
// 00430c05  51                   push ecx
// 00430c06  56                   push esi
// 00430c07  8bf1                 mov esi, ecx
// 00430c09  89742404             mov dword ptr [esp + 4], esi
// 00430c0d  c70600000000         mov dword ptr [esi], 0
// 00430c13  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00430c17  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00430c1b  6a00                 push 0
// 00430c1d  50                   push eax
// 00430c1e  51                   push ecx
// 00430c1f  6a00                 push 0
// 00430c21  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00430c29  ff153c22b200         call dword ptr [0xb2223c]
// 00430c2f  8906                 mov dword ptr [esi], eax
// 00430c31  85c0                 test eax, eax
// 00430c33  7505                 jne 0x430c3a
// 00430c35  e8a6feffff           call 0x430ae0
// 00430c3a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00430c3e  8bc6                 mov eax, esi
// 00430c40  5e                   pop esi
// 00430c41  64890d00000000       mov dword ptr fs:[0], ecx
// 00430c48  83c410               add esp, 0x10
// 00430c4b  c20800               ret 8
// copied from an identical function in another client (function ??0CEvent@ATL@@QAE@HH@Z)

// from server: 100% by EspClaude
// roc 2009-06 00422070
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef void* HANDLE;
typedef int BOOL;
extern "C" __declspec(dllimport) HANDLE __stdcall CreateEventA(void*, BOOL, BOOL, const char*);
namespace ATL {
void AtlThrowLastWin32();
class CHandle {
public:
    CHandle() throw() : m_h(0) {}
    ~CHandle() throw();
    HANDLE m_h;
};
class CEvent : public CHandle {
public:
    CEvent(BOOL bManualReset, BOOL bInitialState);
    BOOL Create(void* pSecurity, BOOL bManualReset, BOOL bInitialState, const char* pszName) {
        m_h = ::CreateEventA(pSecurity, bManualReset, bInitialState, pszName);
        return m_h != 0;
    }
};
CEvent::CEvent(BOOL bManualReset, BOOL bInitialState)
{
    BOOL bSuccess;
    bSuccess = Create(0, bManualReset, bInitialState, 0);
    if (!bSuccess)
        AtlThrowLastWin32();
}
}