// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0059e3d0  unit: VCRenderSettings::?$EnumPropDescriptor  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059e3d0
//
// 0059e3d0  56                   push esi
// 0059e3d1  8bf1                 mov esi, ecx
// 0059e3d3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0059e3d7  d901                 fld dword ptr [ecx]
// 0059e3d9  83ec0c               sub esp, 0xc
// 0059e3dc  8bc4                 mov eax, esp
// 0059e3de  d918                 fstp dword ptr [eax]
// 0059e3e0  d94104               fld dword ptr [ecx + 4]
// 0059e3e3  d95804               fstp dword ptr [eax + 4]
// 0059e3e6  d94108               fld dword ptr [ecx + 8]
// 0059e3e9  d95808               fstp dword ptr [eax + 8]
// 0059e3ec  8d442414             lea eax, [esp + 0x14]
// 0059e3f0  50                   push eax
// 0059e3f1  e8ea7e0100           call 0x5b62e0
// 0059e3f6  8b00                 mov eax, dword ptr [eax]
// 0059e3f8  83c410               add esp, 0x10
// 0059e3fb  3b86e4010000         cmp eax, dword ptr [esi + 0x1e4]
// 0059e401  741e                 je 0x59e421
// 0059e403  68d0629700           push 0x9762d0
// 0059e408  8bce                 mov ecx, esi
// 0059e40a  8986e4010000         mov dword ptr [esi + 0x1e4], eax
// 0059e410  e8ebf6e6ff           call 0x40db00
// 0059e415  680c619700           push 0x97610c
// 0059e41a  8bce                 mov ecx, esi
// 0059e41c  e8dff6e6ff           call 0x40db00
// 0059e421  5e                   pop esi
// 0059e422  c20400               ret 4

struct Vector3 {
    float x, y, z;
    Vector3(const Vector3&);
};

inline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

struct PackedValue {
    unsigned int value;
    PackedValue();
};

extern PackedValue __cdecl convert(Vector3);
extern unsigned char propertyA;
extern unsigned char propertyB;

struct Settings {
    unsigned char padding[0x1e4];
    unsigned int value;

    void notify(void*);
    void setValue(const Vector3&);
};

void Settings::setValue(const Vector3& v)
{
    unsigned int converted = convert(v).value;
    if (converted != value) {
        value = converted;
        notify(&propertyA);
        notify(&propertyB);
    }
}
