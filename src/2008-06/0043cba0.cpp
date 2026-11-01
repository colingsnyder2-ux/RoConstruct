// from server: 100% by colin
#include <intrin.h>
// from server: 95% by king_originala
// roc 2008-06 0043cba0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043cba0
//
// 0043cba0  6aff                 push -1
// 0043cba2  6888067c00           push 0x7c0688
// 0043cba7  64a100000000         mov eax, dword ptr fs:[0]
// 0043cbad  50                   push eax
// 0043cbae  64892500000000       mov dword ptr fs:[0], esp
// 0043cbb5  51                   push ecx
// 0043cbb6  56                   push esi
// 0043cbb7  57                   push edi
// 0043cbb8  8bf1                 mov esi, ecx
// 0043cbba  83ec20               sub esp, 0x20
// 0043cbbd  8bfc                 mov edi, esp
// 0043cbbf  8d442448             lea eax, [esp + 0x48]
// 0043cbc3  89642428             mov dword ptr [esp + 0x28], esp
// 0043cbc7  50                   push eax
// 0043cbc8  8bcf                 mov ecx, edi
// 0043cbca  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0043cbd2  ff155c248000         call dword ptr [0x80245c]
// 0043cbd8  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0043cbdc  894f1c               mov dword ptr [edi + 0x1c], ecx
// 0043cbdf  8b542444             mov edx, dword ptr [esp + 0x44]
// 0043cbe3  8b442440             mov eax, dword ptr [esp + 0x40]
// 0043cbe7  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0043cbeb  52                   push edx
// 0043cbec  50                   push eax
// 0043cbed  51                   push ecx
// 0043cbee  8bce                 mov ecx, esi
// 0043cbf0  e88bfeffff           call 0x43ca80
// 0043cbf5  8d4c2428             lea ecx, [esp + 0x28]
// 0043cbf9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0043cc01  ff1568248000         call dword ptr [0x802468]
// 0043cc07  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043cc0b  5f                   pop edi
// 0043cc0c  8bc6                 mov eax, esi
// 0043cc0e  64890d00000000       mov dword ptr fs:[0], ecx
// 0043cc15  5e                   pop esi
// 0043cc16  83c410               add esp, 0x10
// 0043cc19  c22c00               ret 0x2c

struct String {
    unsigned int storage[7];
    String(const String&);
    ~String();
};

extern String* (__thiscall *string_copy)(String*, const String&);
extern void (__thiscall *string_destroy)(String*);

inline String::String(const String& other) {
    string_copy(this, other);
}

inline String::~String() {
    string_destroy(this);
}

struct Value {
    String text;
    int value;
    Value(const Value& o) : text(o.text) { value = o.value; _ReadWriteBarrier(); }
};

struct Base {
    Base(int, int, int, Value);
};

struct S : Base {
    S(int, int, int, Value);
};

S::S(int a, int b, int c, Value value)
    : Base(a, b, c, value) {
}
