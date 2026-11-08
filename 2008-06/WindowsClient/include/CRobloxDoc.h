#pragma once
// >>> native-status (generated) -- do not edit >>>
// CRobloxDoc | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 4c6250bc | roc native-status --write
#include "VerbBinder.h"
#include <memory>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

class XmlElement;
class CWorkspace;
namespace RBX { class Verb; class VerbContainer; class DataModel; struct StandardVerbs; }

// Candidate shared declaration, not yet used by the shell. Native constructor
// 00451ac0, destructor 00451940, run/stop 00455820/00455580 and command setup
// 00451b60 establish these storage and ownership boundaries without padding.
class CRobloxDoc : public VerbBinder<CRobloxDoc, CDocument> {
    DECLARE_DYNCREATE(CRobloxDoc)

public:
    // The owning pointer ABI is proven; auto_ptr spelling is a codegen choice.
    std::auto_ptr<XmlElement> savedState;
    std::vector<RBX::Verb*> ownedVerbs;
    RBX::StandardVerbs* standardVerbs;
    CWorkspace* workspace;

    CRobloxDoc();
    virtual ~CRobloxDoc();
    void bindExisting(UINT, RBX::Verb*);
    void bindOwned(UINT, RBX::Verb*);
    void initializeCommands();
    int loadFile(std::string);
    int loadFromString(std::string);
    void OnUpdateAlwaysEnable(CCmdUI*);
    // Original message handlers, named by address until their identities are recovered.
    void handle_44f7c0();
    void handle_453af0(CCmdUI*);
    void handle_453670();
    void handle_453750(CCmdUI*);
    void handle_4538b0();
    void handle_453990(CCmdUI*);
    void handle_44fc50();
    void handle_44fcc0();
    void handle_453c30(NMHDR*, LRESULT*);
    void handle_455460();
    void handle_454040(CCmdUI*);
    void handle_455580();
    void handle_454170(CCmdUI*);
    void handle_455820();
    void handle_454300(CCmdUI*);
    void handle_450a70(CCmdUI*);
    void handle_450c00(CCmdUI*);
    void handle_450d90(CCmdUI*);
    void handle_454490(CCmdUI*);
    void handle_4545d0();
    void handle_4547b0(CCmdUI*);
    void handle_454920(CCmdUI*);
    void handle_455c30();
    void handle_454c90();
    void handle_450f30();
    void handle_44fd30();
    void handle_454f30(CCmdUI*);
    void handle_4500d0();
    void handle_4501c0();
    void handle_4502b0();
    boost::shared_ptr<RBX::DataModel> getDataModel();
    RBX::VerbContainer* getVerbContainer();
    virtual void SetTitle(LPCTSTR);
    virtual BOOL IsModified();
    virtual void SetModifiedFlag(BOOL = TRUE);
    virtual void DeleteContents();
    virtual BOOL OnNewDocument();
    virtual BOOL OnOpenDocument(LPCTSTR);
    virtual BOOL OnSaveDocument(LPCTSTR);
    virtual void OnCloseDocument();
    virtual BOOL SaveModified();
    virtual BOOL DoSave(LPCTSTR, BOOL = TRUE);

    DECLARE_MESSAGE_MAP()
};
