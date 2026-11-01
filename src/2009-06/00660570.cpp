// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
extern Reflection::PropertyDescriptor prop_Flag;
class Instance
{
public:
	void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
};
class Holder : public Instance
{
	char pad[0x130];
	bool flag;
public:
	void setFlag(bool value);
};
void Holder::setFlag(bool value)
{
	if (value != flag)
	{
		flag = value;
		raisePropertyChanged(prop_Flag);
	}
}
}
