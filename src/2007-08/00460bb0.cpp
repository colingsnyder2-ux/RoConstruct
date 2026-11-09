// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: atl-8.0 roc_espclaude_86391b04ef95b786.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#define _DLL
#include <atlbase.h>
struct LockOwner { char pad[0x2c]; CRITICAL_SECTION cs; };
class Marshaler {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void doEvent(int a, int b) throw();
    void onEvent(int a, int b) throw();
    int pad[5];
    LockOwner* owner;
};
void Marshaler::onEvent(int a, int b) throw()
{
    ATL::CCritSecLock lock(owner->cs);
    doEvent(a, b);
}
