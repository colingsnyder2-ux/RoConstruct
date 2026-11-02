#include <afxwin.h>
#include <afxdlgs.h>
#include "v8xml/XmlElement.h"
#include "v8xml/SerializerV2.h"
#include "v8tree/Verb.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "script/ScriptContext.h"
#include "../native-headers/CRobloxDoc.h"
#include "../native-headers/CSaveToRobloxDialog.h"
#include "../native-headers/StandardVerbs.h"
#include "../native-headers/CWorkspace.h"
#include "util/RunStateOwner.h"
#include "util/Log.h"
#include "util/StandardOut.h"
#include "Network/Players.h"
#include <exception>
#include <fstream>
#include <shlobj.h>
#include <shlwapi.h>

IMPLEMENT_DYNCREATE(CRobloxDoc, CDocument)

// Original 00817f18 message entries; handler implementations remain under recovery.
BEGIN_MESSAGE_MAP(CRobloxDoc, CDocument)
    ON_COMMAND(0x8025, handle_44f7c0)
    ON_UPDATE_COMMAND_UI(0x8025, handle_453af0)
    ON_COMMAND(0xe12b, handle_453670)
    ON_UPDATE_COMMAND_UI(0xe12b, handle_453750)
    ON_COMMAND(0xe12c, handle_4538b0)
    ON_UPDATE_COMMAND_UI(0xe12c, handle_453990)
    ON_COMMAND(0x80b6, handle_44fc50)
    ON_UPDATE_COMMAND_UI(0x80b6, OnUpdateAlwaysEnable)
    ON_UPDATE_COMMAND_UI(0x80b7, handle_453af0)
    ON_COMMAND(0x80b7, handle_44fcc0)
    ON_NOTIFY(0x64, 0x80c3, handle_453c30)
    ON_UPDATE_COMMAND_UI(0x80c3, OnUpdateAlwaysEnable)
    ON_COMMAND(0x80c7, handle_455460)
    ON_UPDATE_COMMAND_UI(0x80c7, handle_454040)
    ON_COMMAND(0x80c8, handle_455580)
    ON_UPDATE_COMMAND_UI(0x80c8, handle_454170)
    ON_COMMAND(0x80c6, handle_455820)
    ON_UPDATE_COMMAND_UI(0x80c6, handle_454300)
    ON_UPDATE_COMMAND_UI(0xbb, handle_450a70)
    ON_UPDATE_COMMAND_UI(0xbe, handle_450c00)
    ON_UPDATE_COMMAND_UI(0xd1, handle_450d90)
    ON_UPDATE_COMMAND_UI(0x80da, handle_454490)
    ON_COMMAND(0x80da, handle_4545d0)
    ON_UPDATE_COMMAND_UI(0x80f6, handle_4547b0)
    ON_UPDATE_COMMAND_UI(0x80db, handle_454920)
    ON_COMMAND(0x80f1, handle_455c30)
    ON_UPDATE_COMMAND_UI(0x80f1, OnUpdateAlwaysEnable)
    ON_COMMAND(0x80f8, handle_454c90)
    ON_UPDATE_COMMAND_UI(0x80f8, OnUpdateAlwaysEnable)
    ON_UPDATE_COMMAND_UI(0x8021, OnUpdateAlwaysEnable)
    ON_COMMAND(0x8021, handle_450f30)
    ON_COMMAND(0x8100, handle_44fd30)
    ON_UPDATE_COMMAND_UI(0x8100, handle_454f30)
    ON_COMMAND(0x8104, handle_4500d0)
    ON_UPDATE_COMMAND_UI(0x8104, OnUpdateAlwaysEnable)
    ON_UPDATE_COMMAND_UI(0x8108, OnUpdateAlwaysEnable)
    ON_COMMAND(0x8108, handle_4501c0)
    ON_COMMAND(0x8109, handle_4502b0)
    ON_UPDATE_COMMAND_UI(0x8109, OnUpdateAlwaysEnable)
END_MESSAGE_MAP()

// Original 00428850 logs std::exception::what(); recovery/linking remains open.
void reportDocumentException(const std::exception&);
CString applicationBaseUrl();
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

// 00450890: Workspace RTTI places its VerbContainer at +0x2ec.
inline RBX::VerbContainer* workspaceVerbs(RBX::Workspace* root) {
    return root ? reinterpret_cast<RBX::VerbContainer*>(reinterpret_cast<char*>(root) + 0x2ec) : 0;
}
RBX::VerbContainer* CRobloxDoc::getVerbContainer() {
    return workspaceVerbs(getDataModel()->getWorkspace());
}

