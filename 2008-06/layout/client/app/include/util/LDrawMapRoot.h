// =============================================================================
// LDrawMapRoot.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/LDrawMapRoot.h
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
#include <vector>

namespace RBX { namespace LDraw2Lua {
class LDraw2RobloxColorMap {
public:
    virtual ~LDraw2RobloxColorMap();
    int ldrawCode, robloxCode;
    LDraw2RobloxColorMap(int, int);
    int getLDrawCode() const { return ldrawCode; }
};
struct NativeRobloxPart {
    int shape, formFactor;
    std::string size, offset;
    NativeRobloxPart(int, int, std::string, std::string);
};
class LDraw2RobloxPartMap {
public:
    virtual ~LDraw2RobloxPartMap();
    std::string name, description, filename;
    int fidelity;
    std::vector<NativeRobloxPart> parts;
    LDraw2RobloxPartMap(std::string, std::string, std::string, int);
    void addPart(const NativeRobloxPart&);
    std::string getFilename() const;
    NativeRobloxPart* getPart();
};
class LDraw2RobloxMapRoot {
public:
    virtual ~LDraw2RobloxMapRoot();
    std::string path, version;
    std::map<int, LDraw2RobloxColorMap*> colors;
    std::map<std::string, LDraw2RobloxPartMap*> parts;
    explicit LDraw2RobloxMapRoot(std::string);
    LDraw2RobloxColorMap* findColor(int);
    int mapColor(int);
    LDraw2RobloxPartMap* findPart(const std::string&);
    LDraw2RobloxPartMap* findPartCaseInsensitive(const std::string&);
    int readFidelity(std::string);
    int readShape(std::string);
    int readFormFactor(std::string);
    void addPartMap(LDraw2RobloxPartMap*);
};
} }
