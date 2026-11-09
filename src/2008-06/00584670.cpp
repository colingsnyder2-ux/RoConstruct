// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    T* px;
    void* pn;
    T* get() const { return px; }
    void reset();
};
}
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x1a0 - 4];
};
class PVInstance : public Instance {
public:
    void onDescendentAdded(Instance*);
    void onDescendentRemoving(const boost::shared_ptr<Instance>&);
};
class IRenderable {
public:
    virtual void render();
    void shouldRenderSetDirty();
};
class PartInstance;
template<class T, class C> class ComputeProp {
public:
    mutable T val;
    mutable bool dirty;
    C* object;
    char getFunc[16];
    bool setDirty() const { dirty = true; return dirty; }
};
struct Extents { float low[3]; float high[3]; };
class ModelInstance : public PVInstance, public IRenderable {
    char pad0[0x1e0 - 0x1a4];
    mutable PartInstance* primaryPart;
    boost::shared_ptr<PartInstance> candidatePrimaryPart;
    char pad1[0x208 - 0x1ec];
    ComputeProp<float, ModelInstance> FlagHeight;
    char pad2[4];
    ComputeProp<Extents, ModelInstance> LocalGridExtents;
    ComputeProp<Extents, ModelInstance> WorldGridExtents;
    void updatePrimaryPart(PartInstance*) const;
protected:
    virtual void onDescendentAdded(Instance*);
    virtual void onDescendentRemoving(const boost::shared_ptr<Instance>&);
};
void ModelInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
{
    if (primaryPart == (PartInstance*)instance.get())
        primaryPart = 0;
    if (candidatePrimaryPart.get() == (PartInstance*)instance.get())
        candidatePrimaryPart.reset();
    LocalGridExtents.setDirty();
    WorldGridExtents.setDirty();
    FlagHeight.setDirty();
    shouldRenderSetDirty();
    PVInstance::onDescendentRemoving(instance);
}
}
