// from server: 100% by auto
// roc 2007-03 005c0d10  unit: seg_005c0000  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c0d10
//
// 005c0d10  55                   push ebp
// 005c0d11  8bec                 mov ebp, esp
// 005c0d13  6aff                 push -1
// 005c0d15  68d0a57500           push 0x75a5d0
// 005c0d1a  64a100000000         mov eax, dword ptr fs:[0]
// 005c0d20  50                   push eax
// 005c0d21  64892500000000       mov dword ptr fs:[0], esp
// 005c0d28  83ec0c               sub esp, 0xc
// 005c0d2b  53                   push ebx
// 005c0d2c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005c0d2f  8b4304               mov eax, dword ptr [ebx + 4]
// 005c0d32  56                   push esi
// 005c0d33  57                   push edi
// 005c0d34  8bf9                 mov edi, ecx
// 005c0d36  33c9                 xor ecx, ecx
// 005c0d38  3bc1                 cmp eax, ecx
// 005c0d3a  8965f0               mov dword ptr [ebp - 0x10], esp
// 005c0d3d  897de8               mov dword ptr [ebp - 0x18], edi
// 005c0d40  7504                 jne 0x5c0d46
// 005c0d42  33f6                 xor esi, esi
// 005c0d44  eb08                 jmp 0x5c0d4e
// 005c0d46  8b7308               mov esi, dword ptr [ebx + 8]
// 005c0d49  2bf0                 sub esi, eax
// 005c0d4b  c1fe04               sar esi, 4
// 005c0d4e  3bf1                 cmp esi, ecx
// 005c0d50  894f04               mov dword ptr [edi + 4], ecx
// 005c0d53  894f08               mov dword ptr [edi + 8], ecx
// 005c0d56  894f0c               mov dword ptr [edi + 0xc], ecx
// 005c0d59  746c                 je 0x5c0dc7
// 005c0d5b  81feffffff0f         cmp esi, 0xfffffff
// 005c0d61  7605                 jbe 0x5c0d68
// 005c0d63  e86873ffff           call 0x5b80d0
// 005c0d68  51                   push ecx
// 005c0d69  56                   push esi
// 005c0d6a  e831faffff           call 0x5c07a0
// 005c0d6f  c1e604               shl esi, 4
// 005c0d72  03f0                 add esi, eax
// 005c0d74  894704               mov dword ptr [edi + 4], eax
// 005c0d77  894708               mov dword ptr [edi + 8], eax
// 005c0d7a  89770c               mov dword ptr [edi + 0xc], esi
// 005c0d7d  8b4308               mov eax, dword ptr [ebx + 8]
// 005c0d80  83c408               add esp, 8
// 005c0d83  394304               cmp dword ptr [ebx + 4], eax
// 005c0d86  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005c0d8d  8945ec               mov dword ptr [ebp - 0x14], eax
// 005c0d90  7606                 jbe 0x5c0d98
// 005c0d92  ff1544e97700         call dword ptr [0x77e944]
// 005c0d98  8b7304               mov esi, dword ptr [ebx + 4]
// 005c0d9b  3b7308               cmp esi, dword ptr [ebx + 8]
// 005c0d9e  7606                 jbe 0x5c0da6
// 005c0da0  ff1544e97700         call dword ptr [0x77e944]
// 005c0da6  8b4704               mov eax, dword ptr [edi + 4]
// 005c0da9  c6450800             mov byte ptr [ebp + 8], 0
// 005c0dad  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005c0db0  8b5508               mov edx, dword ptr [ebp + 8]
// 005c0db3  51                   push ecx
// 005c0db4  52                   push edx
// 005c0db5  57                   push edi
// 005c0db6  50                   push eax
// 005c0db7  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005c0dba  50                   push eax
// 005c0dbb  56                   push esi
// 005c0dbc  e8affcffff           call 0x5c0a70
// 005c0dc1  83c418               add esp, 0x18
// 005c0dc4  894708               mov dword ptr [edi + 8], eax
// 005c0dc7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005c0dca  8bc7                 mov eax, edi
// 005c0dcc  5f                   pop edi
// 005c0dcd  5e                   pop esi
// 005c0dce  64890d00000000       mov dword ptr fs:[0], ecx
// 005c0dd5  5b                   pop ebx
// 005c0dd6  8be5                 mov esp, ebp
// 005c0dd8  5d                   pop ebp
// 005c0dd9  c20400               ret 4
// 005c0ddc  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 005c0ddf  e8aca9f7ff           call 0x53b790
// 005c0de4  6a00                 push 0
// 005c0de6  6a00                 push 0
// 005c0de8  e841e20500           call 0x61f02e
// standard library vector<pod16> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
