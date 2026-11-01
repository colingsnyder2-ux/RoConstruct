// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct BrickColor { int number; };
namespace Reflection { class PropertyDescriptor; }
extern Reflection::PropertyDescriptor prop_Color;
class Instance
{
public:
	void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
};
class Holder : public Instance
{
	char pad[0x90];
	BrickColor color;
public:
	void setColor(BrickColor value);
};
void Holder::setColor(BrickColor value)
{
	if (color.number != value.number)
	{
		color = value;
		raisePropertyChanged(prop_Color);
	}
}
}
