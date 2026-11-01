// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor& desc);
};
extern const Reflection::PropertyDescriptor descA;
class Mesh : public Instance {
public:
    char pad[0xb8];
    float a, b, c;
    void setA(float v);
};
void Mesh::setA(float v)
{
    a = v;
    raisePropertyChanged(descA);
}
}