// 0042e550: common update handler used by several document commands.
void CRobloxDoc::OnUpdateAlwaysEnable(CCmdUI* ui) { ui->Enable(TRUE); }

inline RBX::RunService* documentRunService(const boost::shared_ptr<RBX::DataModel>& model) {
    return model ? model->create<RBX::RunService>() : 0;
}
// 00453670: invoke undo under the document model lock.
void CRobloxDoc::handle_453670() {
    boost::shared_ptr<RBX::DataModel> model = workspace->getDataModel();
    RBX::DataModel::Lock lock(model);
    model->create<RBX::ChangeHistoryService>()->unplay();
}

// 004538b0: redo the next recorded change.
void CRobloxDoc::handle_4538b0() {
    boost::shared_ptr<RBX::DataModel> model = workspace->getDataModel();
    RBX::DataModel::Lock lock(model);
    model->create<RBX::ChangeHistoryService>()->play();
}

// Original undo/redo command captions and availability.
void CRobloxDoc::handle_453750(CCmdUI* ui) {
    boost::shared_ptr<RBX::DataModel> model = workspace->getDataModel();
    RBX::DataModel::Lock lock(model);
    RBX::ChangeHistoryService* history = model->create<RBX::ChangeHistoryService>();
    std::string name;
    ui->Enable(history->queryUnplay(name, 0));
    CString caption;
    caption.Format(0x82, name.c_str());
    ui->SetText(caption);
}
void CRobloxDoc::handle_453990(CCmdUI* ui) {
    boost::shared_ptr<RBX::DataModel> model = workspace->getDataModel();
    RBX::DataModel::Lock lock(model);
    RBX::ChangeHistoryService* history = model->create<RBX::ChangeHistoryService>();
    std::string name;
    ui->Enable(history->queryPlay(name, 0));
    CString caption;
    caption.Format(0x83, name.c_str());
    ui->SetText(caption);
}

// 00453af0: enable command when selection has entries.
void CRobloxDoc::handle_453af0(CCmdUI* ui) {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    RBX::Selection* selected = RBX::ServiceProvider::create<RBX::Selection>(workspace->getDataModel().get());
    ui->Enable(selected->selection->size() > 0);
}

// 00454040: pause is available while simulation runs.
void CRobloxDoc::handle_454040(CCmdUI* ui) {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    ui->Enable(getDataModel()->create<RBX::RunService>()->getRunState() == RBX::RS_RUNNING);
}

// 00454170: stop is available for local simulation without a local player.
void CRobloxDoc::handle_454170(CCmdUI* ui) {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    RBX::RunState state = getDataModel()->create<RBX::RunService>()->getRunState();
    bool player = RBX::Network::Players::findLocalPlayer(getDataModel().get()) != 0;
    ui->Enable(state && !player);
}

// 00454300: run is unavailable for remote clients or an active simulation.
void CRobloxDoc::handle_454300(CCmdUI* ui) {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    RBX::RunService* state = getDataModel()->create<RBX::RunService>();
    bool client = RBX::Network::Client::clientIsPresent(getDataModel().get(), true);
    ui->Enable(!client && state->getRunState() != RBX::RS_RUNNING);
}

// Original status bar game-time and frame-rate updates.
void CRobloxDoc::handle_450a70(CCmdUI* ui) {
    if (getDataModel()) {
        char text[32];
        {
            RBX::DataModel::Lock lock(workspace->getDataModel());
            sprintf(text, "t %.4g", getDataModel()->getGameTime());
        }
        ui->SetText(text);
    }
}
void CRobloxDoc::handle_450c00(CCmdUI* ui) {
    if (getDataModel()) {
        char text[32];
        {
            RBX::DataModel::Lock lock(workspace->getDataModel());
            sprintf(text, "%.3gfps", getDataModel()->getFrameRate());
            ui->SetText(text);
        }
    }
}

inline bool RBX::ScriptContext::hasState() const { return globalState != 0; }
// 00454490: enable script operations when a Lua state exists.
void CRobloxDoc::handle_454490(CCmdUI* ui) {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    RBX::ScriptContext* context = RBX::ServiceProvider::create<RBX::ScriptContext>(getDataModel().get());
    ui->Enable(context && context->hasState());
}

