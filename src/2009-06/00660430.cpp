// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor { public: int x; }; }
class Primitive {
public:
	char pad[0xf0];
	bool flag;
	bool getAnchored() const { return flag; }
	void setAnchored(bool v);
};
class Instance {
public:
	void raisePropertyChanged(const Reflection::PropertyDescriptor& desc);
};
class PartInstance : public Instance {
public:
	char pad[0x118];
	Primitive* primitive;
	static Reflection::PropertyDescriptor prop_Anchored;
	void setAnchored(bool value);
};
void PartInstance::setAnchored(bool value)
{
	if (value != primitive->getAnchored())
	{
		primitive->setAnchored(value);
		raisePropertyChanged(prop_Anchored);
	}
}
}
