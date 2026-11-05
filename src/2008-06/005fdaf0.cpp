// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_2bda3cfb12250c8e.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <vector>
namespace RBX {
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
class IRenderable {
public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void render(void* a, void* b);
};
class Instance {
public:
    virtual ~Instance();
    char padding[0x104];
    boost::shared_ptr<Instances> children;
    size_t numChildren() const { return children ? children->size() : 0; }
    Instance* getChild(size_t i) const { return (*children)[i].get(); }
};
class ToolBase : public Instance {
public:
    char more[0x1b0 - 0x110];
};
class Tool : public ToolBase, public IRenderable {
public:
    void render(void* a, void* b);
};
void Tool::render(void* a, void* b)
{
    for (size_t i = 0; i < numChildren(); ++i) {
        if (IRenderable* r = dynamic_cast<IRenderable*>(getChild(i)))
            r->render(a, b);
    }
}
}
