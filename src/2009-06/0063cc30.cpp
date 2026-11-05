// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace RBX {
template<class T> struct shared_ptr { T* px; void* pn; T* get() const { return px; } };
class Instance;
struct ChildList { std::vector<shared_ptr<Instance> > v; };
class Instance {
public:
    virtual ~Instance();
    char pad[0x104];
    ChildList* children;
    unsigned int numChildren() const { return children ? children->v.size() : 0; }
    Instance* getChild(unsigned int i) const { return (*children).v[i].get(); }
    char pad2[0x5c];
};
class CameraSubject {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void onCameraNear(float distance) = 0;
};
class ModelInstance : public Instance, public CameraSubject {
public:
    virtual void onCameraNear(float distance);
};
void ModelInstance::onCameraNear(float distance)
{
    for (unsigned int i = 0; i < numChildren(); i++) {
        CameraSubject* subject = dynamic_cast<CameraSubject*>(getChild(i));
        if (subject != 0) {
            subject->onCameraNear(distance);
        }
    }
}
}
