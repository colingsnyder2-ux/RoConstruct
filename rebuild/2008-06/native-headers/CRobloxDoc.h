#pragma once
#include "VerbBinder.h"
#include <memory>
#include <vector>

class XmlElement;
class CWorkspace;
namespace RBX { class Verb; struct StandardVerbs; }

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
