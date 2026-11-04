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
