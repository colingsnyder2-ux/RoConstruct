// from server: 100% by auto
// roc 2008-06 0059c3b0  unit: RBX::PartInstance  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059c3b0
//
// 0059c3b0  83ec08               sub esp, 8
// 0059c3b3  56                   push esi
// 0059c3b4  8bf1                 mov esi, ecx
// 0059c3b6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0059c3b9  57                   push edi
// 0059c3ba  85c9                 test ecx, ecx
// 0059c3bc  7504                 jne 0x59c3c2
// 0059c3be  33c0                 xor eax, eax
// 0059c3c0  eb08                 jmp 0x59c3ca
// 0059c3c2  8b4614               mov eax, dword ptr [esi + 0x14]
// 0059c3c5  2bc1                 sub eax, ecx
// 0059c3c7  c1f803               sar eax, 3
// 0059c3ca  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0059c3cd  8bd7                 mov edx, edi
// 0059c3cf  2bd1                 sub edx, ecx
// 0059c3d1  c1fa03               sar edx, 3
// 0059c3d4  3bd0                 cmp edx, eax
// 0059c3d6  7331                 jae 0x59c409
// 0059c3d8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0059c3dc  c644240800           mov byte ptr [esp + 8], 0
// 0059c3e1  8b442408             mov eax, dword ptr [esp + 8]
// 0059c3e5  50                   push eax
// 0059c3e6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0059c3ea  51                   push ecx
// 0059c3eb  8d5608               lea edx, [esi + 8]
// 0059c3ee  52                   push edx
// 0059c3ef  50                   push eax
// 0059c3f0  6a01                 push 1
// 0059c3f2  57                   push edi
// 0059c3f3  e898f0ffff           call 0x59b490
// 0059c3f8  83c418               add esp, 0x18
// 0059c3fb  83c708               add edi, 8
// 0059c3fe  897e10               mov dword ptr [esi + 0x10], edi
// 0059c401  5f                   pop edi
// 0059c402  5e                   pop esi
// 0059c403  83c408               add esp, 8
// 0059c406  c20400               ret 4
// 0059c409  3bcf                 cmp ecx, edi
// 0059c40b  7606                 jbe 0x59c413
// 0059c40d  ff1590288000         call dword ptr [0x802890]
// 0059c413  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0059c417  8b06                 mov eax, dword ptr [esi]
// 0059c419  51                   push ecx
// 0059c41a  57                   push edi
// 0059c41b  50                   push eax
// 0059c41c  8d542414             lea edx, [esp + 0x14]
// 0059c420  52                   push edx
// 0059c421  8bce                 mov ecx, esi
// 0059c423  e808fdffff           call 0x59c130
// 0059c428  5f                   pop edi
// 0059c429  5e                   pop esi
// 0059c42a  83c408               add esp, 8
// 0059c42d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
