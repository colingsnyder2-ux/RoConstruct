// from server: 100% by auto
// roc 2009-06 0083a0b0  unit: Ogre::RbxEntity  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0083a0b0
//
// 0083a0b0  55                   push ebp
// 0083a0b1  8bec                 mov ebp, esp
// 0083a0b3  6aff                 push -1
// 0083a0b5  6830358800           push 0x883530
// 0083a0ba  64a100000000         mov eax, dword ptr fs:[0]
// 0083a0c0  50                   push eax
// 0083a0c1  64892500000000       mov dword ptr fs:[0], esp
// 0083a0c8  83ec10               sub esp, 0x10
// 0083a0cb  8b5508               mov edx, dword ptr [ebp + 8]
// 0083a0ce  53                   push ebx
// 0083a0cf  56                   push esi
// 0083a0d0  57                   push edi
// 0083a0d1  8965f0               mov dword ptr [ebp - 0x10], esp
// 0083a0d4  8bf1                 mov esi, ecx
// 0083a0d6  81faffffff1f         cmp edx, 0x1fffffff
// 0083a0dc  7605                 jbe 0x83a0e3
// 0083a0de  e87d62c5ff           call 0x490360
// 0083a0e3  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0083a0e6  85c9                 test ecx, ecx
// 0083a0e8  7504                 jne 0x83a0ee
// 0083a0ea  33c0                 xor eax, eax
// 0083a0ec  eb08                 jmp 0x83a0f6
// 0083a0ee  8b4614               mov eax, dword ptr [esi + 0x14]
// 0083a0f1  2bc1                 sub eax, ecx
// 0083a0f3  c1f803               sar eax, 3
// 0083a0f6  3bc2                 cmp eax, edx
// 0083a0f8  737e                 jae 0x83a178
// 0083a0fa  6a00                 push 0
// 0083a0fc  52                   push edx
// 0083a0fd  e8eeadc4ff           call 0x484ef0
// 0083a102  8bd8                 mov ebx, eax
// 0083a104  8b4610               mov eax, dword ptr [esi + 0x10]
// 0083a107  83c408               add esp, 8
// 0083a10a  895de4               mov dword ptr [ebp - 0x1c], ebx
// 0083a10d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0083a114  8945e8               mov dword ptr [ebp - 0x18], eax
// 0083a117  39460c               cmp dword ptr [esi + 0xc], eax
// 0083a11a  7606                 jbe 0x83a122
// 0083a11c  ff15ace98900         call dword ptr [0x89e9ac]
// 0083a122  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0083a125  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0083a128  7606                 jbe 0x83a130
// 0083a12a  ff15ace98900         call dword ptr [0x89e9ac]
// 0083a130  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0083a133  c645ec00             mov byte ptr [ebp - 0x14], 0
// 0083a137  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0083a13a  50                   push eax
// 0083a13b  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 0083a13e  51                   push ecx
// 0083a13f  8d5608               lea edx, [esi + 8]
// 0083a142  52                   push edx
// 0083a143  53                   push ebx
// 0083a144  50                   push eax
// 0083a145  57                   push edi
// 0083a146  e8c5bdc4ff           call 0x485f10
// 0083a14b  8b460c               mov eax, dword ptr [esi + 0xc]
// 0083a14e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0083a151  2bf8                 sub edi, eax
// 0083a153  83c418               add esp, 0x18
// 0083a156  c1ff03               sar edi, 3
// 0083a159  85c0                 test eax, eax
// 0083a15b  7409                 je 0x83a166
// 0083a15d  50                   push eax
// 0083a15e  e8cfe8edff           call 0x718a32
// 0083a163  83c404               add esp, 4
// 0083a166  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0083a169  8d14cb               lea edx, [ebx + ecx*8]
// 0083a16c  8d04fb               lea eax, [ebx + edi*8]
// 0083a16f  895614               mov dword ptr [esi + 0x14], edx
// 0083a172  894610               mov dword ptr [esi + 0x10], eax
// 0083a175  895e0c               mov dword ptr [esi + 0xc], ebx
// 0083a178  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0083a17b  5f                   pop edi
// 0083a17c  5e                   pop esi
// 0083a17d  64890d00000000       mov dword ptr fs:[0], ecx
// 0083a184  5b                   pop ebx
// 0083a185  8be5                 mov esp, ebp
// 0083a187  5d                   pop ebp
// 0083a188  c20400               ret 4
// standard library vector<pod8> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
