// =============================================================================
// Verb.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8tree/Verb.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8tree/IDataState.h"
#include "v8tree/VerbContainer.h"
#include "util/Name.h"
#include "util/Debug.h"
#include <string>

namespace RBX
{
class __declspec(novtable) Verb : public Debugable {
    const Name& name;
    VerbContainer* container;
protected:
    Verb(VerbContainer*, const Name&);
    Verb(VerbContainer*, std::string);
public:
    virtual ~Verb();
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    const Name& getName() const;
    virtual void doIt(IDataState*) = 0;
    VerbContainer* getContainer() const;
};
}
