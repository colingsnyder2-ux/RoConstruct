// from server: 100% by Xemicl
// roc 2012-06 004e4350  unit: Ogre::VGpuProgramParameters::?$SharedPtr  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e4350
//
// 004e4350  53                   push ebx
// 004e4351  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004e4355  55                   push ebp
// 004e4356  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 004e435a  3bdd                 cmp ebx, ebp
// 004e435c  745a                 je 0x4e43b8
// 004e435e  56                   push esi
// 004e435f  57                   push edi
// 004e4360  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004e4364  8d732c               lea esi, [ebx + 0x2c]
// 004e4367  57                   push edi
// 004e4368  8bcb                 mov ecx, ebx
// 004e436a  ff155826b200         call dword ptr [0xb22658]
// 004e4370  8a471c               mov al, byte ptr [edi + 0x1c]
// 004e4373  8846f0               mov byte ptr [esi - 0x10], al
// 004e4376  d94720               fld dword ptr [edi + 0x20]
// 004e4379  d95ef4               fstp dword ptr [esi - 0xc]
// 004e437c  83c344               add ebx, 0x44
// 004e437f  d94724               fld dword ptr [edi + 0x24]
// 004e4382  83c644               add esi, 0x44
// 004e4385  d95eb4               fstp dword ptr [esi - 0x4c]
// 004e4388  d94728               fld dword ptr [edi + 0x28]
// 004e438b  d95eb8               fstp dword ptr [esi - 0x48]
// 004e438e  d9472c               fld dword ptr [edi + 0x2c]
// 004e4391  d95ebc               fstp dword ptr [esi - 0x44]
// 004e4394  d94730               fld dword ptr [edi + 0x30]
// 004e4397  d95ec0               fstp dword ptr [esi - 0x40]
// 004e439a  d94734               fld dword ptr [edi + 0x34]
// 004e439d  d95ec4               fstp dword ptr [esi - 0x3c]
// 004e43a0  d94738               fld dword ptr [edi + 0x38]
// 004e43a3  d95ec8               fstp dword ptr [esi - 0x38]
// 004e43a6  d9473c               fld dword ptr [edi + 0x3c]
// 004e43a9  d95ecc               fstp dword ptr [esi - 0x34]
// 004e43ac  d94740               fld dword ptr [edi + 0x40]
// 004e43af  d95ed0               fstp dword ptr [esi - 0x30]
// 004e43b2  3bdd                 cmp ebx, ebp
// 004e43b4  75b1                 jne 0x4e4367
// 004e43b6  5f                   pop edi
// 004e43b7  5e                   pop esi
// 004e43b8  5d                   pop ebp
// 004e43b9  5b                   pop ebx
// 004e43ba  c3                   ret 
// copied from an identical function in another client (function ?fill_elems@@YAXPAUElem@@0ABU1@@Z)

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