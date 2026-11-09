// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 0065af80  unit: RBX::BallBallContact  size: 305 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065af80
//
// 0065af80  55                   push ebp
// 0065af81  8bec                 mov ebp, esp
// 0065af83  6aff                 push -1
// 0065af85  6850bf7d00           push 0x7dbf50
// 0065af8a  64a100000000         mov eax, dword ptr fs:[0]
// 0065af90  50                   push eax
// 0065af91  64892500000000       mov dword ptr fs:[0], esp
// 0065af98  83ec10               sub esp, 0x10
// 0065af9b  53                   push ebx
// 0065af9c  56                   push esi
// 0065af9d  8bf1                 mov esi, ecx
// 0065af9f  8b560c               mov edx, dword ptr [esi + 0xc]
// 0065afa2  57                   push edi
// 0065afa3  8965f0               mov dword ptr [ebp - 0x10], esp
// 0065afa6  85d2                 test edx, edx
// 0065afa8  7504                 jne 0x65afae
// 0065afaa  33c9                 xor ecx, ecx
// 0065afac  eb0a                 jmp 0x65afb8
// 0065afae  8b4614               mov eax, dword ptr [esi + 0x14]
// 0065afb1  2bc2                 sub eax, edx
// 0065afb3  c1f803               sar eax, 3
// 0065afb6  8bc8                 mov ecx, eax
// 0065afb8  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 0065afbb  85db                 test ebx, ebx
// 0065afbd  0f84cf010000         je 0x65b192
// 0065afc3  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0065afc6  8bc7                 mov eax, edi
// 0065afc8  2bc2                 sub eax, edx
// 0065afca  c1f803               sar eax, 3
// 0065afcd  baffffff1f           mov edx, 0x1fffffff
// 0065afd2  2bd0                 sub edx, eax
// 0065afd4  3bd3                 cmp edx, ebx
// 0065afd6  7305                 jae 0x65afdd
// 0065afd8  e863bde6ff           call 0x4c6d40
// 0065afdd  8d1418               lea edx, [eax + ebx]
// 0065afe0  3bca                 cmp ecx, edx
// 0065afe2  0f83de000000         jae 0x65b0c6
// 0065afe8  8bc1                 mov eax, ecx
// 0065afea  d1e8                 shr eax, 1
// 0065afec  bfffffff1f           mov edi, 0x1fffffff
// 0065aff1  2bf8                 sub edi, eax
// 0065aff3  3bf9                 cmp edi, ecx
// 0065aff5  730c                 jae 0x65b003
// 0065aff7  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 0065affe  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0065b001  eb05                 jmp 0x65b008
// 0065b003  03c8                 add ecx, eax
// 0065b005  894dec               mov dword ptr [ebp - 0x14], ecx
// 0065b008  3bca                 cmp ecx, edx
// 0065b00a  7305                 jae 0x65b011
// 0065b00c  8955ec               mov dword ptr [ebp - 0x14], edx
// 0065b00f  8bca                 mov ecx, edx
// 0065b011  6a00                 push 0
// 0065b013  51                   push ecx
// 0065b014  e8274d0100           call 0x66fd40
// 0065b019  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0065b01c  c645e800             mov byte ptr [ebp - 0x18], 0
// 0065b020  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 0065b023  52                   push edx
// 0065b024  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0065b027  52                   push edx
// 0065b028  8d7e08               lea edi, [esi + 8]
// 0065b02b  57                   push edi
// 0065b02c  50                   push eax
// 0065b02d  894510               mov dword ptr [ebp + 0x10], eax
// 0065b030  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0065b033  50                   push eax
// 0065b034  51                   push ecx
// 0065b035  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0065b03c  e81fefffff           call 0x659f60
// 0065b041  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0065b044  83c420               add esp, 0x20
// 0065b047  51                   push ecx
// 0065b048  53                   push ebx
// 0065b049  50                   push eax
// 0065b04a  8bce                 mov ecx, esi
// 0065b04c  e8cffbffff           call 0x65ac20
// 0065b051  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0065b054  c6451400             mov byte ptr [ebp + 0x14], 0
// 0065b058  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0065b05b  52                   push edx
// 0065b05c  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0065b05f  52                   push edx
// 0065b060  57                   push edi
// 0065b061  50                   push eax
// 0065b062  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0065b065  51                   push ecx
// 0065b066  50                   push eax
// 0065b067  e8f4eeffff           call 0x659f60
// 0065b06c  8b460c               mov eax, dword ptr [esi + 0xc]
// 0065b06f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0065b072  2bc8                 sub ecx, eax
// 0065b074  c1f903               sar ecx, 3
// 0065b077  83c418               add esp, 0x18
// 0065b07a  03d9                 add ebx, ecx
// 0065b07c  85c0                 test eax, eax
// 0065b07e  7409                 je 0x65b089
// 0065b080  50                   push eax
// 0065b081  e8f4550400           call 0x6a067a
// 0065b086  83c404               add esp, 4
// 0065b089  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0065b08c  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0065b08f  8d0cd0               lea ecx, [eax + edx*8]
// 0065b092  8d14d8               lea edx, [eax + ebx*8]
// 0065b095  894e14               mov dword ptr [esi + 0x14], ecx
// 0065b098  895610               mov dword ptr [esi + 0x10], edx
// 0065b09b  89460c               mov dword ptr [esi + 0xc], eax
// 0065b09e  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0065b0a1  64890d00000000       mov dword ptr fs:[0], ecx
// 0065b0a8  5f                   pop edi
// 0065b0a9  5e                   pop esi
// 0065b0aa  5b                   pop ebx
// 0065b0ab  8be5                 mov esp, ebp
// 0065b0ad  5d                   pop ebp
// 0065b0ae  c21000               ret 0x10
// standard library vector<pod8> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
