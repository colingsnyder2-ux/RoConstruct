// from server: 77% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 00442140  unit: TextureItem  size: 295 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00442140
//
// 00442140  64a100000000         mov eax, dword ptr fs:[0]
// 00442146  6aff                 push -1
// 00442148  68e80b7c00           push 0x7c0be8
// 0044214d  50                   push eax
// 0044214e  64892500000000       mov dword ptr fs:[0], esp
// 00442155  83ec3c               sub esp, 0x3c
// 00442158  55                   push ebp
// 00442159  57                   push edi
// 0044215a  8bf9                 mov edi, ecx
// 0044215c  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0044215f  8b4104               mov eax, dword ptr [ecx + 4]
// 00442162  80782900             cmp byte ptr [eax + 0x29], 0
// 00442166  8be9                 mov ebp, ecx
// 00442168  751a                 jne 0x442184
// 0044216a  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0044216e  8b09                 mov ecx, dword ptr [ecx]
// 00442170  39480c               cmp dword ptr [eax + 0xc], ecx
// 00442173  7305                 jae 0x44217a
// 00442175  8b4008               mov eax, dword ptr [eax + 8]
// 00442178  eb04                 jmp 0x44217e
// 0044217a  8be8                 mov ebp, eax
// 0044217c  8b00                 mov eax, dword ptr [eax]
// 0044217e  80782900             cmp byte ptr [eax + 0x29], 0
// 00442182  74ec                 je 0x442170
// 00442184  8b5718               mov edx, dword ptr [edi + 0x18]
// 00442187  56                   push esi
// 00442188  8b37                 mov esi, dword ptr [edi]
// 0044218a  89542410             mov dword ptr [esp + 0x10], edx
// 0044218e  85f6                 test esi, esi
// 00442190  7404                 je 0x442196
// 00442192  3bf6                 cmp esi, esi
// 00442194  7406                 je 0x44219c
// 00442196  ff1590288000         call dword ptr [0x802890]
// 0044219c  3b6c2410             cmp ebp, dword ptr [esp + 0x10]
// 004421a0  740f                 je 0x4421b1
// 004421a2  8b442458             mov eax, dword ptr [esp + 0x58]
// 004421a6  8b08                 mov ecx, dword ptr [eax]
// 004421a8  3b4d0c               cmp ecx, dword ptr [ebp + 0xc]
// 004421ab  0f8386000000         jae 0x442237
// 004421b1  6a04                 push 4
// 004421b3  e868e72500           call 0x6a0920
// 004421b8  33c9                 xor ecx, ecx
// 004421ba  83c404               add esp, 4
// 004421bd  3bc1                 cmp eax, ecx
// 004421bf  7408                 je 0x4421c9
// 004421c1  8d542414             lea edx, [esp + 0x14]
// 004421c5  8910                 mov dword ptr [eax], edx
// 004421c7  eb02                 jmp 0x4421cb
// 004421c9  33c0                 xor eax, eax
// 004421cb  89442414             mov dword ptr [esp + 0x14], eax
// 004421cf  894c2420             mov dword ptr [esp + 0x20], ecx
// 004421d3  894c2424             mov dword ptr [esp + 0x24], ecx
// 004421d7  894c2428             mov dword ptr [esp + 0x28], ecx
// 004421db  8b442458             mov eax, dword ptr [esp + 0x58]
// 004421df  8b08                 mov ecx, dword ptr [eax]
// 004421e1  8d542414             lea edx, [esp + 0x14]
// 004421e5  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004421e9  52                   push edx
// 004421ea  8d4c2434             lea ecx, [esp + 0x34]
// 004421ee  c744245401000000     mov dword ptr [esp + 0x54], 1
// 004421f6  e805a91600           call 0x5acb00
// 004421fb  8d44242c             lea eax, [esp + 0x2c]
// 004421ff  50                   push eax
// 00442200  55                   push ebp
// 00442201  56                   push esi
// 00442202  8d4c2418             lea ecx, [esp + 0x18]
// 00442206  51                   push ecx
// 00442207  8bcf                 mov ecx, edi
// 00442209  c644246002           mov byte ptr [esp + 0x60], 2
// 0044220e  e80dfdffff           call 0x441f20
// 00442213  8b30                 mov esi, dword ptr [eax]
// 00442215  8b6804               mov ebp, dword ptr [eax + 4]
// 00442218  8d4c2430             lea ecx, [esp + 0x30]
// 0044221c  c644245001           mov byte ptr [esp + 0x50], 1
// 00442221  e8ba0d1600           call 0x5a2fe0
// 00442226  8d4c2414             lea ecx, [esp + 0x14]
// 0044222a  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 00442232  e8a90d1600           call 0x5a2fe0
// 00442237  85f6                 test esi, esi
// 00442239  7528                 jne 0x442263
// 0044223b  ff1590288000         call dword ptr [0x802890]
// 00442241  3b6e18               cmp ebp, dword ptr [esi + 0x18]
// 00442244  5e                   pop esi
// 00442245  7506                 jne 0x44224d
// 00442247  ff1590288000         call dword ptr [0x802890]
// 0044224d  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00442251  5f                   pop edi
// 00442252  8d4510               lea eax, [ebp + 0x10]
// 00442255  5d                   pop ebp
// 00442256  64890d00000000       mov dword ptr fs:[0], ecx
// 0044225d  83c448               add esp, 0x48
// 00442260  c20400               ret 4
// 00442263  8b36                 mov esi, dword ptr [esi]
// 00442265  ebda                 jmp 0x442241

// from server: 69% by colin
// roc 2008-06 00442140  unit: TextureItem  size: 295 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00442140
//
// roc-cl: 50727
#include <map>
#include <vector>
struct Elem { int x; };
struct Value : std::vector<Elem> {
    Value() {}
    Value(const Value&);
    ~Value();
};

Value& lookup(std::map<unsigned int, Value>& m, const unsigned int& k)
{
    return m[k];
}
