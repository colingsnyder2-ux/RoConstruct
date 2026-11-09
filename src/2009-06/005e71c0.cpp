// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056f6e0  unit: G3D::VColor3::?$TypedPropertyDescriptor  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056f6e0
//
// 0056f6e0  8b542404             mov edx, dword ptr [esp + 4]
// 0056f6e4  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0056f6e7  8b01                 mov eax, dword ptr [ecx]
// 0056f6e9  8b4008               mov eax, dword ptr [eax + 8]
// 0056f6ec  83ec0c               sub esp, 0xc
// 0056f6ef  56                   push esi
// 0056f6f0  57                   push edi
// 0056f6f1  52                   push edx
// 0056f6f2  8d54240c             lea edx, [esp + 0xc]
// 0056f6f6  52                   push edx
// 0056f6f7  ffd0                 call eax
// 0056f6f9  8d4c2408             lea ecx, [esp + 8]
// 0056f6fd  51                   push ecx
// 0056f6fe  8d4c241c             lea ecx, [esp + 0x1c]
// 0056f702  e8990ffaff           call 0x5106a0
// 0056f707  0fb6742418           movzx esi, byte ptr [esp + 0x18]
// 0056f70c  0fb6542419           movzx edx, byte ptr [esp + 0x19]
// 0056f711  0fb644241a           movzx eax, byte ptr [esp + 0x1a]
// 0056f716  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0056f71a  81c600ff0000         add esi, 0xff00
// 0056f720  c1e608               shl esi, 8
// 0056f723  03f2                 add esi, edx
// 0056f725  83c710               add edi, 0x10
// 0056f728  c1e608               shl esi, 8
// 0056f72b  8bcf                 mov ecx, edi
// 0056f72d  03f0                 add esi, eax
// 0056f72f  e89ccb0000           call 0x57c2d0
// 0056f734  897708               mov dword ptr [edi + 8], esi
// 0056f737  c7470406000000       mov dword ptr [edi + 4], 6
// 0056f73e  5f                   pop edi
// 0056f73f  5e                   pop esi
// 0056f740  83c40c               add esp, 0xc
// 0056f743  c20800               ret 8

struct Color3 {
    float r, g, b;
};

struct Color3uint8 {
    unsigned char r, g, b;
    Color3uint8(const Color3&);
};

struct Accessor {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual Color3 get(void*) = 0;
};

struct Value {
    unsigned int reserved;
    unsigned int type;
    unsigned int data;
    void clear();
};

struct Output {
    unsigned char padding[16];
    Value value;
};

struct Descriptor {
    unsigned char padding[24];
    Accessor* accessor;
    void read(void*, Output*);
};

void Descriptor::read(void* object, Output* output)
{
    Color3 color = accessor->get(object);
    Color3uint8 bytes(color);
    unsigned int packed =
        (((bytes.r + 0xff00u) << 8) + bytes.g) * 256u + bytes.b;
    Value* value = &output->value;
    value->clear();
    value->data = packed;
    value->type = 6;
}
