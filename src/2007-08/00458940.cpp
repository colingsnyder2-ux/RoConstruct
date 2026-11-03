// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: atl-8.0 roc_espclaude_4b89bba6d344f8c6.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#define _DLL
#include <atlbase.h>
extern CRITICAL_SECTION g_renderLock;
#pragma pack(push, 4)
class CRobloxWnd {
    char pad[0x2c];
    double m_lastTime;
public:
    void SetTime(double t);
};
#pragma pack(pop)
void CRobloxWnd::SetTime(double t)
{
    ATL::CCritSecLock lock(g_renderLock);
    m_lastTime = t;
}
