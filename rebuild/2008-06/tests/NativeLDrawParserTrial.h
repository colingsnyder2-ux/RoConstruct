#pragma once
#include <string>
#include <ostream>

namespace RBX { namespace LDraw2Lua {
// Candidate; constructor, global ownership and full layout remain under proof.
class LDrawParser {
public:
    virtual ~LDrawParser();
    std::string fileName;
    explicit LDrawParser(const char*);
    void parse(std::ostream&);
};
} }
