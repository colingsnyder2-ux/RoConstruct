// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <algorithm>
namespace RBX { namespace Reflection {
class Type {
public:
    virtual ~Type() {}
    int name;
    int data[3];
};
class EnumDescriptor : public Type {
public:
    virtual ~EnumDescriptor();
    static std::vector<const EnumDescriptor*>& allEnums();
    std::vector<int> values;
};
extern int enumCount;
EnumDescriptor::~EnumDescriptor()
{
    allEnums().erase(std::find(allEnums().begin(), allEnums().end(), this));
    --enumCount;
}
}}
