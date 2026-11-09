// from server: 100% by auto
// roc 2007-08 005c5040  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 204 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c5040
//
// 005c5040  55                   push ebp
// 005c5041  8bec                 mov ebp, esp
// 005c5043  6aff                 push -1
// 005c5045  6810997500           push 0x759910
// 005c504a  64a100000000         mov eax, dword ptr fs:[0]
// 005c5050  50                   push eax
// 005c5051  64892500000000       mov dword ptr fs:[0], esp
// 005c5058  83ec0c               sub esp, 0xc
// 005c505b  53                   push ebx
// 005c505c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005c505f  8b4304               mov eax, dword ptr [ebx + 4]
// 005c5062  56                   push esi
// 005c5063  57                   push edi
// 005c5064  8bf9                 mov edi, ecx
// 005c5066  33c9                 xor ecx, ecx
// 005c5068  3bc1                 cmp eax, ecx
// 005c506a  8965f0               mov dword ptr [ebp - 0x10], esp
// 005c506d  897de8               mov dword ptr [ebp - 0x18], edi
// 005c5070  7504                 jne 0x5c5076
// 005c5072  33f6                 xor esi, esi
// 005c5074  eb08                 jmp 0x5c507e
// 005c5076  8b7308               mov esi, dword ptr [ebx + 8]
// 005c5079  2bf0                 sub esi, eax
// 005c507b  c1fe04               sar esi, 4
// 005c507e  3bf1                 cmp esi, ecx
// 005c5080  894f04               mov dword ptr [edi + 4], ecx
// 005c5083  894f08               mov dword ptr [edi + 8], ecx
// 005c5086  894f0c               mov dword ptr [edi + 0xc], ecx
// 005c5089  746c                 je 0x5c50f7
// 005c508b  81feffffff0f         cmp esi, 0xfffffff
// 005c5091  7605                 jbe 0x5c5098
// 005c5093  e8987c0000           call 0x5ccd30
// 005c5098  51                   push ecx
// 005c5099  56                   push esi
// 005c509a  e861dbe7ff           call 0x442c00
// 005c509f  c1e604               shl esi, 4
// 005c50a2  03f0                 add esi, eax
// 005c50a4  894704               mov dword ptr [edi + 4], eax
// 005c50a7  894708               mov dword ptr [edi + 8], eax
// 005c50aa  89770c               mov dword ptr [edi + 0xc], esi
// 005c50ad  8b4308               mov eax, dword ptr [ebx + 8]
// 005c50b0  83c408               add esp, 8
// 005c50b3  394304               cmp dword ptr [ebx + 4], eax
// 005c50b6  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005c50bd  8945ec               mov dword ptr [ebp - 0x14], eax
// 005c50c0  7606                 jbe 0x5c50c8
// 005c50c2  ff15d8e67700         call dword ptr [0x77e6d8]
// 005c50c8  8b7304               mov esi, dword ptr [ebx + 4]
// 005c50cb  3b7308               cmp esi, dword ptr [ebx + 8]
// 005c50ce  7606                 jbe 0x5c50d6
// 005c50d0  ff15d8e67700         call dword ptr [0x77e6d8]
// 005c50d6  8b4704               mov eax, dword ptr [edi + 4]
// 005c50d9  c6450800             mov byte ptr [ebp + 8], 0
// 005c50dd  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005c50e0  8b5508               mov edx, dword ptr [ebp + 8]
// 005c50e3  51                   push ecx
// 005c50e4  52                   push edx
// 005c50e5  57                   push edi
// 005c50e6  50                   push eax
// 005c50e7  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005c50ea  50                   push eax
// 005c50eb  56                   push esi
// 005c50ec  e8affcffff           call 0x5c4da0
// 005c50f1  83c418               add esp, 0x18
// 005c50f4  894708               mov dword ptr [edi + 8], eax
// 005c50f7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005c50fa  8bc7                 mov eax, edi
// 005c50fc  5f                   pop edi
// 005c50fd  5e                   pop esi
// 005c50fe  64890d00000000       mov dword ptr fs:[0], ecx
// 005c5105  5b                   pop ebx
// 005c5106  8be5                 mov esp, ebp
// 005c5108  5d                   pop ebp
// 005c5109  c20400               ret 4
// standard library vector<pod16> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
