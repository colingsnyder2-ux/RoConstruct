// from server: 100% by EspClaude
// roc 2009-06 004702f0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004702f0
//
// 004702f0  6aff                 push -1
// 004702f2  687b3a8500           push 0x853a7b
// 004702f7  64a100000000         mov eax, dword ptr fs:[0]
// 004702fd  50                   push eax
// 004702fe  64892500000000       mov dword ptr fs:[0], esp
// 00470305  83ec1c               sub esp, 0x1c
// 00470308  53                   push ebx
// 00470309  6838d88b00           push 0x8bd838
// 0047030e  8d4c2408             lea ecx, [esp + 8]
// 00470312  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0047031a  ff15b4e48900         call dword ptr [0x89e4b4]
// 00470320  8d442404             lea eax, [esp + 4]
// 00470324  50                   push eax
// 00470325  8d4c2434             lea ecx, [esp + 0x34]
// 00470329  51                   push ecx
// 0047032a  c644243001           mov byte ptr [esp + 0x30], 1
// 0047032f  e82c300000           call 0x473360
// 00470334  83c408               add esp, 8
// 00470337  85c0                 test eax, eax
// 00470339  8d4c2404             lea ecx, [esp + 4]
// 0047033d  0f94c3               sete bl
// 00470340  c644242800           mov byte ptr [esp + 0x28], 0
// 00470345  ff15c4e48900         call dword ptr [0x89e4c4]
// 0047034b  84db                 test bl, bl
// 0047034d  7426                 je 0x470375
// 0047034f  8d4c2430             lea ecx, [esp + 0x30]
// 00470353  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0047035b  ff15c4e48900         call dword ptr [0x89e4c4]
// 00470361  33c0                 xor eax, eax
// 00470363  5b                   pop ebx
// 00470364  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00470368  64890d00000000       mov dword ptr fs:[0], ecx
// 0047036f  83c428               add esp, 0x28
// 00470372  c21c00               ret 0x1c
// 00470375  6830d88b00           push 0x8bd830
// 0047037a  8d4c2408             lea ecx, [esp + 8]
// 0047037e  ff15b4e48900         call dword ptr [0x89e4b4]
// 00470384  8d542404             lea edx, [esp + 4]
// 00470388  52                   push edx
// 00470389  8d442434             lea eax, [esp + 0x34]
// 0047038d  50                   push eax
// 0047038e  c644243002           mov byte ptr [esp + 0x30], 2
// 00470393  e8c82f0000           call 0x473360
// 00470398  83c408               add esp, 8
// 0047039b  85c0                 test eax, eax
// 0047039d  8d4c2404             lea ecx, [esp + 4]
// 004703a1  0f94c3               sete bl
// 004703a4  c644242800           mov byte ptr [esp + 0x28], 0
// 004703a9  ff15c4e48900         call dword ptr [0x89e4c4]
// 004703af  8d4c2430             lea ecx, [esp + 0x30]
// 004703b3  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 004703bb  ff15c4e48900         call dword ptr [0x89e4c4]
// 004703c1  b801000000           mov eax, 1
// 004703c6  84db                 test bl, bl
// 004703c8  7505                 jne 0x4703cf
// 004703ca  b802000000           mov eax, 2
// 004703cf  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004703d3  5b                   pop ebx
// 004703d4  64890d00000000       mov dword ptr fs:[0], ecx
// 004703db  83c428               add esp, 0x28
// 004703de  c21c00               ret 0x1c
// copied from an identical function in another client (function ?classify@ns_ROCX00003b@@YGHUString@1@@Z)

namespace ns_ROCX00003b {
struct String
{
    char storage[28];

    String(const char *);
    ~String();
};

extern void (__thiscall *constructString)(String *, const char *);
extern void (__thiscall *destroyString)(String *);
extern int __cdecl compare(const String &, const String &);

inline String::String(const char *text)
{
    constructString(this, text);
}

inline String::~String()
{
    destroyString(this);
}

int __stdcall classify(String value)
{
    if (compare(value, String("exact")) == 0)
        return 0;

    bool matched = compare(value, String("close")) == 0;
    if (matched)
        return 1;
    return 2;
}
}
