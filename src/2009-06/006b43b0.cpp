// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost {
template<class T> class shared_ptr { public: T* px; void* pn; T* get() const { return px; } };
}
namespace RBX {
class Instance;
class Primitive;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
class Instance {
public:
    virtual ~Instance();
    char pad[0x48];
    Instances* children;
    unsigned int numChildren() const;
    const Instance* getChild(unsigned int i) const { return (*children)[i].get(); }
};
class PartInstance : public Instance {
public:
    char pad2[0x118 - 0x50];
    Primitive* primitive;
    const Primitive* getConstPrimitive() const { return primitive; }
};
class DragUtilities {
public:
    static void getPrimitivesConst(const Instance* instance, std::vector<const Primitive*>& primitives);
};
void DragUtilities::getPrimitivesConst(const Instance* instance, std::vector<const Primitive*>& primitives)
{
    if (const PartInstance* part = dynamic_cast<const PartInstance*>(instance)) {
        primitives.push_back(part->getConstPrimitive());
    }
    for (unsigned int i = 0; i < instance->numChildren(); ++i) {
        getPrimitivesConst(instance->getChild(i), primitives);
    }
}
}
