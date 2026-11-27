// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
struct PropertyDescriptor { int x; };
struct BrickColor {
    int number;
    bool operator!=(const BrickColor& o) const { return number != o.number; }
};
extern PropertyDescriptor prop_BrickColor;
extern PropertyDescriptor prop_Color;
class PartInstance {
public:
    char pad[0x1a0];
    BrickColor color;
    void raisePropertyChanged(const PropertyDescriptor& d);
    void setColor(BrickColor value);
};
void PartInstance::setColor(BrickColor value)
{
    if (value != color)
    {
        color = value;
        raisePropertyChanged(prop_BrickColor);
        raisePropertyChanged(prop_Color);
    }
}
}