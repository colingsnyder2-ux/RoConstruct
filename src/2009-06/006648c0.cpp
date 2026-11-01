// from server: 100% by EspClaude
// roc 2009-06 006648c0  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006648c0
//
// 006648c0  56                   push esi
// 006648c1  57                   push edi
// 006648c2  6830f25e00           push 0x5ef230
// 006648c7  68c0a4a400           push 0xa4a4c0
// 006648cc  8bf1                 mov esi, ecx
// 006648ce  e83dced9ff           call 0x401710
// 006648d3  83c408               add esp, 8
// 006648d6  e8f5a8f8ff           call 0x5ef1d0
// 006648db  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006648df  57                   push edi
// 006648e0  8bc8                 mov ecx, eax
// 006648e2  e8b9f4ddff           call 0x443da0
// 006648e7  84c0                 test al, al
// 006648e9  741f                 je 0x66490a
// 006648eb  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 006648ee  8d542410             lea edx, [esp + 0x10]
// 006648f2  52                   push edx
// 006648f3  8b542410             mov edx, dword ptr [esp + 0x10]
// 006648f7  897c2414             mov dword ptr [esp + 0x14], edi
// 006648fb  8b01                 mov eax, dword ptr [ecx]
// 006648fd  8b400c               mov eax, dword ptr [eax + 0xc]
// 00664900  52                   push edx
// 00664901  ffd0                 call eax
// 00664903  5f                   pop edi
// 00664904  b001                 mov al, 1
// 00664906  5e                   pop esi
// 00664907  c20800               ret 8
// 0066490a  5f                   pop edi
// 0066490b  32c0                 xor al, al
// 0066490d  5e                   pop esi
// 0066490e  c20800               ret 8
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
