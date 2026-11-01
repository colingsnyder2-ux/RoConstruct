// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
namespace Reflection { class PropertyDescriptor { public: int x; }; }
class Instance {
public:
	void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
};
extern Reflection::PropertyDescriptor prop_Value;
class Humanoid : public Instance {
public:
	char pad[0x1d8];
	float value;
	void setValue(float v);
};
void Humanoid::setValue(float v) { if (v != value) { value = v; raisePropertyChanged(prop_Value); } }
}
