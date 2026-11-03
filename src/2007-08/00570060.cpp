// from server: 100% by EspClaude
// roc 2007-08 00570060  descriptor-name ordering predicate (std::operator< on the Name strings)
// roc-flags: /O2 /GS /EHsc /MD
#include <string>
namespace RBX {
class Name {
    int id;
public:
    std::string name;
    bool operator<(const Name& other) const { return name < other.name; }
};
namespace Reflection {
class Descriptor {
    void* vptr_pad;
public:
    const Name& name;
};
bool lessByName(const Descriptor* a, const Descriptor* b)
{
    return a->name < b->name;
}
}
}
