// from server: 100% by auto
// roc 2010-06 004e3b90  unit: RBX::Network::IdSerializer  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e3b90
//
// 004e3b90  55                   push ebp
// 004e3b91  8bec                 mov ebp, esp
// 004e3b93  6aff                 push -1
// 004e3b95  6888bb9800           push 0x98bb88
// 004e3b9a  64a100000000         mov eax, dword ptr fs:[0]
// 004e3ba0  50                   push eax
// 004e3ba1  64892500000000       mov dword ptr fs:[0], esp
// 004e3ba8  83ec0c               sub esp, 0xc
// 004e3bab  53                   push ebx
// 004e3bac  56                   push esi
// 004e3bad  57                   push edi
// 004e3bae  8965f0               mov dword ptr [ebp - 0x10], esp
// 004e3bb1  8bf1                 mov esi, ecx
// 004e3bb3  6a04                 push 4
// 004e3bb5  8975e8               mov dword ptr [ebp - 0x18], esi
// 004e3bb8  e8e33d2c00           call 0x7a79a0
// 004e3bbd  83c404               add esp, 4
// 004e3bc0  85c0                 test eax, eax
// 004e3bc2  7404                 je 0x4e3bc8
// 004e3bc4  8930                 mov dword ptr [eax], esi
// 004e3bc6  eb02                 jmp 0x4e3bca
// 004e3bc8  33c0                 xor eax, eax
// 004e3bca  8906                 mov dword ptr [esi], eax
// 004e3bcc  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004e3bcf  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004e3bd2  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 004e3bd5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004e3bda  f7e9                 imul ecx
// 004e3bdc  d1fa                 sar edx, 1
// 004e3bde  8bfa                 mov edi, edx
// 004e3be0  b800000000           mov eax, 0
// 004e3be5  c1ef1f               shr edi, 0x1f
// 004e3be8  03fa                 add edi, edx
// 004e3bea  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004e3bf1  89460c               mov dword ptr [esi + 0xc], eax
// 004e3bf4  894610               mov dword ptr [esi + 0x10], eax
// 004e3bf7  894614               mov dword ptr [esi + 0x14], eax
// 004e3bfa  746d                 je 0x4e3c69
// 004e3bfc  81ff55555515         cmp edi, 0x15555555
// 004e3c02  7605                 jbe 0x4e3c09
// 004e3c04  e8e701f4ff           call 0x423df0
// 004e3c09  50                   push eax
// 004e3c0a  57                   push edi
// 004e3c0b  e880ae4000           call 0x8eea90
// 004e3c10  8d0c7f               lea ecx, [edi + edi*2]
// 004e3c13  8d1488               lea edx, [eax + ecx*4]
// 004e3c16  89460c               mov dword ptr [esi + 0xc], eax
// 004e3c19  894610               mov dword ptr [esi + 0x10], eax
// 004e3c1c  895614               mov dword ptr [esi + 0x14], edx
// 004e3c1f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004e3c22  83c408               add esp, 8
// 004e3c25  c645fc01             mov byte ptr [ebp - 4], 1
// 004e3c29  8945ec               mov dword ptr [ebp - 0x14], eax
// 004e3c2c  39430c               cmp dword ptr [ebx + 0xc], eax
// 004e3c2f  7606                 jbe 0x4e3c37
// 004e3c31  ff150ca99e00         call dword ptr [0x9ea90c]
// 004e3c37  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 004e3c3a  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 004e3c3d  7606                 jbe 0x4e3c45
// 004e3c3f  ff150ca99e00         call dword ptr [0x9ea90c]
// 004e3c45  8b460c               mov eax, dword ptr [esi + 0xc]
// 004e3c48  c6450800             mov byte ptr [ebp + 8], 0
// 004e3c4c  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004e3c4f  8b5508               mov edx, dword ptr [ebp + 8]
// 004e3c52  51                   push ecx
// 004e3c53  52                   push edx
// 004e3c54  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004e3c57  8d4e08               lea ecx, [esi + 8]
// 004e3c5a  51                   push ecx
// 004e3c5b  50                   push eax
// 004e3c5c  52                   push edx
// 004e3c5d  57                   push edi
// 004e3c5e  e8adefffff           call 0x4e2c10
// 004e3c63  83c418               add esp, 0x18
// 004e3c66  894610               mov dword ptr [esi + 0x10], eax
// 004e3c69  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004e3c6c  5f                   pop edi
// 004e3c6d  8bc6                 mov eax, esi
// 004e3c6f  5e                   pop esi
// 004e3c70  64890d00000000       mov dword ptr fs:[0], ecx
// 004e3c77  5b                   pop ebx
// 004e3c78  8be5                 mov esp, ebp
// 004e3c7a  5d                   pop ebp
// 004e3c7b  c20400               ret 4
// standard library vector<pod12> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
