// =============================================================================
// VerbContainer.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8tree/VerbContainer.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <map>
#include <string>

namespace RBX
{
class Name;
class Verb;

class VerbContainer {
    friend class Verb; // 005833e0 registers itself in the verb map inline
    std::map<const Name*, Verb*> verbs;
    VerbContainer* parent;
public:
    explicit VerbContainer(VerbContainer* parent);
    virtual ~VerbContainer();
    Verb* getVerb(std::string name);
    Verb* getVerb(const Name& name);
    void setVerbParent(VerbContainer* parent);
    VerbContainer* getVerbParent() const;
private:
    void addVerb(Verb*);
    void removeVerb(Verb*);
};
}
