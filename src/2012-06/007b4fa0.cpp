// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
namespace Reflection { struct PropertyDescriptor { int x; }; }

struct BrickColor {
    int number;
    bool operator!=(const BrickColor& o) const { return number != o.number; }
};

extern Reflection::PropertyDescriptor prop_BrickColor;
extern Reflection::PropertyDescriptor prop_Color;

struct PartInstance {
    char pad[0x2c0];
    BrickColor color;
    void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
    void setColor(BrickColor value);
};

void PartInstance::setColor(BrickColor value)
{
    if (value != color) {
        color = value;
        raisePropertyChanged(prop_BrickColor);
        raisePropertyChanged(prop_Color);
    }
}
}
