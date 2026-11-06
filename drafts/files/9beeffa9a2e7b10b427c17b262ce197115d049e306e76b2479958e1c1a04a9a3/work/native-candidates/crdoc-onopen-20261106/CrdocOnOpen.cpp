// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// Inactive recovery probe: OnOpenDocument (004513c0, 449B) rebuilt from the
// original assembly, not the canonical source (which describes file loading
// the original does not perform). No linked selection/runtime activation.
#include <afxwin.h>
#include <afxdlgs.h>
#include <afxpriv.h>
#include "v8xml/XmlElement.h"
#include "v8xml/SerializerV2.h"
#include "v8tree/Verb.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/Visit.h"
#include "script/ScriptContext.h"
#include "../native-headers/CRobloxDoc.h"
#include "../native-headers/CSaveToRobloxDialog.h"
#include "../native-headers/StandardVerbs.h"
#include "../native-headers/CWorkspace.h"
#include "util/RunStateOwner.h"
#include "util/FileSystem.h"
#include "util/Log.h"
#include "util/StandardOut.h"
#include "Network/Players.h"
#include <exception>
#include <fstream>
#include <shlobj.h>
#include <shlwapi.h>

IMPLEMENT_DYNCREATE(CRobloxDoc, CDocument)

BEGIN_MESSAGE_MAP(CRobloxDoc, CDocument)
END_MESSAGE_MAP()

CRobloxDoc::CRobloxDoc() : standardVerbs(0), workspace(0) {}
CRobloxDoc::~CRobloxDoc() { delete standardVerbs; }

BOOL CRobloxDoc::OnOpenDocument(LPCTSTR path)
{
    boost::shared_ptr<RBX::DataModel> guard = getDataModel();
    std::vector<RBX::Verb*>::iterator i = ownedVerbs.begin();
    std::vector<RBX::Verb*>::iterator last = ownedVerbs.end();
    for (; i != last; ++i)
        delete *i;
    ownedVerbs.erase(ownedVerbs.begin(), ownedVerbs.end());
    RBX::StandardVerbs* old = standardVerbs;
    standardVerbs = 0;
    delete old;
    if (workspace) {
        workspace->Release();
        workspace = 0;
    }
    CDocument::DeleteContents();
    return TRUE;
}
