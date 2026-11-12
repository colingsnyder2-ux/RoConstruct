// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 0043e5a0  unit: Vector3Item  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043e5a0
// 0043e5a0  6aff                 push -1
// 0043e5a2  6889ff7300           push 0x73ff89
// 0043e5a7  64a100000000         mov eax, dword ptr fs:[0]
// 0043e5ad  50                   push eax
// 0043e5ae  83ec28               sub esp, 0x28
// 0043e5b1  56                   push esi
// 0043e5b2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043e5b7  33c4                 xor eax, esp
// 0043e5b9  50                   push eax
// 0043e5ba  8d442430             lea eax, [esp + 0x30]
// 0043e5be  64a300000000         mov dword ptr fs:[0], eax
// 0043e5c4  d9ee                 fldz 
// 0043e5c6  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0043e5ca  d9542408             fst dword ptr [esp + 8]
// 0043e5ce  d954240c             fst dword ptr [esp + 0xc]
// 0043e5d2  d95c2410             fstp dword ptr [esp + 0x10]
// 0043e5d6  ff1598dd7700         call dword ptr [0x77dd98]
// 0043e5dc  50                   push eax
// 0043e5dd  8d4c2418             lea ecx, [esp + 0x18]
// 0043e5e1  ff1598e67700         call dword ptr [0x77e698]
// 0043e5e7  8d442408             lea eax, [esp + 8]
// 0043e5eb  50                   push eax
// 0043e5ec  8d4c2418             lea ecx, [esp + 0x18]
// 0043e5f0  51                   push ecx
// 0043e5f1  c744244000000000     mov dword ptr [esp + 0x40], 0
// 0043e5f9  e892eb1400           call 0x58d190
// 0043e5fe  83c408               add esp, 8
// 0043e601  8d4c2414             lea ecx, [esp + 0x14]
// 0043e605  0fb6f0               movzx esi, al
// 0043e608  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 0043e610  ff15ace67700         call dword ptr [0x77e6ac]
// 0043e616  8bc6                 mov eax, esi
// 0043e618  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0043e61c  64890d00000000       mov dword ptr fs:[0], ecx
// 0043e623  59                   pop ecx
// 0043e624  5e                   pop esi
// 0043e625  83c434               add esp, 0x34
// 0043e628  c20400               ret 4

struct CStr {
    __declspec(dllimport) operator const char*() const;
};

struct StdString {
    __declspec(dllimport) StdString(const char* s);
    __declspec(dllimport) ~StdString();
    int storage[7];
};

struct Vector3 {
    float x, y, z;
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
};

bool __cdecl fromString(const StdString& text, Vector3& value);

struct Vector3Item {
    int Init(const CStr& text);
};

int Vector3Item::Init(const CStr& text) {
    Vector3 value(0.0f, 0.0f, 0.0f);
    StdString s(text);
    return fromString(s, value);
}
