// from server: 100% by EspClaude
// roc 2009-06 005c9350  unit: seg_005c0000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c9350
//
// 005c9350  6aff                 push -1
// 005c9352  68eb218600           push 0x8621eb
// 005c9357  64a100000000         mov eax, dword ptr fs:[0]
// 005c935d  50                   push eax
// 005c935e  64892500000000       mov dword ptr fs:[0], esp
// 005c9365  81ec88000000         sub esp, 0x88
// 005c936b  56                   push esi
// 005c936c  8d4c2408             lea ecx, [esp + 8]
// 005c9370  c744240400000000     mov dword ptr [esp + 4], 0
// 005c9378  e893c1f9ff           call 0x565510
// 005c937d  8bb4249c000000       mov esi, dword ptr [esp + 0x9c]
// 005c9384  83c068               add eax, 0x68
// 005c9387  50                   push eax
// 005c9388  8bce                 mov ecx, esi
// 005c938a  c784249800000001000000 mov dword ptr [esp + 0x98], 1
// 005c9395  ff15b8e48900         call dword ptr [0x89e4b8]
// 005c939b  8d4c2408             lea ecx, [esp + 8]
// 005c939f  c744240401000000     mov dword ptr [esp + 4], 1
// 005c93a7  c684249400000000     mov byte ptr [esp + 0x94], 0
// 005c93af  e81cf8ffff           call 0x5c8bd0
// 005c93b4  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 005c93bb  8bc6                 mov eax, esi
// 005c93bd  5e                   pop esi
// 005c93be  64890d00000000       mov dword ptr fs:[0], ecx
// 005c93c5  81c494000000         add esp, 0x94
// 005c93cb  c20400               ret 4
// copied from an identical function in another client (function ?f@ns_ROCX000000@@YG?AUString@1@XZ)

namespace ns_ROCX000000 {
struct String;
typedef void (__thiscall *StringCopy)(String*, const String&);
extern StringCopy copyString;

struct String {
    char storage[28];
    String(const String& other) { copyString(this, other); }
    ~String();
};

struct Temporary {
    char storage[104];
    String value;
    Temporary();
    ~Temporary();
};

String __stdcall f()
{
    return Temporary().value;
}
}
