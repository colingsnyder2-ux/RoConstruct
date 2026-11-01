// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost {
template<class T> class shared_ptr { public: T* px; void* pn; T* get() const { return px; } };
}
namespace G3D { class Ray; class Vector3; }
namespace RBX {
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
class Instance {
public:
    virtual ~Instance();
    char pad[0x48];
    Instances* children;
    unsigned int numChildren() const;
    Instance* getChild(unsigned int i) const { return (*children)[i].get(); }
};
class PVInstance : public Instance {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual bool hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint);
};
class ModelInstance : public PVInstance {
public:
    virtual bool hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint);
};
bool ModelInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
{
    for (unsigned int i = 0; i < numChildren(); ++i) {
        PVInstance* pv = dynamic_cast<PVInstance*>(getChild(i));
        if (pv && pv->hitTest(worldRay, worldHitPoint))
            return true;
    }
    return false;
}
}
