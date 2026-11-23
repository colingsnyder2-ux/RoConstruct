// =============================================================================
// LDrawEntities.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/LDrawEntities.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "util/LDrawMapRoot.h"
#include <ostream>
#include <string>
#include <vector>

namespace RBX { namespace LDraw2Lua {
class LDrawItem {
public:
    virtual ~LDrawItem();
    virtual bool writeLua(std::ostream&, std::string) const = 0;
};
class LDrawPart : public LDrawItem {
public:
    LDraw2RobloxMapRoot* output;
    int type, color;
    double values[12];
    std::string name;
    explicit LDrawPart(LDraw2RobloxMapRoot*);
    virtual ~LDrawPart() {}
    virtual bool writeLua(std::ostream&, std::string) const;
    void setName(std::string value) { name = value; }
    bool writeShape(std::ostream&, const NativeRobloxPart*) const;
    bool writeColor(std::ostream&) const;
    bool writeTransform(std::ostream&, std::string) const;
    bool writeParent(std::ostream&, std::string) const;
};
class LDrawModel {
public:
    virtual ~LDrawModel();
    std::string name;
    std::vector<LDrawItem*> items;
    explicit LDrawModel(const char*);
    void add(LDrawItem*);
    void writeLua(std::ostream&) const;
};
} }
