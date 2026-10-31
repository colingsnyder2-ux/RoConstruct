// from server: 100% by EspClaude
// roc 2009-06 00443e20  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00443e20
//
// 00443e20  56                   push esi
// 00443e21  8bf1                 mov esi, ecx
// 00443e23  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00443e27  57                   push edi
// 00443e28  ff15bce48900         call dword ptr [0x89e4bc]
// 00443e2e  8b7e20               mov edi, dword ptr [esi + 0x20]
// 00443e31  8d4c2410             lea ecx, [esp + 0x10]
// 00443e35  51                   push ecx
// 00443e36  50                   push eax
// 00443e37  e8449b1800           call 0x5cd980
// 00443e3c  83c404               add esp, 4
// 00443e3f  50                   push eax
// 00443e40  8bcf                 mov ecx, edi
// 00443e42  e809a71a00           call 0x5ee550
// 00443e47  84c0                 test al, al
// 00443e49  7423                 je 0x443e6e
// 00443e4b  8b542410             mov edx, dword ptr [esp + 0x10]
// 00443e4f  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00443e52  89542410             mov dword ptr [esp + 0x10], edx
// 00443e56  8b01                 mov eax, dword ptr [ecx]
// 00443e58  8b400c               mov eax, dword ptr [eax + 0xc]
// 00443e5b  8d542410             lea edx, [esp + 0x10]
// 00443e5f  52                   push edx
// 00443e60  8b542410             mov edx, dword ptr [esp + 0x10]
// 00443e64  52                   push edx
// 00443e65  ffd0                 call eax
// 00443e67  5f                   pop edi
// 00443e68  b001                 mov al, 1
// 00443e6a  5e                   pop esi
// 00443e6b  c20800               ret 8
// 00443e6e  5f                   pop edi
// 00443e6f  32c0                 xor al, al
// 00443e71  5e                   pop esi
// 00443e72  c20800               ret 8
// copied from an identical function in another client (function ?set@Descriptor@ns_ROCX00003b@@QAE_NPAXABUString@2@@Z)

namespace ns_ROCX00003b {
struct String;
extern const char* (__thiscall *string_c_str)(const String*);

extern const void* __cdecl internName(const char*);

struct EnumMap {
    bool lookup(const void*, int*);
};

struct Property {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const int&);
};

struct Descriptor {
    char padding[0x1c];
    Property* property;
    EnumMap* enumMap;

    bool set(void*, const String&);
};

bool Descriptor::set(void* instance, const String& text)
{
    int result;
    const char* name = string_c_str(&text);
    EnumMap* map = enumMap;

    if (map->lookup(internName(name), &result)) {
        *(volatile int*)&result = result;
        property->set(instance, result);
        return true;
    }

    return false;
}
}
