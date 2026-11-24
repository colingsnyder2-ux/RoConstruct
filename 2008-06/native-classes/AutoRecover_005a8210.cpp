// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

namespace RBX {

class Guid {
public:
    // INFERRED: scope node layout; string lives at +4 per the disassembly
    struct Scope {
        int reserved;
        std::string name;
    };

    struct Data {
        const Scope* scope;
        int index;

        bool operator<(const Data& other) const;
    };
};

bool Guid::Data::operator<(const Data& other) const
{
    // INFERRED: operand order and switch shape chosen to match load order and block layout
    const Scope* o = other.scope;
    const Scope* s = scope;
    if (s != o)
    {
        int c = s->name.compare(o->name);
        switch (c)
        {
        case -1:
            return true;
        case 0:
            break;
        default:
            return false;
        }
    }
    return index < other.index;
}

} // namespace RBX
