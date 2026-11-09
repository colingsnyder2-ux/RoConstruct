// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_5d9a25f9d36be9fc.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afx.h>
#include <atlbase.h>
#include <atlwin.h>
#include <atlsync.h>
namespace RBX {
class CMarshalWindow : public ATL::CWindowImpl<CMarshalWindow>
{
public:
    BEGIN_MSG_MAP(CMarshalWindow)
    END_MSG_MAP()
    int m_24;
    int m_28;
    ATL::CCriticalSection m_cs;
    CMarshalWindow(int a);
};
CMarshalWindow::CMarshalWindow(int a) : m_24(0)
{
    m_28 = a;
    Create(NULL, NULL, NULL, WS_POPUP);
}
}
