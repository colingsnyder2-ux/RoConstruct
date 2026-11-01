// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 0060e450  unit: RBX::BlockBlockContact  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060e450
//
// 0060e450  55                   push ebp
// 0060e451  8bec                 mov ebp, esp
// 0060e453  6aff                 push -1
// 0060e455  68f88c7d00           push 0x7d8cf8
// 0060e45a  64a100000000         mov eax, dword ptr fs:[0]
// 0060e460  50                   push eax
// 0060e461  64892500000000       mov dword ptr fs:[0], esp
// 0060e468  83ec0c               sub esp, 0xc
// 0060e46b  53                   push ebx
// 0060e46c  56                   push esi
// 0060e46d  57                   push edi
// 0060e46e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0060e471  8bf1                 mov esi, ecx
// 0060e473  6a04                 push 4
// 0060e475  8975e8               mov dword ptr [ebp - 0x18], esi
// 0060e478  e8a3240900           call 0x6a0920
// 0060e47d  33c9                 xor ecx, ecx
// 0060e47f  83c404               add esp, 4
// 0060e482  3bc1                 cmp eax, ecx
// 0060e484  7404                 je 0x60e48a
// 0060e486  8930                 mov dword ptr [eax], esi
// 0060e488  eb02                 jmp 0x60e48c
// 0060e48a  33c0                 xor eax, eax
// 0060e48c  8906                 mov dword ptr [esi], eax
// 0060e48e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0060e491  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 0060e494  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 0060e497  894dfc               mov dword ptr [ebp - 4], ecx
// 0060e49a  c1ff03               sar edi, 3
// 0060e49d  894e0c               mov dword ptr [esi + 0xc], ecx
// 0060e4a0  894e10               mov dword ptr [esi + 0x10], ecx
// 0060e4a3  894e14               mov dword ptr [esi + 0x14], ecx
// 0060e4a6  3bf9                 cmp edi, ecx
// 0060e4a8  746a                 je 0x60e514
// 0060e4aa  81ffffffff1f         cmp edi, 0x1fffffff
// 0060e4b0  7605                 jbe 0x60e4b7
// 0060e4b2  e88988ebff           call 0x4c6d40
// 0060e4b7  51                   push ecx
// 0060e4b8  57                   push edi
// 0060e4b9  e882180600           call 0x66fd40
// 0060e4be  89460c               mov dword ptr [esi + 0xc], eax
// 0060e4c1  894610               mov dword ptr [esi + 0x10], eax
// 0060e4c4  8d04f8               lea eax, [eax + edi*8]
// 0060e4c7  894614               mov dword ptr [esi + 0x14], eax
// 0060e4ca  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0060e4cd  83c408               add esp, 8
// 0060e4d0  c645fc01             mov byte ptr [ebp - 4], 1
// 0060e4d4  8945ec               mov dword ptr [ebp - 0x14], eax
// 0060e4d7  39430c               cmp dword ptr [ebx + 0xc], eax
// 0060e4da  7606                 jbe 0x60e4e2
// 0060e4dc  ff1590288000         call dword ptr [0x802890]
// 0060e4e2  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 0060e4e5  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 0060e4e8  7606                 jbe 0x60e4f0
// 0060e4ea  ff1590288000         call dword ptr [0x802890]
// 0060e4f0  8b460c               mov eax, dword ptr [esi + 0xc]
// 0060e4f3  c6450800             mov byte ptr [ebp + 8], 0
// 0060e4f7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0060e4fa  8b5508               mov edx, dword ptr [ebp + 8]
// 0060e4fd  51                   push ecx
// 0060e4fe  52                   push edx
// 0060e4ff  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0060e502  8d4e08               lea ecx, [esi + 8]
// 0060e505  51                   push ecx
// 0060e506  50                   push eax
// 0060e507  52                   push edx
// 0060e508  57                   push edi
// 0060e509  e892c4f8ff           call 0x59a9a0
// 0060e50e  83c418               add esp, 0x18
// 0060e511  894610               mov dword ptr [esi + 0x10], eax
// 0060e514  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0060e517  5f                   pop edi
// 0060e518  8bc6                 mov eax, esi
// 0060e51a  5e                   pop esi
// 0060e51b  64890d00000000       mov dword ptr fs:[0], ecx
// 0060e522  5b                   pop ebx
// 0060e523  8be5                 mov esp, ebp
// 0060e525  5d                   pop ebp
// 0060e526  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
