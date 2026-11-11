#pragma once
// >>> native-status (generated) -- do not edit >>>
// ClipboardVerbs | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src eb0bba7c | roc native-status --write
#include <afxwin.h>
#include "StandardVerbs.h"

// Empty native base, established by RTTI and the existing verb constructors.
class ClipboardObject {};
class CutVerb : public RBX::DeleteSelectionVerb, public ClipboardObject {
public:
    __declspec(noinline) CutVerb(RBX::DataModel*);
    virtual void doIt(RBX::IDataState*);
};
class CopyVerb : public RBX::EditSelectionVerb, public ClipboardObject {
public:
    __declspec(noinline) CopyVerb(RBX::DataModel*);
    virtual void doIt(RBX::IDataState*);
};
class PasteVerb : public RBX::Verb, public ClipboardObject {
    RBX::DataModel* dataModel;
    const bool pasteInto;
public:
    __declspec(noinline) PasteVerb(RBX::DataModel*, bool);
    virtual bool isEnabled() const;
    virtual void doIt(RBX::IDataState*);
};

inline UINT getClipboardFormat()
{
    static UINT format = ::RegisterClipboardFormatA("Roblox");
    return format;
}
