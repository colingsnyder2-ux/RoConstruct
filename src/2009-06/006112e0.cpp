// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x48 - 4];
    Instance* parent;
    char pad2[0x9c - 0x4c];
    Instance* getParent() const { return parent; }
};
class PVInstance : public Instance {
public:
    const Instance* getTopPVInstance() const;
};
class IAdornable {
public:
    virtual bool shouldRender3dAdorn() const = 0;
};
class Model : public PVInstance, public IAdornable {
public:
    static bool showModelSelection;
    virtual bool shouldRender3dAdorn() const;
};
bool Model::shouldRender3dAdorn() const
{
    const Model* self = this;
    return (!dynamic_cast<const PVInstance*>(self->getParent()) || self->getTopPVInstance() == self->getParent())
        && showModelSelection;
}
}
