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
extern const Reflection::PropertyDescriptor descC;
class Mesh : public Instance {
public:
    char pad[0xb8];
    float a, b, c;
    void setC(float v);
};
void Mesh::setC(float v)
{
    c = v;
    raisePropertyChanged(descC);
}
}
