// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace RBX {
class Instance;
struct SP { Instance* p; void* c; };
struct Children {
    std::vector<SP> v;
};
class Instance {
public:
    virtual ~Instance();
    char pad[0xcc];
    Children* children;
    char pad2[0xc4];
    size_t numChildren() const { return children ? children->v.size() : 0; }
    Instance* getChild(size_t i) const { return children->v[i].p; }
};
class ICameraSubject {
public:
    virtual void getCameraSubject();
    virtual void onCameraNear(float);
};
class ModelInstance : public Instance, public ICameraSubject {
public:
    virtual void onCameraNear(float);
};
void ModelInstance::onCameraNear(float f)
{
    for (size_t i = 0; i < numChildren(); ++i) {
        ICameraSubject* s = dynamic_cast<ICameraSubject*>(getChild(i));
        if (s)
            s->onCameraNear(f);
    }
}
}
