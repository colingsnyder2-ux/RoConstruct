// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Instance { public: void raisePropertyChanged(const Reflection::PropertyDescriptor& d); };
extern const Reflection::PropertyDescriptor& prop_X;
extern Reflection::PropertyDescriptor desc_X;
class Humanoid : public Instance { char pad[0x1d4]; float x; public: void setX(const float& v); };
void Humanoid::setX(const float& v) { if (x != v) { x = v; raisePropertyChanged(desc_X); } }
}
