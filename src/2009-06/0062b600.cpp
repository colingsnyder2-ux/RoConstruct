// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    T* px; void* pn;
    T* get() const { return px; }
};
}
namespace RBX {
class Instance { public: virtual ~Instance(); };
class IRenderable { public: virtual ~IRenderable(); };
class IRenderableBucket {
public:
    void onRemoving(IRenderable* r);
};
class RootInstance : public Instance {
public:
    char pad[0x1ac];
    virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance);
};
class Workspace : public RootInstance {
public:
    IRenderableBucket bucket;
    virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance);
};
void Workspace::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
{
    if (IRenderable* r = dynamic_cast<IRenderable*>(instance.get()))
        bucket.onRemoving(r);
    RootInstance::onDescendentRemoving(instance);
}
}
