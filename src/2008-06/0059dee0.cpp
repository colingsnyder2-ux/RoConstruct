// from server: 100% by colin
// from server: 91% (rbxgs-dll PartInstance.cpp, wrong member offset)
// Manually recovered: PartInstance float setter with member at 0x328 and the
// raisePropertyChanged tail call. Standalone codegen analog.
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
struct PropertyDescriptor;

struct PartInstance
{
    char padding[0x328];
    float renderImportance;
    void setRenderImportance(float value);
    void raisePropertyChanged(const PropertyDescriptor&);
};

extern const PropertyDescriptor prop_RenderImportance;

void PartInstance::setRenderImportance(float value)
{
    if (value != renderImportance)
    {
        renderImportance = value;
        raisePropertyChanged(prop_RenderImportance);
    }
}
