// from server: 100% by auto
// roc 2009-06 00486b40  unit: Ogre::RbxMeshPartAdapter  size: 332 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486b40
//
// 00486b40  55                   push ebp
// 00486b41  8bec                 mov ebp, esp
// 00486b43  6aff                 push -1
// 00486b45  68b0548500           push 0x8554b0
// 00486b4a  64a100000000         mov eax, dword ptr fs:[0]
// 00486b50  50                   push eax
// 00486b51  64892500000000       mov dword ptr fs:[0], esp
// 00486b58  83ec0c               sub esp, 0xc
// 00486b5b  53                   push ebx
// 00486b5c  56                   push esi
// 00486b5d  8bf1                 mov esi, ecx
// 00486b5f  8b560c               mov edx, dword ptr [esi + 0xc]
// 00486b62  57                   push edi
// 00486b63  8965f0               mov dword ptr [ebp - 0x10], esp
// 00486b66  85d2                 test edx, edx
// 00486b68  7504                 jne 0x486b6e
// 00486b6a  33c9                 xor ecx, ecx
// 00486b6c  eb0a                 jmp 0x486b78
// 00486b6e  8b4614               mov eax, dword ptr [esi + 0x14]
// 00486b71  2bc2                 sub eax, edx
// 00486b73  c1f803               sar eax, 3
// 00486b76  8bc8                 mov ecx, eax
// 00486b78  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00486b7b  85ff                 test edi, edi
// 00486b7d  0f84ea010000         je 0x486d6d
// 00486b83  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00486b86  8bc3                 mov eax, ebx
// 00486b88  2bc2                 sub eax, edx
// 00486b8a  c1f803               sar eax, 3
// 00486b8d  baffffff1f           mov edx, 0x1fffffff
// 00486b92  2bd0                 sub edx, eax
// 00486b94  3bd7                 cmp edx, edi
// 00486b96  7305                 jae 0x486b9d
// 00486b98  e8c3970000           call 0x490360
// 00486b9d  8d1438               lea edx, [eax + edi]
// 00486ba0  3bca                 cmp ecx, edx
// 00486ba2  0f83f9000000         jae 0x486ca1
// 00486ba8  8bc1                 mov eax, ecx
// 00486baa  d1e8                 shr eax, 1
// 00486bac  bbffffff1f           mov ebx, 0x1fffffff
// 00486bb1  2bd8                 sub ebx, eax
// 00486bb3  3bd9                 cmp ebx, ecx
// 00486bb5  730c                 jae 0x486bc3
// 00486bb7  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00486bbe  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00486bc1  eb05                 jmp 0x486bc8
// 00486bc3  03c8                 add ecx, eax
// 00486bc5  894dec               mov dword ptr [ebp - 0x14], ecx
// 00486bc8  3bca                 cmp ecx, edx
// 00486bca  7305                 jae 0x486bd1
// 00486bcc  8955ec               mov dword ptr [ebp - 0x14], edx
// 00486bcf  8bca                 mov ecx, edx
// 00486bd1  6a00                 push 0
// 00486bd3  51                   push ecx
// 00486bd4  e817e3ffff           call 0x484ef0
// 00486bd9  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00486bdc  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 00486bdf  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00486be2  83c408               add esp, 8
// 00486be5  51                   push ecx
// 00486be6  c1fb03               sar ebx, 3
// 00486be9  57                   push edi
// 00486bea  8d14d8               lea edx, [eax + ebx*8]
// 00486bed  52                   push edx
// 00486bee  8bce                 mov ecx, esi
// 00486bf0  894510               mov dword ptr [ebp + 0x10], eax
// 00486bf3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00486bfa  e871fbffff           call 0x486770
// 00486bff  8b460c               mov eax, dword ptr [esi + 0xc]
// 00486c02  c6451400             mov byte ptr [ebp + 0x14], 0
// 00486c06  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00486c09  52                   push edx
// 00486c0a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00486c0d  52                   push edx
// 00486c0e  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00486c11  8d4e08               lea ecx, [esi + 8]
// 00486c14  51                   push ecx
// 00486c15  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00486c18  51                   push ecx
// 00486c19  52                   push edx
// 00486c1a  50                   push eax
// 00486c1b  e880f2ffff           call 0x485ea0
// 00486c20  8b4610               mov eax, dword ptr [esi + 0x10]
// 00486c23  83c418               add esp, 0x18
// 00486c26  c6451400             mov byte ptr [ebp + 0x14], 0
// 00486c2a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00486c2d  52                   push edx
// 00486c2e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00486c31  52                   push edx
// 00486c32  8d0c3b               lea ecx, [ebx + edi]
// 00486c35  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 00486c38  8d5608               lea edx, [esi + 8]
// 00486c3b  52                   push edx
// 00486c3c  8d0ccb               lea ecx, [ebx + ecx*8]
// 00486c3f  51                   push ecx
// 00486c40  50                   push eax
// 00486c41  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00486c44  50                   push eax
// 00486c45  e856f2ffff           call 0x485ea0
// 00486c4a  8b460c               mov eax, dword ptr [esi + 0xc]
// 00486c4d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00486c50  2bc8                 sub ecx, eax
// 00486c52  c1f903               sar ecx, 3
// 00486c55  83c418               add esp, 0x18
// 00486c58  03f9                 add edi, ecx
// 00486c5a  85c0                 test eax, eax
// 00486c5c  7409                 je 0x486c67
// 00486c5e  50                   push eax
// 00486c5f  e8ce1d2900           call 0x718a32
// 00486c64  83c404               add esp, 4
// 00486c67  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00486c6a  8d04d3               lea eax, [ebx + edx*8]
// 00486c6d  8d0cfb               lea ecx, [ebx + edi*8]
// 00486c70  894614               mov dword ptr [esi + 0x14], eax
// 00486c73  894e10               mov dword ptr [esi + 0x10], ecx
// 00486c76  895e0c               mov dword ptr [esi + 0xc], ebx
// 00486c79  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00486c7c  64890d00000000       mov dword ptr fs:[0], ecx
// 00486c83  5f                   pop edi
// 00486c84  5e                   pop esi
// 00486c85  5b                   pop ebx
// 00486c86  8be5                 mov esp, ebp
// 00486c88  5d                   pop ebp
// 00486c89  c21000               ret 0x10
// standard library vector<pod8> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
