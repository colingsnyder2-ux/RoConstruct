// from server: 100% by EspClaude
// roc 2009-06 00663860  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00663860
//
// 00663860  56                   push esi
// 00663861  57                   push edi
// 00663862  6800f75e00           push 0x5ef700
// 00663867  68eca4a400           push 0xa4a4ec
// 0066386c  8bf1                 mov esi, ecx
// 0066386e  e89dded9ff           call 0x401710
// 00663873  83c408               add esp, 8
// 00663876  e825bef8ff           call 0x5ef6a0
// 0066387b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0066387f  57                   push edi
// 00663880  8bc8                 mov ecx, eax
// 00663882  e81905deff           call 0x443da0
// 00663887  84c0                 test al, al
// 00663889  741f                 je 0x6638aa
// 0066388b  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0066388e  8d542410             lea edx, [esp + 0x10]
// 00663892  52                   push edx
// 00663893  8b542410             mov edx, dword ptr [esp + 0x10]
// 00663897  897c2414             mov dword ptr [esp + 0x14], edi
// 0066389b  8b01                 mov eax, dword ptr [ecx]
// 0066389d  8b400c               mov eax, dword ptr [eax + 0xc]
// 006638a0  52                   push edx
// 006638a1  ffd0                 call eax
// 006638a3  5f                   pop edi
// 006638a4  b001                 mov al, 1
// 006638a6  5e                   pop esi
// 006638a7  c20800               ret 8
// 006638aa  5f                   pop edi
// 006638ab  32c0                 xor al, al
// 006638ad  5e                   pop esi
// 006638ae  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000014@@QAE_NPAXH@Z)

namespace ns_ROCX000014 {
extern char descriptorData;
extern void __cdecl initializeDescriptor();
extern void __cdecl registerDescriptor(void (__cdecl *)(), void *);

struct EnumDescriptor {
    bool contains(int value);
};

extern EnumDescriptor * __cdecl getEnumDescriptor();

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void *object, const int *value);
};

struct S {
    char padding[28];
    Setter *setter;
    bool f(void *object, int value);
};

bool S::f(void *object, int value)
{
    registerDescriptor(initializeDescriptor, &descriptorData);
    EnumDescriptor *descriptor = getEnumDescriptor();
    if (descriptor->contains(value)) {
        int converted = value;
        setter->set(object, &converted);
        return true;
    }
    return false;
}
}
