// from server: 100% by EspClaude
// from server: 81% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_aa653535b7e152ad.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>

struct Reporter { void report(int, const char*); };
typedef boost::shared_ptr<Reporter> Handle;

extern Handle __cdecl acquire();
extern int __stdcall cleanup(void*);
extern const char exitMessage[];
extern char cleanupObject;

struct Lock { void release(); };
extern Lock lockA;
extern Lock lockB;
void __cdecl shutdownA();
void __cdecl shutdownB();
void __cdecl shutdownC();

struct CRobloxApp
{
    int ExitInstance();
    int finish();
};

int CRobloxApp::ExitInstance()
{
    acquire()->report(1, exitMessage);
    lockA.release();
    lockB.release();
    shutdownA();
    shutdownB();
    shutdownC();
    cleanup(&cleanupObject);
    return finish();
}
