// from server: 100% by EspClaude
// roc 2009-06 00437f40  unit: Vector3Item  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00437f40
//
// 00437f40  6aff                 push -1
// 00437f42  68d9b88500           push 0x85b8d9
// 00437f47  64a100000000         mov eax, dword ptr fs:[0]
// 00437f4d  50                   push eax
// 00437f4e  64892500000000       mov dword ptr fs:[0], esp
// 00437f55  83ec28               sub esp, 0x28
// 00437f58  d9ee                 fldz 
// 00437f5a  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00437f5e  d91424               fst dword ptr [esp]
// 00437f61  56                   push esi
// 00437f62  d9542408             fst dword ptr [esp + 8]
// 00437f66  d95c240c             fstp dword ptr [esp + 0xc]
// 00437f6a  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00437f70  50                   push eax
// 00437f71  8d4c2414             lea ecx, [esp + 0x14]
// 00437f75  ff15b4e48900         call dword ptr [0x89e4b4]
// 00437f7b  8d442404             lea eax, [esp + 4]
// 00437f7f  50                   push eax
// 00437f80  8d4c2414             lea ecx, [esp + 0x14]
// 00437f84  51                   push ecx
// 00437f85  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 00437f8d  e85e3f2100           call 0x64bef0
// 00437f92  83c408               add esp, 8
// 00437f95  8d4c2410             lea ecx, [esp + 0x10]
// 00437f99  0fb6f0               movzx esi, al
// 00437f9c  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 00437fa4  ff15c4e48900         call dword ptr [0x89e4c4]
// 00437faa  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00437fae  8bc6                 mov eax, esi
// 00437fb0  5e                   pop esi
// 00437fb1  64890d00000000       mov dword ptr fs:[0], ecx
// 00437fb8  83c434               add esp, 0x34
// 00437fbb  c20400               ret 4
// copied from an identical function in another client (function ?readVector@ns_ROCX000009@@YGHPAUInput@1@@Z)

namespace ns_ROCX000009 {
struct String;

extern void (__thiscall* constructString)(String*, const char*);
extern void (__thiscall* destroyString)(String*);

struct String {
    char reserved[4];
    union {
        char buffer[16];
        char* pointer;
    } data;
    unsigned int length;
    unsigned int capacity;

    String(const char* text) { constructString(this, text); }
    ~String() { destroyString(this); }
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Input;

extern const char* (__thiscall* getText)(Input*);
extern bool __cdecl parseVector(const String&, Vector3&);

int __stdcall readVector(Input* input)
{
    Vector3 value = { 0.0f, 0.0f, 0.0f };
    String text(getText(input));
    return parseVector(text, value);
}
}
