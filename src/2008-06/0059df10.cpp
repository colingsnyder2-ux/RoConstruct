// from server: 100% by colin
// from server: 95% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast

namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor);
};
class PartInstance : public Instance {
    char padding[0x1ec];
    float renderImportance;
public:
    static const Reflection::PropertyDescriptor prop_RenderImportance;
    float getRenderImportance() const { return renderImportance; }
    void setRenderImportance(float value);
};
void PartInstance::setRenderImportance(float value)
{
    if (value != getRenderImportance())
    {
        renderImportance = value;
        raisePropertyChanged(prop_RenderImportance);
    }
}
}
