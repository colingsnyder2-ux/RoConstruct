#include <afxwin.h>
#include "v8xml/XmlElement.h"
#include "v8tree/Verb.h"
#include "v8datamodel/DataModel.h"
#include "../native-headers/CRobloxDoc.h"
#include "../native-headers/StandardVerbs.h"
#include "../native-headers/CWorkspace.h"
#include <exception>

IMPLEMENT_DYNCREATE(CRobloxDoc, CDocument)

// Original 00428850 logs std::exception::what(); recovery/linking remains open.
void reportDocumentCreateException(const std::exception&);
extern CRobloxDoc* currentDocument;
void setCurrentDocument(int, CRobloxDoc*);
// Native predicates 00495e60/00495e70 resolve to NetworkClient/NetworkServer lookups.
namespace RBX { namespace Network {
class Client { public: static bool clientIsPresent(const Instance*, bool); };
class Server { public: static bool serverIsPresent(const Instance*, bool); };
} }
inline bool canSaveDocument(RBX::DataModel* model) {
    if (RBX::Network::Client::clientIsPresent(model, true) && !RBX::Network::Server::serverIsPresent(model, true)) return false;
    return true;
}

// Existing recovered 00451ac0, expressed through the shared native fields.
CRobloxDoc::CRobloxDoc() : standardVerbs(0), workspace(0) {}

// 00451940: DeleteContents owns the workspace/verb cleanup before destruction.
CRobloxDoc::~CRobloxDoc() { delete standardVerbs; }

boost::shared_ptr<RBX::DataModel> CRobloxDoc::getDataModel() {
    if (workspace) return workspace->getDataModel();
    return boost::shared_ptr<RBX::DataModel>();
}

// 0044f8d0: preserve original save guard before calling MFC.
BOOL CRobloxDoc::DoSave(LPCTSTR path, BOOL replace) {
    if (!canSaveDocument(workspace->getDataModel().get())) return FALSE;
    return CDocument::DoSave(path, replace);
}

// 0044fb80: keep document and DataModel titles in sync.
void CRobloxDoc::SetTitle(LPCTSTR title) {
    CDocument::SetTitle(title);
    if (workspace) {
        std::string name(title);
        workspace->getDataModel()->setName(name);
    }
}

// 004508f0: query dirty state while holding the DataModel lock.
BOOL CRobloxDoc::IsModified() {
    if (getDataModel()) {
        RBX::DataModel::Lock lock(getDataModel());
        return getDataModel()->isDirty();
    }
    return FALSE;
}

// 0044fad0: synchronize MFC modification flag with native IDataState.
void CRobloxDoc::SetModifiedFlag(BOOL modified) {
    m_bModified = modified;
    if (workspace) workspace->getDataModel()->setDirty(modified == TRUE);
}

void CRobloxDoc::OnCloseDocument() { CDocument::OnCloseDocument(); }

void CRobloxDoc::DeleteContents() {
    {
        RBX::DataModel::Lock lock(getDataModel());
        std::vector<RBX::Verb*>::iterator it = ownedVerbs.begin();
        std::vector<RBX::Verb*>::iterator last = ownedVerbs.end();
        for (; it != last; ++it)
            delete *it;
        ownedVerbs.erase(ownedVerbs.begin(), ownedVerbs.end());
        RBX::StandardVerbs* old = standardVerbs;
        standardVerbs = 0;
        delete old;
    }
    if (workspace) {
        workspace->cleanup();
        static_cast<IWorkspace*>(workspace)->Release();
        workspace = 0;
    }
    if (currentDocument == this) setCurrentDocument(1, this);
    CDocument::DeleteContents();
}

BOOL CRobloxDoc::OnNewDocument() {
    if (!CDocument::OnNewDocument()) return FALSE;
    try {
        initializeCommands();
    } catch (std::exception& error) {
        reportDocumentCreateException(error);
        AfxMessageBox("An error occured while creating the document", MB_ICONEXCLAMATION, 0);
        return FALSE;
    }
    SetModifiedFlag(FALSE);
    return TRUE;
}

inline const RBX::Name& RBX::Verb::getName() const { return name; }

// 00451a10: external verb ownership stays with its container.
void CRobloxDoc::bindExisting(UINT id, RBX::Verb* verb) {
    if (verb) {
        const RBX::Name* name = &verb->getName();
        commandNames[id] = name;
    } else {
        const RBX::Name* name = &RBX::Name::getNullName();
        commandNames[id] = name;
    }
}

// 00451a60: document also tracks the newly owned verb.
void CRobloxDoc::bindOwned(UINT id, RBX::Verb* verb) {
    if (verb) {
        ownedVerbs.push_back(verb);
        commandNames[id] = &verb->getName();
    } else {
        const RBX::Name* name = &RBX::Name::getNullName();
        commandNames[id] = name;
    }
}
