// from server: 100% by auto
// roc 2008-06 00561330  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00561330
//
// 00561330  83ec08               sub esp, 8
// 00561333  56                   push esi
// 00561334  8bf1                 mov esi, ecx
// 00561336  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00561339  57                   push edi
// 0056133a  85c9                 test ecx, ecx
// 0056133c  7504                 jne 0x561342
// 0056133e  33c0                 xor eax, eax
// 00561340  eb08                 jmp 0x56134a
// 00561342  8b4614               mov eax, dword ptr [esi + 0x14]
// 00561345  2bc1                 sub eax, ecx
// 00561347  c1f805               sar eax, 5
// 0056134a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0056134d  8bd7                 mov edx, edi
// 0056134f  2bd1                 sub edx, ecx
// 00561351  c1fa05               sar edx, 5
// 00561354  3bd0                 cmp edx, eax
// 00561356  7331                 jae 0x561389
// 00561358  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056135c  c644240800           mov byte ptr [esp + 8], 0
// 00561361  8b442408             mov eax, dword ptr [esp + 8]
// 00561365  50                   push eax
// 00561366  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056136a  51                   push ecx
// 0056136b  8d5608               lea edx, [esi + 8]
// 0056136e  52                   push edx
// 0056136f  50                   push eax
// 00561370  6a01                 push 1
// 00561372  57                   push edi
// 00561373  e878e2ffff           call 0x55f5f0
// 00561378  83c418               add esp, 0x18
// 0056137b  83c720               add edi, 0x20
// 0056137e  897e10               mov dword ptr [esi + 0x10], edi
// 00561381  5f                   pop edi
// 00561382  5e                   pop esi
// 00561383  83c408               add esp, 8
// 00561386  c20400               ret 4
// 00561389  3bcf                 cmp ecx, edi
// 0056138b  7606                 jbe 0x561393
// 0056138d  ff1590288000         call dword ptr [0x802890]
// 00561393  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00561397  8b06                 mov eax, dword ptr [esi]
// 00561399  51                   push ecx
// 0056139a  57                   push edi
// 0056139b  50                   push eax
// 0056139c  8d542414             lea edx, [esp + 0x14]
// 005613a0  52                   push edx
// 005613a1  8bce                 mov ecx, esi
// 005613a3  e848feffff           call 0x5611f0
// 005613a8  5f                   pop edi
// 005613a9  5e                   pop esi
// 005613aa  83c408               add esp, 8
// 005613ad  c20400               ret 4
// standard library vector<pod32> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