// 004547b0: display active script thread count.
void CRobloxDoc::handle_4547b0(CCmdUI* ui) {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    RBX::ScriptContext* context = RBX::ServiceProvider::create<RBX::ScriptContext>(getDataModel().get());
    if (context && context->allocator) {
        char text[32];
        sprintf(text, "%d threads", context->getThreadCount());
        ui->SetText(text);
        ui->Enable(TRUE);
    } else {
        ui->SetText("");
        ui->Enable(FALSE);
    }
}

// 00450d90: display simulation duty cycle.
void CRobloxDoc::handle_450d90(CCmdUI* ui) {
    if (getDataModel()) {
        RBX::DataModel::Lock lock(workspace->getDataModel());
        double value = getDataModel()->getDutyCycle() * 100.0;
        char text[32];
        sprintf(text, "%.3g%%", value);
        ui->SetText(text);
    }
}

// 00454920: display script allocator heap usage.
void CRobloxDoc::handle_454920(CCmdUI* ui) {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    RBX::ScriptContext* context = RBX::ServiceProvider::create<RBX::ScriptContext>(getDataModel().get());
    if (context && context->allocator) {
        size_t bytes, blocks;
        context->allocator->getHeapStats(bytes, blocks);
        std::string text = RBX::Log::formatMem(bytes);
        ui->SetText(text.c_str());
        ui->Enable(TRUE);
    } else {
        ui->SetText("");
        ui->Enable(FALSE);
    }
}

// 004545d0: collect Lua garbage and report allocator and thread totals.
void CRobloxDoc::handle_4545d0() {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    RBX::ScriptContext* context = RBX::ServiceProvider::create<RBX::ScriptContext>(getDataModel().get());
    if (context && context->allocator) {
        context->gc();
        size_t bytes, blocks;
        context->allocator->getHeapStats(bytes, blocks);
        std::string heap = RBX::Log::formatMem(bytes);
        unsigned int threads = context->getThreadCount();
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO,
            "Script heap %s (%d blocks), %d threads", heap.c_str(), blocks, threads);
    }
}

// 00454f30: enable abuse reporting when the players service supports it.
void CRobloxDoc::handle_454f30(CCmdUI* ui) {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    ui->Enable(getDataModel()->create<RBX::Network::Players>()->canReportAbuse());
}

// 0044f7c0: save selected instances to a model file.
void CRobloxDoc::handle_44f7c0() {
    CString filter;
    filter.LoadString(184);
    CFileDialog dialog(FALSE, "rbxm", NULL, 6, filter, NULL, 0, TRUE);
    if (dialog.DoModal() == IDOK) {
        ATL::CComBSTR filename((LPCSTR)dialog.GetPathName());
        workspace->SaveSelectionToFile(filename);
    }
}

// 0044fc50 / 0044fcc0: open native publish dialogs.
void CRobloxDoc::handle_44fc50() {
    CPublishAsPlaceDialog dialog(workspace, 0);
    dialog.DoModal();
}
void CRobloxDoc::handle_44fcc0() {
    CSaveModelToRobloxDialog dialog(workspace, 0);
    dialog.DoModal();
}

// 0044fd30: show the in-game abuse report dialog.
void CRobloxDoc::handle_44fd30() {
    CRobloxDHtmlDialog dialog(0x7b, applicationBaseUrl() + "/AbuseReport/InGameChat.aspx", 0);
    dialog.SetExternalDispatch(workspace);
    dialog.DoModal();
}

// 00455580: stop simulation, restore the saved place and rebuild joints.
void CRobloxDoc::handle_455580() {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    if (getDataModel()->create<RBX::RunService>()->getRunState() != RBX::RS_NORMAL) {
        documentRunService(getDataModel())->setRunState(RBX::RS_NORMAL);
        getDataModel()->clearContents();
        SerializerV2::load(savedState.get(), getDataModel().get());
        getDataModel()->getWorkspace()->joinAllHack();
        savedState.reset();
    }
}

// 00450f30: insert a model file into the current place.
void CRobloxDoc::handle_450f30() {
    CString filter;
    filter.LoadString(184);
    CFileDialog dialog(TRUE, "rbxm", NULL, 6, filter, NULL, 0, TRUE);
    if (dialog.DoModal() == IDOK) {
        std::ifstream input(dialog.GetPathName(), std::ios::in | std::ios::binary);
        RBX::DataModel::Lock lock(workspace->getDataModel());
        workspace->insert(input, true);
    }
}

// 00455460: pause the current simulation.
void CRobloxDoc::handle_455460() {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    documentRunService(getDataModel())->setRunState(RBX::RS_PAUSED);
}

