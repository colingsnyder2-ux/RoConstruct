// from server: 100% by EspClaude
// roc 2009-06 00467dc0  unit: CSettingsPropGrid  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00467dc0
//
// 00467dc0  56                   push esi
// 00467dc1  57                   push edi
// 00467dc2  8bf1                 mov esi, ecx
// 00467dc4  e82727faff           call 0x40a4f0
// 00467dc9  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00467dcd  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00467dd0  50                   push eax
// 00467dd1  e8aa0b1900           call 0x5f8980
// 00467dd6  84c0                 test al, al
// 00467dd8  740d                 je 0x467de7
// 00467dda  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00467dde  57                   push edi
// 00467ddf  50                   push eax
// 00467de0  8bce                 mov ecx, esi
// 00467de2  e89936fdff           call 0x43b480
// 00467de7  5f                   pop edi
// 00467de8  5e                   pop esi
// 00467de9  c20800               ret 8
// copied from an identical function in another client (function ?f@CSettingsPropGrid@ns_ROCX000004@@QAEXHPAUItem@2@@Z)

namespace ns_ROCX000004 {
struct Descriptor {
    bool __thiscall differs(const Descriptor&) const;
};

const Descriptor& __cdecl getDescriptor();

struct Item {
    unsigned char padding[12];
    Descriptor* descriptor;
};

struct CSettingsPropGrid {
    void __thiscall apply(int, Item*);
    void __thiscall f(int, Item*);
};

void CSettingsPropGrid::f(int value, Item* item)
{
    if (item->descriptor->differs(getDescriptor()))
        apply(value, item);
}
}
