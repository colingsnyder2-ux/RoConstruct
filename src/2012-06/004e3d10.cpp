// from server: 100% by Xemicl
// roc 2012-06 004e3d10  unit: Ogre::RbxMaterialAdapter  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e3d10
//
// 004e3d10  56                   push esi
// 004e3d11  57                   push edi
// 004e3d12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004e3d16  57                   push edi
// 004e3d17  8bf1                 mov esi, ecx
// 004e3d19  ff154426b200         call dword ptr [0xb22644]
// 004e3d1f  8a471c               mov al, byte ptr [edi + 0x1c]
// 004e3d22  88461c               mov byte ptr [esi + 0x1c], al
// 004e3d25  d94720               fld dword ptr [edi + 0x20]
// 004e3d28  d95e20               fstp dword ptr [esi + 0x20]
// 004e3d2b  8bc6                 mov eax, esi
// 004e3d2d  d94724               fld dword ptr [edi + 0x24]
// 004e3d30  d95e24               fstp dword ptr [esi + 0x24]
// 004e3d33  d94728               fld dword ptr [edi + 0x28]
// 004e3d36  d95e28               fstp dword ptr [esi + 0x28]
// 004e3d39  d9472c               fld dword ptr [edi + 0x2c]
// 004e3d3c  d95e2c               fstp dword ptr [esi + 0x2c]
// 004e3d3f  d94730               fld dword ptr [edi + 0x30]
// 004e3d42  d95e30               fstp dword ptr [esi + 0x30]
// 004e3d45  d94734               fld dword ptr [edi + 0x34]
// 004e3d48  d95e34               fstp dword ptr [esi + 0x34]
// 004e3d4b  d94738               fld dword ptr [edi + 0x38]
// 004e3d4e  d95e38               fstp dword ptr [esi + 0x38]
// 004e3d51  d9473c               fld dword ptr [edi + 0x3c]
// 004e3d54  d95e3c               fstp dword ptr [esi + 0x3c]
// 004e3d57  d94740               fld dword ptr [edi + 0x40]
// 004e3d5a  5f                   pop edi
// 004e3d5b  d95e40               fstp dword ptr [esi + 0x40]
// 004e3d5e  5e                   pop esi
// 004e3d5f  c20400               ret 4
// copied from an identical function in another client (function ??4Elem@@QAEAAU0@ABU0@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Vector3 {
    float x, y, z;
    Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; }
};
struct Vector4 { float x,y,z,w; Vector4& operator=(const Vector4& o){x=o.x;y=o.y;z=o.z;w=o.w;return *this;} };
struct Elem {
    std::string name;
    bool flag;
    float p; Vector4 a; Vector4 b;
};
void fill_elems(Elem* first, Elem* last, const Elem& val)
{
    for (; first != last; ++first)
        *first = val;
}