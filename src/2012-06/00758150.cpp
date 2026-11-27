// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor { public: PropertyDescriptor(); int x; }; }
class Instance { public: void raisePropertyChanged(const Reflection::PropertyDescriptor&); };
class Primitive {
public:
    char pad[0x115];
    bool dragging;
    void setDragging(bool value);
    bool getDragging() const { return dragging; }
};
class PartInstance : public Instance {
public:
    char pad[0x198];
    Primitive* primitive;
    bool getDragging() const { return primitive->getDragging(); }
    void setDragging(bool value);
};
extern Reflection::PropertyDescriptor prop_Dragging;
void PartInstance::setDragging(bool value)
{
    if (value != getDragging())
    {
        primitive->setDragging(value);
        raisePropertyChanged(prop_Dragging);
    }
}
}
