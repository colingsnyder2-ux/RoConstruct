#pragma once
#include "LDrawMapRoot.h"
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
