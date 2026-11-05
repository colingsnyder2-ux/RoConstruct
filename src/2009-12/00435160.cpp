// from server: 100% by auto
// roc 2009-12 00435160  unit: IIHAAH::?$CMap  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00435160
//
// 00435160  55                   push ebp
// 00435161  8bec                 mov ebp, esp
// 00435163  6aff                 push -1
// 00435165  6808a09200           push 0x92a008
// 0043516a  64a100000000         mov eax, dword ptr fs:[0]
// 00435170  50                   push eax
// 00435171  64892500000000       mov dword ptr fs:[0], esp
// 00435178  83ec0c               sub esp, 0xc
// 0043517b  53                   push ebx
// 0043517c  56                   push esi
// 0043517d  57                   push edi
// 0043517e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00435181  8bf1                 mov esi, ecx
// 00435183  6a04                 push 4
// 00435185  8975e8               mov dword ptr [ebp - 0x18], esi
// 00435188  e8d3e63b00           call 0x7f3860
// 0043518d  33c9                 xor ecx, ecx
// 0043518f  83c404               add esp, 4
// 00435192  3bc1                 cmp eax, ecx
// 00435194  7404                 je 0x43519a
// 00435196  8930                 mov dword ptr [eax], esi
// 00435198  eb02                 jmp 0x43519c
// 0043519a  33c0                 xor eax, eax
// 0043519c  8906                 mov dword ptr [esi], eax
// 0043519e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004351a1  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 004351a4  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 004351a7  894dfc               mov dword ptr [ebp - 4], ecx
// 004351aa  c1ff03               sar edi, 3
// 004351ad  894e0c               mov dword ptr [esi + 0xc], ecx
// 004351b0  894e10               mov dword ptr [esi + 0x10], ecx
// 004351b3  894e14               mov dword ptr [esi + 0x14], ecx
// 004351b6  3bf9                 cmp edi, ecx
// 004351b8  746a                 je 0x435224
// 004351ba  81ffffffff1f         cmp edi, 0x1fffffff
// 004351c0  7605                 jbe 0x4351c7
// 004351c2  e899cf0000           call 0x442160
// 004351c7  51                   push ecx
// 004351c8  57                   push edi
// 004351c9  e802691400           call 0x57bad0
// 004351ce  89460c               mov dword ptr [esi + 0xc], eax
// 004351d1  894610               mov dword ptr [esi + 0x10], eax
// 004351d4  8d04f8               lea eax, [eax + edi*8]
// 004351d7  894614               mov dword ptr [esi + 0x14], eax
// 004351da  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004351dd  83c408               add esp, 8
// 004351e0  c645fc01             mov byte ptr [ebp - 4], 1
// 004351e4  8945ec               mov dword ptr [ebp - 0x14], eax
// 004351e7  39430c               cmp dword ptr [ebx + 0xc], eax
// 004351ea  7606                 jbe 0x4351f2
// 004351ec  ff1560b79800         call dword ptr [0x98b760]
// 004351f2  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 004351f5  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 004351f8  7606                 jbe 0x435200
// 004351fa  ff1560b79800         call dword ptr [0x98b760]
// 00435200  8b460c               mov eax, dword ptr [esi + 0xc]
// 00435203  c6450800             mov byte ptr [ebp + 8], 0
// 00435207  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0043520a  8b5508               mov edx, dword ptr [ebp + 8]
// 0043520d  51                   push ecx
// 0043520e  52                   push edx
// 0043520f  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00435212  8d4e08               lea ecx, [esi + 8]
// 00435215  51                   push ecx
// 00435216  50                   push eax
// 00435217  52                   push edx
// 00435218  57                   push edi
// 00435219  e862ac3100           call 0x74fe80
// 0043521e  83c418               add esp, 0x18
// 00435221  894610               mov dword ptr [esi + 0x10], eax
// 00435224  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00435227  5f                   pop edi
// 00435228  8bc6                 mov eax, esi
// 0043522a  5e                   pop esi
// 0043522b  64890d00000000       mov dword ptr fs:[0], ecx
// 00435232  5b                   pop ebx
// 00435233  8be5                 mov esp, ebp
// 00435235  5d                   pop ebp
// 00435236  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
