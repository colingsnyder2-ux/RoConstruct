// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00584c90  unit: G3D::VCoordinateFrame::?$TypedPropertyDescriptor  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00584c90
//
// 00584c90  64a100000000         mov eax, dword ptr fs:[0]
// 00584c96  6aff                 push -1
// 00584c98  68a8257d00           push 0x7d25a8
// 00584c9d  50                   push eax
// 00584c9e  64892500000000       mov dword ptr fs:[0], esp
// 00584ca5  83ec08               sub esp, 8
// 00584ca8  56                   push esi
// 00584ca9  8bf1                 mov esi, ecx
// 00584cab  8b06                 mov eax, dword ptr [esi]
// 00584cad  8b4008               mov eax, dword ptr [eax + 8]
// 00584cb0  57                   push edi
// 00584cb1  50                   push eax
// 00584cb2  b980639400           mov ecx, 0x946380
// 00584cb7  ff1578288000         call dword ptr [0x802878]
// 00584cbd  84c0                 test al, al
// 00584cbf  7441                 je 0x584d02
// 00584cc1  83c604               add esi, 4
// 00584cc4  56                   push esi
// 00584cc5  e8c6f8ffff           call 0x584590
// 00584cca  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00584cce  83c404               add esp, 4
// 00584cd1  8bf0                 mov esi, eax
// 00584cd3  56                   push esi
// 00584cd4  8bcf                 mov ecx, edi
// 00584cd6  e845e5f8ff           call 0x513220
// 00584cdb  d94624               fld dword ptr [esi + 0x24]
// 00584cde  d95f24               fstp dword ptr [edi + 0x24]
// 00584ce1  8bc7                 mov eax, edi
// 00584ce3  d94628               fld dword ptr [esi + 0x28]
// 00584ce6  d95f28               fstp dword ptr [edi + 0x28]
// 00584ce9  d9462c               fld dword ptr [esi + 0x2c]
// 00584cec  d95f2c               fstp dword ptr [edi + 0x2c]
// 00584cef  5f                   pop edi
// 00584cf0  5e                   pop esi
// 00584cf1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00584cf5  64890d00000000       mov dword ptr fs:[0], ecx
// 00584cfc  83c414               add esp, 0x14
// 00584cff  c20400               ret 4
// 00584d02  8b0e                 mov ecx, dword ptr [esi]
// 00584d04  894c2408             mov dword ptr [esp + 8], ecx
// 00584d08  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584d0b  85c9                 test ecx, ecx
// 00584d0d  7409                 je 0x584d18
// 00584d0f  8b11                 mov edx, dword ptr [ecx]
// 00584d11  8b4208               mov eax, dword ptr [edx + 8]
// 00584d14  ffd0                 call eax
// 00584d16  eb02                 jmp 0x584d1a
// 00584d18  33c0                 xor eax, eax
// 00584d1a  8944240c             mov dword ptr [esp + 0xc], eax
// 00584d1e  8d4c2408             lea ecx, [esp + 8]
// 00584d22  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00584d2a  e881a2feff           call 0x56efb0
// 00584d2f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00584d33  8bf0                 mov esi, eax
// 00584d35  56                   push esi
// 00584d36  8bcf                 mov ecx, edi
// 00584d38  e8e3e4f8ff           call 0x513220
// 00584d3d  d94624               fld dword ptr [esi + 0x24]
// 00584d40  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00584d44  d95f24               fstp dword ptr [edi + 0x24]
// 00584d47  d94628               fld dword ptr [esi + 0x28]
// 00584d4a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00584d52  d95f28               fstp dword ptr [edi + 0x28]
// 00584d55  d9462c               fld dword ptr [esi + 0x2c]
// 00584d58  d95f2c               fstp dword ptr [edi + 0x2c]
// 00584d5b  85c9                 test ecx, ecx
// 00584d5d  7408                 je 0x584d67
// 00584d5f  8b11                 mov edx, dword ptr [ecx]
// 00584d61  8b02                 mov eax, dword ptr [edx]
// 00584d63  6a01                 push 1
// 00584d65  ffd0                 call eax
// 00584d67  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00584d6b  8bc7                 mov eax, edi
// 00584d6d  5f                   pop edi
// 00584d6e  5e                   pop esi
// 00584d6f  64890d00000000       mov dword ptr fs:[0], ecx
// 00584d76  83c414               add esp, 0x14
// 00584d79  c20400               ret 4

class type_info;

typedef bool (__thiscall *TypeInfoEqual)(const type_info*, const type_info&);
extern TypeInfoEqual typeInfoEqual;
extern type_info coordinateFrameType;

struct Descriptor {
    unsigned char reserved[8];
    const type_info* type;
};

struct Holder {
    virtual ~Holder();
    virtual void unused();
    virtual Holder* clone() const;

    static Holder* copy(const Holder*);
};

inline Holder* Holder::copy(const Holder* p)
{
    if (p)
        return p->clone();
    return 0;
}

struct Matrix {
    float elements[9];
    Matrix(const Matrix&);
};

struct Frame {
    Matrix rotation;
    float x, y, z;
};

struct Value {
    Descriptor* descriptor;
    Holder* object;

    Value(const Value&);
    ~Value();
    const Frame& convert() const;
    Frame get() const;
};

extern const Frame& __cdecl unboxFrame(Holder* const*);

inline Value::Value(const Value& source)
    : descriptor(source.descriptor)
{
    object = Holder::copy(source.object);
}

inline Value::~Value()
{
    if (object)
        delete object;
}

Frame Value::get() const
{
    const type_info* type = descriptor->type;
    if (typeInfoEqual(&coordinateFrameType, *type))
        return unboxFrame(&object);

    Value temporary(*this);
    return temporary.convert();
}
