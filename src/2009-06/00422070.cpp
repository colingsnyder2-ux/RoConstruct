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
