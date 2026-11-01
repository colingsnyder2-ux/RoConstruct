// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <algorithm>

namespace RBX {
class Instance
{
public:
    virtual ~Instance();
    Instance* getParent() const { return parent; }
private:
    char pad[0x44];
    Instance* parent;
};

namespace Reflection { namespace Metadata {
class Class : public Instance
{
    char pad[0xb0 - 0x4c];
    int browsable;
public:
    int isBrowsable() const;
};

int Class::isBrowsable() const
{
    if (browsable == -1)
    {
        if (dynamic_cast<Class*>(getParent()) && dynamic_cast<Class*>(getParent())->isBrowsable())
            return 1;
        return 0;
    }
    return std::max(browsable, 0);
}
}}
}
