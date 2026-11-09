// from server: 100% by auto
// roc 2009-06 006b29a0  unit: RBX::BlockBlockContact  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b29a0
//
// 006b29a0  55                   push ebp
// 006b29a1  8bec                 mov ebp, esp
// 006b29a3  6aff                 push -1
// 006b29a5  6878048700           push 0x870478
// 006b29aa  64a100000000         mov eax, dword ptr fs:[0]
// 006b29b0  50                   push eax
// 006b29b1  64892500000000       mov dword ptr fs:[0], esp
// 006b29b8  83ec0c               sub esp, 0xc
// 006b29bb  53                   push ebx
// 006b29bc  56                   push esi
// 006b29bd  57                   push edi
// 006b29be  8965f0               mov dword ptr [ebp - 0x10], esp
// 006b29c1  8bf1                 mov esi, ecx
// 006b29c3  6a04                 push 4
// 006b29c5  8975e8               mov dword ptr [ebp - 0x18], esi
// 006b29c8  e86b600600           call 0x718a38
// 006b29cd  33c9                 xor ecx, ecx
// 006b29cf  83c404               add esp, 4
// 006b29d2  3bc1                 cmp eax, ecx
// 006b29d4  7404                 je 0x6b29da
// 006b29d6  8930                 mov dword ptr [eax], esi
// 006b29d8  eb02                 jmp 0x6b29dc
// 006b29da  33c0                 xor eax, eax
// 006b29dc  8906                 mov dword ptr [esi], eax
// 006b29de  8b5d08               mov ebx, dword ptr [ebp + 8]
// 006b29e1  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 006b29e4  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 006b29e7  894dfc               mov dword ptr [ebp - 4], ecx
// 006b29ea  c1ff03               sar edi, 3
// 006b29ed  894e0c               mov dword ptr [esi + 0xc], ecx
// 006b29f0  894e10               mov dword ptr [esi + 0x10], ecx
// 006b29f3  894e14               mov dword ptr [esi + 0x14], ecx
// 006b29f6  3bf9                 cmp edi, ecx
// 006b29f8  746a                 je 0x6b2a64
// 006b29fa  81ffffffff1f         cmp edi, 0x1fffffff
// 006b2a00  7605                 jbe 0x6b2a07
// 006b2a02  e859d9ddff           call 0x490360
// 006b2a07  51                   push ecx
// 006b2a08  57                   push edi
// 006b2a09  e8e224ddff           call 0x484ef0
// 006b2a0e  89460c               mov dword ptr [esi + 0xc], eax
// 006b2a11  894610               mov dword ptr [esi + 0x10], eax
// 006b2a14  8d04f8               lea eax, [eax + edi*8]
// 006b2a17  894614               mov dword ptr [esi + 0x14], eax
// 006b2a1a  8b4310               mov eax, dword ptr [ebx + 0x10]
// 006b2a1d  83c408               add esp, 8
// 006b2a20  c645fc01             mov byte ptr [ebp - 4], 1
// 006b2a24  8945ec               mov dword ptr [ebp - 0x14], eax
// 006b2a27  39430c               cmp dword ptr [ebx + 0xc], eax
// 006b2a2a  7606                 jbe 0x6b2a32
// 006b2a2c  ff15ace98900         call dword ptr [0x89e9ac]
// 006b2a32  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 006b2a35  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 006b2a38  7606                 jbe 0x6b2a40
// 006b2a3a  ff15ace98900         call dword ptr [0x89e9ac]
// 006b2a40  8b460c               mov eax, dword ptr [esi + 0xc]
// 006b2a43  c6450800             mov byte ptr [ebp + 8], 0
// 006b2a47  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006b2a4a  8b5508               mov edx, dword ptr [ebp + 8]
// 006b2a4d  51                   push ecx
// 006b2a4e  52                   push edx
// 006b2a4f  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 006b2a52  8d4e08               lea ecx, [esi + 8]
// 006b2a55  51                   push ecx
// 006b2a56  50                   push eax
// 006b2a57  52                   push edx
// 006b2a58  57                   push edi
// 006b2a59  e892a9faff           call 0x65d3f0
// 006b2a5e  83c418               add esp, 0x18
// 006b2a61  894610               mov dword ptr [esi + 0x10], eax
// 006b2a64  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006b2a67  5f                   pop edi
// 006b2a68  8bc6                 mov eax, esi
// 006b2a6a  5e                   pop esi
// 006b2a6b  64890d00000000       mov dword ptr fs:[0], ecx
// 006b2a72  5b                   pop ebx
// 006b2a73  8be5                 mov esp, ebp
// 006b2a75  5d                   pop ebp
// 006b2a76  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
