// from server: 100% by EspClaude
// roc 2009-06 00664bc0  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00664bc0
//
// 00664bc0  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 00664bc3  8b01                 mov eax, dword ptr [ecx]
// 00664bc5  8b542404             mov edx, dword ptr [esp + 4]
// 00664bc9  8b4008               mov eax, dword ptr [eax + 8]
// 00664bcc  52                   push edx
// 00664bcd  ffd0                 call eax
// 00664bcf  8d4c2404             lea ecx, [esp + 4]
// 00664bd3  51                   push ecx
// 00664bd4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00664bd8  89442408             mov dword ptr [esp + 8], eax
// 00664bdc  e8fffeffff           call 0x664ae0
// 00664be1  c20800               ret 8
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
