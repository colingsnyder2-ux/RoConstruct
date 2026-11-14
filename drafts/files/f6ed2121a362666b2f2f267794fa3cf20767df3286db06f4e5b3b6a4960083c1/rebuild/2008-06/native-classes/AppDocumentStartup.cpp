// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../native-donor-2007
// >>> native-status (generated) -- do not edit >>>
// AppDocumentStartup | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by tester (ntech:glm-4.5-air)
// <<< native-status | src a3b980f3 | roc native-status --write
// LogManager.h (donor, via CRobloxApp.h) builds ThreadLogManager's inline constructor from RBX::get_thread_name;
// declared here as in the sibling AppLeftovers.cpp unit.
namespace RBX { const char* get_thread_name(); }
#include "CRobloxApp.h"
#include "CIDEDocManager.h"

void CRobloxApp::initializeEmptyDocument()
{
    static_cast<CIDEDocManager*>(m_pDocManager)->templates[0]->OpenDocumentFile(NULL, TRUE);
}
