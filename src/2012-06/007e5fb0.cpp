// from server: 100% by Xemicl
// roc 2012-06 007e5fb0  unit: RBX::VBlockMesh::?$FactoryProduct  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e5fb0
//
// 007e5fb0  8b442404             mov eax, dword ptr [esp + 4]
// 007e5fb4  3981a4000000         cmp dword ptr [ecx + 0xa4], eax
// 007e5fba  7413                 je 0x7e5fcf
// 007e5fbc  8981a4000000         mov dword ptr [ecx + 0xa4], eax
// 007e5fc2  c7442404f4e8e400     mov dword ptr [esp + 4], 0xe4e8f4
// 007e5fca  e9d1edc2ff           jmp 0x414da0
// 007e5fcf  c20400               ret 4
// copied from an identical function in another client (function ?setFace@FaceInstance@RBX@@QAEXW4NormalId@2@@Z)

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