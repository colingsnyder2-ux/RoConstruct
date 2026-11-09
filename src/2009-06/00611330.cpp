// from server: 97% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Adorn;
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
    void render3dAdornImpl(Adorn* adorn);
};
class IAdornable {
public:
    virtual bool shouldRender3dAdorn() const = 0;
    virtual void render3dAdorn(Adorn* adorn) = 0;
};
class Model : public PVInstance, public IAdornable {
public:
    static bool showModelSelection;
    virtual bool shouldRender3dAdorn() const
    {
        const Model* self = this;
        return (!dynamic_cast<const PVInstance*>(self->getParent()) || self->getTopPVInstance() == self->getParent())
            && showModelSelection;
    }
    virtual void render3dAdorn(Adorn* adorn);
};
void Model::render3dAdorn(Adorn* adorn)
{
    if (Model::shouldRender3dAdorn())
        render3dAdornImpl(adorn);
}
}
