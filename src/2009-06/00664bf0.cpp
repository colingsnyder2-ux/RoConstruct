// from server: 100% by EspClaude
// roc 2009-06 00664bf0  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00664bf0
//
// 00664bf0  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 00664bf3  8b01                 mov eax, dword ptr [ecx]
// 00664bf5  8b542404             mov edx, dword ptr [esp + 4]
// 00664bf9  8b4008               mov eax, dword ptr [eax + 8]
// 00664bfc  52                   push edx
// 00664bfd  ffd0                 call eax
// 00664bff  8d4c2404             lea ecx, [esp + 4]
// 00664c03  51                   push ecx
// 00664c04  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00664c08  89442408             mov dword ptr [esp + 8], eax
// 00664c0c  e83fffffff           call 0x664b50
// 00664c11  c20800               ret 8
// copied from an identical function in another client (function ?read@Descriptor@ns_ROCX00000b@@QAEXHPAUResult@2@@Z)

namespace ns_ROCX00000b {
struct Access {
    virtual void slot0();
    virtual void slot1();
    virtual int get(int);
};

struct Result {
    void assign(const int*);
};

struct Descriptor {
    unsigned char padding[28];
    Access* access;

    void read(int, Result*);
};

void Descriptor::read(int value, Result* result)
{
    value = access->get(value);
    result->assign(&value);
}
}
