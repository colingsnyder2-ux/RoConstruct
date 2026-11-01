// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor { public: int x; }; }
class Primitive {
public:
	char pad[0xf1];
	bool flag;
	bool getCanCollide() const { return flag; }
	void setCanCollide(bool v);
};
class Instance {
public:
	void raisePropertyChanged(const Reflection::PropertyDescriptor& desc);
};
class PartInstance : public Instance {
public:
	char pad[0x118];
	Primitive* primitive;
	static Reflection::PropertyDescriptor prop_CanCollide;
	void setCanCollide(bool value);
};
void PartInstance::setCanCollide(bool value)
{
	if (value != primitive->getCanCollide())
	{
		primitive->setCanCollide(value);
		raisePropertyChanged(prop_CanCollide);
	}
}
}
