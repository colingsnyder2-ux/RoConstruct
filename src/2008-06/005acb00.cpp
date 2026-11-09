// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 005acb00  unit: RBX::Reflection::Z::$$A6AXM::?$TSignalDesc::TSignalInstance  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005acb00
//
// 005acb00  55                   push ebp
// 005acb01  8bec                 mov ebp, esp
// 005acb03  6aff                 push -1
// 005acb05  6828327d00           push 0x7d3228
// 005acb0a  64a100000000         mov eax, dword ptr fs:[0]
// 005acb10  50                   push eax
// 005acb11  64892500000000       mov dword ptr fs:[0], esp
// 005acb18  83ec0c               sub esp, 0xc
// 005acb1b  53                   push ebx
// 005acb1c  56                   push esi
// 005acb1d  57                   push edi
// 005acb1e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005acb21  8bf1                 mov esi, ecx
// 005acb23  6a04                 push 4
// 005acb25  8975e8               mov dword ptr [ebp - 0x18], esi
// 005acb28  e8f33d0f00           call 0x6a0920
// 005acb2d  33c9                 xor ecx, ecx
// 005acb2f  83c404               add esp, 4
// 005acb32  3bc1                 cmp eax, ecx
// 005acb34  7404                 je 0x5acb3a
// 005acb36  8930                 mov dword ptr [eax], esi
// 005acb38  eb02                 jmp 0x5acb3c
// 005acb3a  33c0                 xor eax, eax
// 005acb3c  8906                 mov dword ptr [esi], eax
// 005acb3e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005acb41  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 005acb44  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 005acb47  894dfc               mov dword ptr [ebp - 4], ecx
// 005acb4a  c1ff03               sar edi, 3
// 005acb4d  894e0c               mov dword ptr [esi + 0xc], ecx
// 005acb50  894e10               mov dword ptr [esi + 0x10], ecx
// 005acb53  894e14               mov dword ptr [esi + 0x14], ecx
// 005acb56  3bf9                 cmp edi, ecx
// 005acb58  746a                 je 0x5acbc4
// 005acb5a  81ffffffff1f         cmp edi, 0x1fffffff
// 005acb60  7605                 jbe 0x5acb67
// 005acb62  e8d9a1f1ff           call 0x4c6d40
// 005acb67  51                   push ecx
// 005acb68  57                   push edi
// 005acb69  e8d2310c00           call 0x66fd40
// 005acb6e  89460c               mov dword ptr [esi + 0xc], eax
// 005acb71  894610               mov dword ptr [esi + 0x10], eax
// 005acb74  8d04f8               lea eax, [eax + edi*8]
// 005acb77  894614               mov dword ptr [esi + 0x14], eax
// 005acb7a  8b4310               mov eax, dword ptr [ebx + 0x10]
// 005acb7d  83c408               add esp, 8
// 005acb80  c645fc01             mov byte ptr [ebp - 4], 1
// 005acb84  8945ec               mov dword ptr [ebp - 0x14], eax
// 005acb87  39430c               cmp dword ptr [ebx + 0xc], eax
// 005acb8a  7606                 jbe 0x5acb92
// 005acb8c  ff1590288000         call dword ptr [0x802890]
// 005acb92  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 005acb95  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 005acb98  7606                 jbe 0x5acba0
// 005acb9a  ff1590288000         call dword ptr [0x802890]
// 005acba0  8b460c               mov eax, dword ptr [esi + 0xc]
// 005acba3  c6450800             mov byte ptr [ebp + 8], 0
// 005acba7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005acbaa  8b5508               mov edx, dword ptr [ebp + 8]
// 005acbad  51                   push ecx
// 005acbae  52                   push edx
// 005acbaf  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 005acbb2  8d4e08               lea ecx, [esi + 8]
// 005acbb5  51                   push ecx
// 005acbb6  50                   push eax
// 005acbb7  52                   push edx
// 005acbb8  57                   push edi
// 005acbb9  e8a2bfe8ff           call 0x438b60
// 005acbbe  83c418               add esp, 0x18
// 005acbc1  894610               mov dword ptr [esi + 0x10], eax
// 005acbc4  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005acbc7  5f                   pop edi
// 005acbc8  8bc6                 mov eax, esi
// 005acbca  5e                   pop esi
// 005acbcb  64890d00000000       mov dword ptr fs:[0], ecx
// 005acbd2  5b                   pop ebx
// 005acbd3  8be5                 mov esp, ebp
// 005acbd5  5d                   pop ebp
// 005acbd6  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
