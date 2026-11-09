// from server: 100% by EspClaude
// roc 2008-06 0046f6b0  unit: RBX::LDraw2Lua::LDrawParser
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <vector>
#include <ostream>

namespace RBX {
namespace LDraw2Lua {

class LDrawItem {
public:
    virtual ~LDrawItem();
    virtual void writeLua(std::ostream& out, std::string parent) const;
};

class LDrawParser {
    void* vtbl_pad;
    struct Name { __declspec(dllimport) const char* c_str() const; char pad[0x1c]; } name;
    std::vector<LDrawItem*> items;
public:
    void writeLua(std::ostream& out) const;
};

void LDrawParser::writeLua(std::ostream& out) const
{
    if (items.size() > 0) {
        out << "-- " << "Get the current workspace" << "\n";
        out << "local w = game:service(\"Workspace\")" << "\n";
        out << "\n";
        out << "-- " << "Create a new model" << "\n";
        out << "m = Instance.new(\"Model\")" << "\n";
        out << "m.Name = \"" << name.c_str() << "\"" << "\n";
        out << "m.Parent = w" << "\n";
        out << "\n";
        size_t count = items.size();
        for (size_t i = 0; i < count; ++i)
            items.at(i)->writeLua(out, "m");
    }
}

}
}
