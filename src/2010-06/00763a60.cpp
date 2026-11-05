// from server: 100% by auto
// roc 2010-06 00763a60  unit: RBX::Assembly  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00763a60
//
// 00763a60  55                   push ebp
// 00763a61  8bec                 mov ebp, esp
// 00763a63  6aff                 push -1
// 00763a65  68b8ba9a00           push 0x9abab8
// 00763a6a  64a100000000         mov eax, dword ptr fs:[0]
// 00763a70  50                   push eax
// 00763a71  64892500000000       mov dword ptr fs:[0], esp
// 00763a78  83ec0c               sub esp, 0xc
// 00763a7b  53                   push ebx
// 00763a7c  56                   push esi
// 00763a7d  57                   push edi
// 00763a7e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00763a81  8bf1                 mov esi, ecx
// 00763a83  6a04                 push 4
// 00763a85  8975e8               mov dword ptr [ebp - 0x18], esi
// 00763a88  e8133f0400           call 0x7a79a0
// 00763a8d  33c9                 xor ecx, ecx
// 00763a8f  83c404               add esp, 4
// 00763a92  3bc1                 cmp eax, ecx
// 00763a94  7404                 je 0x763a9a
// 00763a96  8930                 mov dword ptr [eax], esi
// 00763a98  eb02                 jmp 0x763a9c
// 00763a9a  33c0                 xor eax, eax
// 00763a9c  8906                 mov dword ptr [esi], eax
// 00763a9e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00763aa1  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 00763aa4  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 00763aa7  894dfc               mov dword ptr [ebp - 4], ecx
// 00763aaa  c1ff03               sar edi, 3
// 00763aad  894e0c               mov dword ptr [esi + 0xc], ecx
// 00763ab0  894e10               mov dword ptr [esi + 0x10], ecx
// 00763ab3  894e14               mov dword ptr [esi + 0x14], ecx
// 00763ab6  3bf9                 cmp edi, ecx
// 00763ab8  746a                 je 0x763b24
// 00763aba  81ffffffff1f         cmp edi, 0x1fffffff
// 00763ac0  7605                 jbe 0x763ac7
// 00763ac2  e82903ccff           call 0x423df0
// 00763ac7  51                   push ecx
// 00763ac8  57                   push edi
// 00763ac9  e8e2aa1900           call 0x8fe5b0
// 00763ace  89460c               mov dword ptr [esi + 0xc], eax
// 00763ad1  894610               mov dword ptr [esi + 0x10], eax
// 00763ad4  8d04f8               lea eax, [eax + edi*8]
// 00763ad7  894614               mov dword ptr [esi + 0x14], eax
// 00763ada  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00763add  83c408               add esp, 8
// 00763ae0  c645fc01             mov byte ptr [ebp - 4], 1
// 00763ae4  8945ec               mov dword ptr [ebp - 0x14], eax
// 00763ae7  39430c               cmp dword ptr [ebx + 0xc], eax
// 00763aea  7606                 jbe 0x763af2
// 00763aec  ff150ca99e00         call dword ptr [0x9ea90c]
// 00763af2  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 00763af5  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 00763af8  7606                 jbe 0x763b00
// 00763afa  ff150ca99e00         call dword ptr [0x9ea90c]
// 00763b00  8b460c               mov eax, dword ptr [esi + 0xc]
// 00763b03  c6450800             mov byte ptr [ebp + 8], 0
// 00763b07  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00763b0a  8b5508               mov edx, dword ptr [ebp + 8]
// 00763b0d  51                   push ecx
// 00763b0e  52                   push edx
// 00763b0f  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00763b12  8d4e08               lea ecx, [esi + 8]
// 00763b15  51                   push ecx
// 00763b16  50                   push eax
// 00763b17  52                   push edx
// 00763b18  57                   push edi
// 00763b19  e83204f8ff           call 0x6e3f50
// 00763b1e  83c418               add esp, 0x18
// 00763b21  894610               mov dword ptr [esi + 0x10], eax
// 00763b24  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00763b27  5f                   pop edi
// 00763b28  8bc6                 mov eax, esi
// 00763b2a  5e                   pop esi
// 00763b2b  64890d00000000       mov dword ptr fs:[0], ecx
// 00763b32  5b                   pop ebx
// 00763b33  8be5                 mov esp, ebp
// 00763b35  5d                   pop ebp
// 00763b36  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
