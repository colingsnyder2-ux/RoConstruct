// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005ad6d0  unit: RBX::Reflection::UTuple::?$holder  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ad6d0
//
// 005ad6d0  6aff                 push -1
// 005ad6d2  683bf47b00           push 0x7bf43b
// 005ad6d7  64a100000000         mov eax, dword ptr fs:[0]
// 005ad6dd  50                   push eax
// 005ad6de  64892500000000       mov dword ptr fs:[0], esp
// 005ad6e5  51                   push ecx
// 005ad6e6  53                   push ebx
// 005ad6e7  55                   push ebp
// 005ad6e8  56                   push esi
// 005ad6e9  57                   push edi
// 005ad6ea  6a18                 push 0x18
// 005ad6ec  e82f320f00           call 0x6a0920
// 005ad6f1  83c404               add esp, 4
// 005ad6f4  89442410             mov dword ptr [esp + 0x10], eax
// 005ad6f8  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 005ad6fc  33f6                 xor esi, esi
// 005ad6fe  8974241c             mov dword ptr [esp + 0x1c], esi
// 005ad702  3bc6                 cmp eax, esi
// 005ad704  740a                 je 0x5ad710
// 005ad706  53                   push ebx
// 005ad707  8bc8                 mov ecx, eax
// 005ad709  e832c5fdff           call 0x589c40
// 005ad70e  8bf0                 mov esi, eax
// 005ad710  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005ad714  8b2f                 mov ebp, dword ptr [edi]
// 005ad716  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 005ad71e  3bf5                 cmp esi, ebp
// 005ad720  7414                 je 0x5ad736
// 005ad722  85ed                 test ebp, ebp
// 005ad724  7410                 je 0x5ad736
// 005ad726  8bcd                 mov ecx, ebp
// 005ad728  e803ffe7ff           call 0x42d630
// 005ad72d  55                   push ebp
// 005ad72e  e8472f0f00           call 0x6a067a
// 005ad733  83c404               add esp, 4
// 005ad736  8937                 mov dword ptr [edi], esi
// 005ad738  33f6                 xor esi, esi
// 005ad73a  85db                 test ebx, ebx
// 005ad73c  761e                 jbe 0x5ad75c
// 005ad73e  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005ad742  8b0f                 mov ecx, dword ptr [edi]
// 005ad744  56                   push esi
// 005ad745  e8063b0a00           call 0x651250
// 005ad74a  6a01                 push 1
// 005ad74c  50                   push eax
// 005ad74d  46                   inc esi
// 005ad74e  56                   push esi
// 005ad74f  55                   push ebp
// 005ad750  e82bfcffff           call 0x5ad380
// 005ad755  83c410               add esp, 0x10
// 005ad758  3bf3                 cmp esi, ebx
// 005ad75a  72e6                 jb 0x5ad742
// 005ad75c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005ad760  5f                   pop edi
// 005ad761  5e                   pop esi
// 005ad762  5d                   pop ebp
// 005ad763  5b                   pop ebx
// 005ad764  64890d00000000       mov dword ptr fs:[0], ecx
// 005ad76b  83c410               add esp, 0x10
// 005ad76e  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Tuple {
    unsigned char storage[24];

    Tuple(unsigned int count);
    ~Tuple();
    void* element(unsigned int index);
};

extern void __cdecl transfer(void* state, unsigned int index,
                            void* value, int flag);

void __cdecl buildTuple(Tuple** destination, void* state, unsigned int count)
{
    Tuple* replacement = new Tuple(count);
    Tuple* previous = *destination;

    if (replacement != previous && previous != 0)
        delete previous;

    *destination = replacement;

    unsigned int index = 0;
    while (index < count) {
        void* value = (*destination)->element(index);
        ++index;
        transfer(state, index, value, 1);
    }
}
