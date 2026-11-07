#pragma once
// >>> native-status (generated) -- do not edit >>>
// ViewVerbs | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 4c518ec7 | roc native-status --write
#include "v8tree/Verb.h"

class CRobloxView;

// Verbs created by CRobloxView's initializer (0045a4a0); class names from RTTI, sizes from
// operator new. All post WM_COMMAND to a window; the main frame is AfxGetApp()->m_pMainWnd.
class HelpCommand : public RBX::Verb {           // 0x10, vtable 00819140
    CRobloxView* view;                           // +0xc
public:
    HelpCommand(CRobloxView* view, RBX::VerbContainer* c) : RBX::Verb(c, "Help"), view(view) {}
    virtual void doIt(RBX::IDataState*);         // 00459150
};

class ToggleFullscreenVerb : public RBX::Verb {  // 0xc, vtable 00819114
public:
    explicit ToggleFullscreenVerb(RBX::VerbContainer* c) : RBX::Verb(c, "ToggleFullScreen") {}
    virtual bool isChecked() const;              // 00459100
    virtual void doIt(RBX::IDataState*);         // 00459120
};

class LockPlayModeVerb : public RBX::Verb {      // 0xc, vtable 008190ec
public:
    explicit LockPlayModeVerb(RBX::VerbContainer* c) : RBX::Verb(c, "LockPlayMode") {}
    virtual void doIt(RBX::IDataState*);         // 004590d0
};

class ToggleIDEModeVerb : public RBX::Verb {     // 0x18, vtable 008190c4; verb name "TogglePlayMode"
    double createdAt;                            // +0x10, G3D::System::getLocalTime at construction
public:
    explicit ToggleIDEModeVerb(RBX::VerbContainer*);  // 00458fd0
    virtual bool isEnabled() const;              // 00459040
    virtual bool isChecked() const;              // 00459080
    virtual void doIt(RBX::IDataState*);         // 004590a0
};
