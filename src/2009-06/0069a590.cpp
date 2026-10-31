// from server: 100% by EspClaude
// roc 2009-06 0069a590  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0069a590
//
// 0069a590  56                   push esi
// 0069a591  57                   push edi
// 0069a592  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0069a596  8bf1                 mov esi, ecx
// 0069a598  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0069a59b  57                   push edi
// 0069a59c  e8ff97daff           call 0x443da0
// 0069a5a1  84c0                 test al, al
// 0069a5a3  741f                 je 0x69a5c4
// 0069a5a5  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0069a5a8  8d542410             lea edx, [esp + 0x10]
// 0069a5ac  52                   push edx
// 0069a5ad  8b542410             mov edx, dword ptr [esp + 0x10]
// 0069a5b1  897c2414             mov dword ptr [esp + 0x14], edi
// 0069a5b5  8b01                 mov eax, dword ptr [ecx]
// 0069a5b7  8b400c               mov eax, dword ptr [eax + 0xc]
// 0069a5ba  52                   push edx
// 0069a5bb  ffd0                 call eax
// 0069a5bd  5f                   pop edi
// 0069a5be  b001                 mov al, 1
// 0069a5c0  5e                   pop esi
// 0069a5c1  c20800               ret 8
// 0069a5c4  5f                   pop edi
// 0069a5c5  32c0                 xor al, al
// 0069a5c7  5e                   pop esi
// 0069a5c8  c20800               ret 8
// copied from an identical function in another client (function ?setValue@Descriptor@ns_ROCX000000@@QAE_NPAXH@Z)

namespace ns_ROCX000000 {
struct Setter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* instance, const int& value);
};

struct EnumInfo
{
    bool accepts(int value);
};

struct Descriptor
{
    char gap[0x1c];
    Setter* setter;
    EnumInfo* info;

    bool setValue(void* instance, int value);
};

bool Descriptor::setValue(void* instance, int value)
{
    if (info->accepts(value)) {
        int converted = value;
        setter->set(instance, converted);
        return true;
    }
    return false;
}
}
