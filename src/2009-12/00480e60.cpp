// from server: 100% by auto
// roc 2009-12 00480e60  unit: RBX::AdornRbxGfx  size: 332 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00480e60
//
// 00480e60  55                   push ebp
// 00480e61  8bec                 mov ebp, esp
// 00480e63  6aff                 push -1
// 00480e65  68b0eb9200           push 0x92ebb0
// 00480e6a  64a100000000         mov eax, dword ptr fs:[0]
// 00480e70  50                   push eax
// 00480e71  64892500000000       mov dword ptr fs:[0], esp
// 00480e78  83ec0c               sub esp, 0xc
// 00480e7b  53                   push ebx
// 00480e7c  56                   push esi
// 00480e7d  8bf1                 mov esi, ecx
// 00480e7f  8b560c               mov edx, dword ptr [esi + 0xc]
// 00480e82  57                   push edi
// 00480e83  8965f0               mov dword ptr [ebp - 0x10], esp
// 00480e86  85d2                 test edx, edx
// 00480e88  7504                 jne 0x480e8e
// 00480e8a  33c9                 xor ecx, ecx
// 00480e8c  eb0a                 jmp 0x480e98
// 00480e8e  8b4614               mov eax, dword ptr [esi + 0x14]
// 00480e91  2bc2                 sub eax, edx
// 00480e93  c1f803               sar eax, 3
// 00480e96  8bc8                 mov ecx, eax
// 00480e98  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00480e9b  85ff                 test edi, edi
// 00480e9d  0f84ea010000         je 0x48108d
// 00480ea3  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00480ea6  8bc3                 mov eax, ebx
// 00480ea8  2bc2                 sub eax, edx
// 00480eaa  c1f803               sar eax, 3
// 00480ead  baffffff1f           mov edx, 0x1fffffff
// 00480eb2  2bd0                 sub edx, eax
// 00480eb4  3bd7                 cmp edx, edi
// 00480eb6  7305                 jae 0x480ebd
// 00480eb8  e8a312fcff           call 0x442160
// 00480ebd  8d1438               lea edx, [eax + edi]
// 00480ec0  3bca                 cmp ecx, edx
// 00480ec2  0f83f9000000         jae 0x480fc1
// 00480ec8  8bc1                 mov eax, ecx
// 00480eca  d1e8                 shr eax, 1
// 00480ecc  bbffffff1f           mov ebx, 0x1fffffff
// 00480ed1  2bd8                 sub ebx, eax
// 00480ed3  3bd9                 cmp ebx, ecx
// 00480ed5  730c                 jae 0x480ee3
// 00480ed7  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00480ede  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00480ee1  eb05                 jmp 0x480ee8
// 00480ee3  03c8                 add ecx, eax
// 00480ee5  894dec               mov dword ptr [ebp - 0x14], ecx
// 00480ee8  3bca                 cmp ecx, edx
// 00480eea  7305                 jae 0x480ef1
// 00480eec  8955ec               mov dword ptr [ebp - 0x14], edx
// 00480eef  8bca                 mov ecx, edx
// 00480ef1  6a00                 push 0
// 00480ef3  51                   push ecx
// 00480ef4  e8d7ab0f00           call 0x57bad0
// 00480ef9  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00480efc  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 00480eff  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00480f02  83c408               add esp, 8
// 00480f05  51                   push ecx
// 00480f06  c1fb03               sar ebx, 3
// 00480f09  57                   push edi
// 00480f0a  8d14d8               lea edx, [eax + ebx*8]
// 00480f0d  52                   push edx
// 00480f0e  8bce                 mov ecx, esi
// 00480f10  894510               mov dword ptr [ebp + 0x10], eax
// 00480f13  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00480f1a  e811f7ffff           call 0x480630
// 00480f1f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00480f22  c6451400             mov byte ptr [ebp + 0x14], 0
// 00480f26  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00480f29  52                   push edx
// 00480f2a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00480f2d  52                   push edx
// 00480f2e  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00480f31  8d4e08               lea ecx, [esi + 8]
// 00480f34  51                   push ecx
// 00480f35  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00480f38  51                   push ecx
// 00480f39  52                   push edx
// 00480f3a  50                   push eax
// 00480f3b  e8e09d0200           call 0x4aad20
// 00480f40  8b4610               mov eax, dword ptr [esi + 0x10]
// 00480f43  83c418               add esp, 0x18
// 00480f46  c6451400             mov byte ptr [ebp + 0x14], 0
// 00480f4a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00480f4d  52                   push edx
// 00480f4e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00480f51  52                   push edx
// 00480f52  8d0c3b               lea ecx, [ebx + edi]
// 00480f55  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 00480f58  8d5608               lea edx, [esi + 8]
// 00480f5b  52                   push edx
// 00480f5c  8d0ccb               lea ecx, [ebx + ecx*8]
// 00480f5f  51                   push ecx
// 00480f60  50                   push eax
// 00480f61  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00480f64  50                   push eax
// 00480f65  e8b69d0200           call 0x4aad20
// 00480f6a  8b460c               mov eax, dword ptr [esi + 0xc]
// 00480f6d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00480f70  2bc8                 sub ecx, eax
// 00480f72  c1f903               sar ecx, 3
// 00480f75  83c418               add esp, 0x18
// 00480f78  03f9                 add edi, ecx
// 00480f7a  85c0                 test eax, eax
// 00480f7c  7409                 je 0x480f87
// 00480f7e  50                   push eax
// 00480f7f  e8d6283700           call 0x7f385a
// 00480f84  83c404               add esp, 4
// 00480f87  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00480f8a  8d04d3               lea eax, [ebx + edx*8]
// 00480f8d  8d0cfb               lea ecx, [ebx + edi*8]
// 00480f90  894614               mov dword ptr [esi + 0x14], eax
// 00480f93  894e10               mov dword ptr [esi + 0x10], ecx
// 00480f96  895e0c               mov dword ptr [esi + 0xc], ebx
// 00480f99  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00480f9c  64890d00000000       mov dword ptr fs:[0], ecx
// 00480fa3  5f                   pop edi
// 00480fa4  5e                   pop esi
// 00480fa5  5b                   pop ebx
// 00480fa6  8be5                 mov esp, ebp
// 00480fa8  5d                   pop ebp
// 00480fa9  c21000               ret 0x10
// standard library vector<pod8> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
