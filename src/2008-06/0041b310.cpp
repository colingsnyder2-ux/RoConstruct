// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_d2657038b371ce18.cpp

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
#include <deque>

struct MarshalLock {
    void* handle;
    bool owned;
    MarshalLock();
    ~MarshalLock();
};

class Marshaller : public ATL::CWindowImpl<Marshaller>
{
public:
    DWORD userData;
    DWORD threadId;
    std::deque<int> queue;
    MarshalLock lock;

    Marshaller(DWORD threadId);
    virtual ~Marshaller();

    BEGIN_MSG_MAP(Marshaller)
    END_MSG_MAP()
};

Marshaller::Marshaller(DWORD id) : userData(0)
{
    threadId = id;
    Create(NULL, NULL, NULL, WS_POPUP);
}