// 00455820: snapshot before entering play, then start simulation.
void CRobloxDoc::handle_455820() {
    RBX::DataModel::Lock lock(workspace->getDataModel());
    if (getDataModel()->create<RBX::RunService>()->getRunState() == RBX::RS_NORMAL) {
        savedState.reset(SerializerV2::newRootElement());
        getDataModel()->writeChildren(savedState.get());
    }
    documentRunService(getDataModel())->setRunState(RBX::RS_RUNNING);
}

// 0044f8d0: preserve original save guard before calling MFC.
BOOL CRobloxDoc::DoSave(LPCTSTR path, BOOL replace) {
    if (!canSaveDocument(workspace->getDataModel().get())) return FALSE;
    return CDocument::DoSave(path, replace);
}

// 0044f9b0: save through the native COM workspace.
BOOL CRobloxDoc::OnSaveDocument(LPCTSTR path) {
    if (!canSaveDocument(workspace->getDataModel().get())) return FALSE;
    if (workspace->SaveToFile(ATL::CComBSTR(path)) != 0) return FALSE;
    SetModifiedFlag(FALSE);
    return TRUE;
}

// 004533f0: reject cached paths, then load and enable history.
BOOL CRobloxDoc::OnOpenDocument(LPCTSTR path) {
    {
        char folder[MAX_PATH];
        if (SHGetFolderPathA(0, CSIDL_INTERNET_CACHE, 0, 0, folder) == S_OK) {
            CString relative;
            char* buffer = relative.GetBuffer(MAX_PATH);
            BOOL result = PathRelativePathToA(buffer, folder, FILE_ATTRIBUTE_DIRECTORY, path, 0);
            relative.ReleaseBuffer();
            if (result) {
                bool inCache = relative.Left(2).Compare(".\\") == 0;
                if (inCache) return FALSE;
            }
        }
    }
    DeleteContents();
    initializeCommands();
    SetModifiedFlag(TRUE);
    try {
        std::ifstream input(path, std::ios::in | std::ios::binary);
        workspace->load(input);
        SetModifiedFlag(FALSE);
        RBX::DataModel::Lock lock(workspace->getDataModel());
        RBX::ChangeHistoryService* history = workspace->getDataModel()->create<RBX::ChangeHistoryService>();
        history->setEnabled(true);
        return TRUE;
    } catch (const std::exception& error) {
        reportDocumentException(error);
        ReportSaveLoadException(path, 0, FALSE, 0xf101);
        return FALSE;
    }
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
        reportDocumentException(error);
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
        commandNames[static_cast<DWORD>(id)] = name;
    } else {
        const RBX::Name* name = &RBX::Name::getNullName();
        commandNames[static_cast<DWORD>(id)] = name;
    }
}

// 00451a60: document also tracks the newly owned verb.
void CRobloxDoc::bindOwned(UINT id, RBX::Verb* verb) {
    if (verb) {
        ownedVerbs.push_back(verb);
        commandNames[static_cast<DWORD>(id)] = &verb->getName();
    } else {
        const RBX::Name* name = &RBX::Name::getNullName();
        commandNames[static_cast<DWORD>(id)] = name;
    }
}

// 00451690: route mapped commands through the workspace verb container.
template<>
BOOL VerbBinder<CRobloxDoc, CDocument>::OnCmdMsg(UINT id, int code, void* extra, AFX_CMDHANDLERINFO* info) {
    if (code == 0 || code == -1) {
        std::map<UINT, const RBX::Name*>::iterator it = commandNames.find(id);
        if (it != commandNames.end() && it->second) {
            CRobloxDoc* doc = static_cast<CRobloxDoc*>(this);
            boost::shared_ptr<RBX::DataModel> model = doc->getDataModel();
            RBX::DataModel::Lock lock(model);
            const RBX::Name* name = it->second;
            RBX::VerbContainer* verbs = doc->getVerbContainer();
            RBX::Verb* verb = verbs ? verbs->getVerb(*name) : 0;
            if (verb) {
                if (code == 0) {
                    try { verb->doIt(model ? static_cast<RBX::IDataState*>(model.get()) : 0); }
                    catch (std::exception& error) { AfxMessageBox(error.what(), 0, 0); }
                } else {
                    CCmdUI* ui = static_cast<CCmdUI*>(extra);
                    ui->Enable(verb->isEnabled() ? TRUE : FALSE);
                    ui->SetCheck(verb->isChecked() ? 1 : 0);
                }
            }
            return TRUE;
        }
    }
    return CDocument::OnCmdMsg(id, code, extra, info);
}
