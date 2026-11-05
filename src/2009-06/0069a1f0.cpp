// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
enum NormalId { NORM_X };
namespace Reflection { class PropertyDescriptor { public: int x; }; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
    char pad[0xa4];
};
class FaceInstance : public Instance {
public:
    NormalId face;
    static Reflection::PropertyDescriptor prop_Face;
    void setFace(NormalId value);
};
void FaceInstance::setFace(NormalId value)
{
    if (face != value)
    {
        face = value;
        raisePropertyChanged(prop_Face);
    }
}
}
