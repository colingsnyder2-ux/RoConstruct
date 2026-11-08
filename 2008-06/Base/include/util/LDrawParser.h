#pragma once
// >>> native-status (generated) -- do not edit >>>
// LDrawParser | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src ecd10d77 | roc native-status --write
#include <string>
#include <ostream>

namespace RBX { namespace LDraw2Lua {
class LDrawParser {
public:
    virtual ~LDrawParser();
    std::string fileName;
    explicit LDrawParser(const char*);
    void parse(std::ostream&);
};
} }
