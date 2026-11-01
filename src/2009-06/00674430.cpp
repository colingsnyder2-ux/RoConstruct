// from server: 90% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005d4c40  unit: RBX::VClothing::?$FactoryProduct  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d4c40
//
// 005d4c40  56                   push esi
// 005d4c41  57                   push edi
// 005d4c42  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005d4c46  57                   push edi
// 005d4c47  8bf1                 mov esi, ecx
// 005d4c49  e87260f8ff           call 0x55acc0
// 005d4c4e  3937                 cmp dword ptr [edi], esi
// 005d4c50  7553                 jne 0x5d4ca5
// 005d4c52  6a00                 push 0
// 005d4c54  6880699300           push 0x936980
// 005d4c59  68684d9300           push 0x934d68
// 005d4c5e  6a00                 push 0
// 005d4c60  56                   push esi
// 005d4c61  e860cb0c00           call 0x6a17c6
// 005d4c66  83c414               add esp, 0x14
// 005d4c69  85c0                 test eax, eax
// 005d4c6b  740c                 je 0x5d4c79
// 005d4c6d  8bc8                 mov ecx, eax
// 005d4c6f  e88cfeffff           call 0x5d4b00
// 005d4c74  5f                   pop edi
// 005d4c75  5e                   pop esi
// 005d4c76  c20400               ret 4
// 005d4c79  6a00                 push 0
// 005d4c7b  56                   push esi
// 005d4c7c  e82f12ecff           call 0x495eb0
// 005d4c81  83c408               add esp, 8
// 005d4c84  84c0                 test al, al
// 005d4c86  741d                 je 0x5d4ca5
// 005d4c88  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 005d4c8e  50                   push eax
// 005d4c8f  e88c4d0000           call 0x5d9a20
// 005d4c94  83c404               add esp, 4
// 005d4c97  85c0                 test eax, eax
// 005d4c99  740a                 je 0x5d4ca5
// 005d4c9b  8b16                 mov edx, dword ptr [esi]
// 005d4c9d  50                   push eax
// 005d4c9e  8b4240               mov eax, dword ptr [edx + 0x40]
// 005d4ca1  8bce                 mov ecx, esi
// 005d4ca3  ffd0                 call eax
// 005d4ca5  5f                   pop edi
// 005d4ca6  5e                   pop esi
// 005d4ca7  c20400               ret 4

struct S;
struct Appearance {
    void update();
};

struct VTable {
    void* slots[16];
    void (__thiscall *apply)(S*, void*);
};

struct S {
    VTable* table;
    char padding[256];
    void* appearance;

    void base(S**);
    void changed(S**);
};

extern char clothingType;
extern char appearanceType;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);
extern int __cdecl sub_495e80(int, int);
extern void* __cdecl lookup(void*);

void S::changed(S** value)
{
    base(value);
    if (*value == this) {
        Appearance* p = (Appearance*)__RTDynamicCast(
            this, 0, &clothingType, &appearanceType, 0);
        if (p) {
            p->update();
            return;
        }
        if ((unsigned char)sub_495e80((int)this, 0)) {
            void* result = lookup(appearance);
            if (result)
                table->apply(this, result);
        }
    }
}
