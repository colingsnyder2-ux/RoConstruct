// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../native-donor-2007
// ThreadLogManager's donor inline constructor needs this original declaration.
namespace RBX { const char* get_thread_name(); }
#include "CRobloxApp.h"
#include "CIDEDocManager.h"

void CRobloxApp::initializeEmptyDocument()
{
    static_cast<CIDEDocManager*>(m_pDocManager)->templates[0]->OpenDocumentFile(NULL, TRUE);
}
