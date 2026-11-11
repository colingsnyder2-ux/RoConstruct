// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// DocumentUrl | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src c492a683 | roc native-status --write
#include <afxwin.h>
#include <atlbase.h>
#include <stdexcept>
#include "CRobloxDoc.h"
#include "CWorkspace.h"
#include "util/FileSystem.h"

static CString copyDocument(CRobloxDoc* doc, const char* suffix)
{
    CString result;
    GetShortPathNameA(RBX::FileSystem::getUserAppDataDirectory(true, "Test").c_str(), result.GetBuffer(MAX_PATH), MAX_PATH);
    result.ReleaseBuffer();
    result += suffix;
    result += ".rbxl";
    if (doc->workspace->SaveToFile(ATL::CComBSTR(result)) != S_OK)
        throw std::runtime_error("Failed to copy document");
    return result;
}

// Linkage bridge only. The original static helper is emitted once authentic callers join it.
CString documentUrl(CRobloxDoc* doc, const char* suffix)
{
    return copyDocument(doc, suffix);
}

