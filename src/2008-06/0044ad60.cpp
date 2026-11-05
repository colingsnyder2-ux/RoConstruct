// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_appexit_82405606eefa1aeb.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Handle;

extern Handle __cdecl acquire();
extern void __cdecl report(void*, int, const char*);
extern int __stdcall cleanup(void*);
extern const char exitMessage[];
extern char cleanupObject;

struct CRobloxApp
{
    int ExitInstance();
    int finish();
};

int CRobloxApp::ExitInstance()
{
    report(acquire().get(), 1, exitMessage);
    cleanup(&cleanupObject);
    return finish();
}