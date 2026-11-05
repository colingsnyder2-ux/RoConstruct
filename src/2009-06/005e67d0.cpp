// from server: 100% by EspClaude
// roc 2009-06 005e67d0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e67d0
//
// 005e67d0  51                   push ecx
// 005e67d1  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005e67d4  8b01                 mov eax, dword ptr [ecx]
// 005e67d6  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005e67da  8b4008               mov eax, dword ptr [eax + 8]
// 005e67dd  56                   push esi
// 005e67de  52                   push edx
// 005e67df  c744240800000000     mov dword ptr [esp + 8], 0
// 005e67e7  ffd0                 call eax
// 005e67e9  d95c2410             fstp dword ptr [esp + 0x10]
// 005e67ed  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005e67f1  8d4c2410             lea ecx, [esp + 0x10]
// 005e67f5  51                   push ecx
// 005e67f6  56                   push esi
// 005e67f7  e8944e0600           call 0x64b690
// 005e67fc  83c408               add esp, 8
// 005e67ff  8bc6                 mov eax, esi
// 005e6801  5e                   pop esi
// 005e6802  59                   pop ecx
// 005e6803  c20800               ret 8
// copied from an identical function in another client (function ?getString@Descriptor@ns_ROCX000003@@QAEPAUString@2@PAU32@PAX@Z)

namespace ns_ROCX000003 {
struct String;
String* __cdecl formatFloat(String* result, const float& value);

struct Getter;

struct GetterTable
{
    void* slots[2];
    float (__thiscall *get)(Getter*, void*);
};

struct Getter
{
    GetterTable* table;
};

struct Descriptor
{
    char padding[24];
    Getter* getter;

    String* getString(String* result, void* object);
};

String* Descriptor::getString(String* result, void* object)
{
    volatile int state = 0;
    reinterpret_cast<float&>(object) = getter->table->get(getter, object);
    formatFloat(result, reinterpret_cast<const float&>(object));
    return result;
}
}
