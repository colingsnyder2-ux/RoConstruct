// from server: 100% by EspClaude
// roc 2009-06 005e6750  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e6750
//
// 005e6750  51                   push ecx
// 005e6751  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005e6754  8b01                 mov eax, dword ptr [ecx]
// 005e6756  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005e675a  8b4008               mov eax, dword ptr [eax + 8]
// 005e675d  56                   push esi
// 005e675e  52                   push edx
// 005e675f  c744240800000000     mov dword ptr [esp + 8], 0
// 005e6767  ffd0                 call eax
// 005e6769  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005e676d  8d4c2410             lea ecx, [esp + 0x10]
// 005e6771  51                   push ecx
// 005e6772  56                   push esi
// 005e6773  88442418             mov byte ptr [esp + 0x18], al
// 005e6777  e8544b0600           call 0x64b2d0
// 005e677c  83c408               add esp, 8
// 005e677f  8bc6                 mov eax, esi
// 005e6781  5e                   pop esi
// 005e6782  59                   pop ecx
// 005e6783  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000001@@QAE?AUResult@2@PAX@Z)

namespace ns_ROCX000001 {
struct Result {
    char storage[28];
    Result(const Result&);
    ~Result();
};

Result __cdecl convert(const bool& value);

struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual bool get(void* instance);
};

struct S {
    char padding[24];
    Getter* getter;

    Result f(void* instance);
};

Result S::f(void* instance)
{
    return convert(getter->get(instance));
}
}
