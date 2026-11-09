// from server: 100% by EspClaude
// roc 2009-06 00668080  unit: RBX::Humanoid  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00668080
//
// 00668080  56                   push esi
// 00668081  8b742408             mov esi, dword ptr [esp + 8]
// 00668085  6a00                 push 0
// 00668087  6850f99d00           push 0x9df950
// 0066808c  6840be9d00           push 0x9dbe40
// 00668091  6a00                 push 0
// 00668093  56                   push esi
// 00668094  e8e11b0b00           call 0x719c7a
// 00668099  83c414               add esp, 0x14
// 0066809c  85c0                 test eax, eax
// 0066809e  740f                 je 0x6680af
// 006680a0  d9e8                 fld1 
// 006680a2  51                   push ecx
// 006680a3  8bc8                 mov ecx, eax
// 006680a5  d91c24               fstp dword ptr [esp]
// 006680a8  e86381ffff           call 0x660210
// 006680ad  5e                   pop esi
// 006680ae  c3                   ret 
// 006680af  6a00                 push 0
// 006680b1  6888619e00           push 0x9e6188
// 006680b6  6840be9d00           push 0x9dbe40
// 006680bb  6a00                 push 0
// 006680bd  56                   push esi
// 006680be  e8b71b0b00           call 0x719c7a
// 006680c3  83c414               add esp, 0x14
// 006680c6  85c0                 test eax, eax
// 006680c8  740c                 je 0x6680d6
// 006680ca  6880806600           push 0x668080
// 006680cf  8bc8                 mov ecx, eax
// 006680d1  e8ca41dfff           call 0x45c2a0
// 006680d6  5e                   pop esi
// 006680d7  c3                   ret 
// copied from an identical function in another client (function ?apply@ns_ROCX000043@@YAXPAUInstance@1@@Z)

namespace ns_ROCX000043 {
struct Instance {};

struct Part {
    void setValue(float value);
};

struct Model {
    void visit(void (__cdecl *callback)(Instance*));
};

extern const char instanceType;
extern const char partType;
extern const char modelType;

extern "C" void* __cdecl castObject(
    void* object, int offset, const void* sourceType,
    const void* targetType, int isReference);

void __cdecl apply(Instance* object)
{
    Part* part = static_cast<Part*>(
        castObject(object, 0, &instanceType, &partType, 0));

    if (part) {
        part->setValue(1.0f);
        return;
    }

    Model* model = static_cast<Model*>(
        castObject(object, 0, &instanceType, &modelType, 0));

    if (model)
        model->visit(apply);
}
}
