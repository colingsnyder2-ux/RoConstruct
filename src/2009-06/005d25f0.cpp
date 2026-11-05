// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost {
template<class T> class shared_ptr {
public:
    T* px; void* pn;
    T* operator->() const { return px; }
};
}
namespace RBX {
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
struct ChildrenHolder { int header; Instances v; };
class Instance {
public:
    char pad[0x48];
    Instance* parent;
    Instances* children;
    int numChildren() const;
    void setParent(Instance* newParent);
    Instance* getParent() const { return parent; }
    void promoteChildren();
};
void Instance::promoteChildren()
{
    while (numChildren())
        (*children)[0]->setParent(getParent());
}
}
