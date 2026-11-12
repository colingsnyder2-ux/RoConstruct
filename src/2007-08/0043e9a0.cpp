// from server: 100% by EspClaude
// from server: 50% by colin
// roc 2007-08 0043e9a0  unit: Vector3Item  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043e9a0
//
// 0043e9a0  6aff                 push -1
// 0043e9a2  68fa387600           push 0x7638fa
// 0043e9a7  64a100000000         mov eax, dword ptr fs:[0]
// 0043e9ad  50                   push eax
// 0043e9ae  51                   push ecx
// 0043e9af  53                   push ebx
// 0043e9b0  56                   push esi
// 0043e9b1  57                   push edi
// 0043e9b2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043e9b7  33c4                 xor eax, esp
// 0043e9b9  50                   push eax
// 0043e9ba  8d442414             lea eax, [esp + 0x14]
// 0043e9be  64a300000000         mov dword ptr fs:[0], eax
// 0043e9c4  8bf9                 mov edi, ecx
// 0043e9c6  e875982500           call 0x698240
// 0043e9cb  33f6                 xor esi, esi
// 0043e9cd  8d9f1c010000         lea ebx, [edi + 0x11c]
// 0043e9d3  682c010000           push 0x12c
// 0043e9d8  e819151f00           call 0x62fef6
// 0043e9dd  83c404               add esp, 4
// 0043e9e0  89442410             mov dword ptr [esp + 0x10], eax
// 0043e9e4  85c0                 test eax, eax
// 0043e9e6  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0043e9ee  7418                 je 0x43ea08
// 0043e9f0  8b8f14010000         mov ecx, dword ptr [edi + 0x114]
// 0043e9f6  8b9718010000         mov edx, dword ptr [edi + 0x118]
// 0043e9fc  56                   push esi
// 0043e9fd  51                   push ecx
// 0043e9fe  52                   push edx
// 0043e9ff  8bc8                 mov ecx, eax
// 0043ea01  e86afcffff           call 0x43e670
// 0043ea06  eb02                 jmp 0x43ea0a
// 0043ea08  33c0                 xor eax, eax
// 0043ea0a  50                   push eax
// 0043ea0b  8bcf                 mov ecx, edi
// 0043ea0d  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0043ea15  8903                 mov dword ptr [ebx], eax
// 0043ea17  e8e4b22500           call 0x699d00
// 0043ea1c  83c601               add esi, 1
// 0043ea1f  83c304               add ebx, 4
// 0043ea22  83fe03               cmp esi, 3
// 0043ea25  7cac                 jl 0x43e9d3
// 0043ea27  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043ea2b  64890d00000000       mov dword ptr fs:[0], ecx
// 0043ea32  59                   pop ecx
// 0043ea33  5f                   pop edi
// 0043ea34  5e                   pop esi
// 0043ea35  5b                   pop ebx
// 0043ea36  83c410               add esp, 0x10
// 0043ea39  c3                   ret 

// new(0x12c) object constructed by thiscall 0x43e670(arg [this+0x118], arg [this+0x114], i);
// result stored into this+0x11c+4*i and passed to thiscall 0x699d00 on this.
struct Child {
    char storage[0x12c];
    Child(int a, int b, int index);
};

struct Vector3Item {
    char pad[0x114];
    int field114;
    int field118;
    Child* items[3];

    void baseInit();
    void addChild(Child* c);
    void method();
};

void Vector3Item::method()
{
    baseInit();
    for (int i = 0; i < 3; i++) {
        items[i] = new Child(field118, field114, i);
        addChild(items[i]);
    }
}
