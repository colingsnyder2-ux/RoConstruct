// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost { template<class T> class shared_ptr { public: T* px; void* pn; T* get() const { return px; } }; }
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x48];
    typedef std::vector<boost::shared_ptr<Instance> > ChildList;
    ChildList* children; // 0x4c
    unsigned int numChildren() const { return children ? children->size() : 0; }
    Instance* getChild(unsigned int i) const { return (*children)[i].get(); }
    char pad2[0x9c - 0x50];
};
class IRenderable {
public:
    virtual void r0(int);
    virtual void r1(int);
    virtual void r2(int);
    virtual void r3(int);
    virtual void render(int a, int b);
};
class RenderGroup : public Instance, public IRenderable {
public:
    virtual void render(int a, int b);
};
void RenderGroup::render(int a, int b)
{
    for (unsigned int i = 0; i < numChildren(); ++i) {
        IRenderable* r = dynamic_cast<IRenderable*>(getChild(i));
        if (r)
            r->render(a, b);
    }
}
}
