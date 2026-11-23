// =============================================================================
// ClipboardVerbs.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/ClipboardVerbs.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <afxwin.h>
#include "StandardVerbs.h"

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
