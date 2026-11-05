// from server: 100% by auto
// roc 2007-08 005390b0  unit: RBX::VScriptContext::?$FactoryProduct  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005390b0
//
// 005390b0  55                   push ebp
// 005390b1  8bec                 mov ebp, esp
// 005390b3  6aff                 push -1
// 005390b5  68c00b7500           push 0x750bc0
// 005390ba  64a100000000         mov eax, dword ptr fs:[0]
// 005390c0  50                   push eax
// 005390c1  64892500000000       mov dword ptr fs:[0], esp
// 005390c8  83ec0c               sub esp, 0xc
// 005390cb  53                   push ebx
// 005390cc  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005390cf  8b4304               mov eax, dword ptr [ebx + 4]
// 005390d2  56                   push esi
// 005390d3  8bf1                 mov esi, ecx
// 005390d5  33c9                 xor ecx, ecx
// 005390d7  3bc1                 cmp eax, ecx
// 005390d9  57                   push edi
// 005390da  8965f0               mov dword ptr [ebp - 0x10], esp
// 005390dd  8975e8               mov dword ptr [ebp - 0x18], esi
// 005390e0  7504                 jne 0x5390e6
// 005390e2  33ff                 xor edi, edi
// 005390e4  eb08                 jmp 0x5390ee
// 005390e6  8b7b08               mov edi, dword ptr [ebx + 8]
// 005390e9  2bf8                 sub edi, eax
// 005390eb  c1ff03               sar edi, 3
// 005390ee  3bf9                 cmp edi, ecx
// 005390f0  894e04               mov dword ptr [esi + 4], ecx
// 005390f3  894e08               mov dword ptr [esi + 8], ecx
// 005390f6  894e0c               mov dword ptr [esi + 0xc], ecx
// 005390f9  746a                 je 0x539165
// 005390fb  81ffffffff1f         cmp edi, 0x1fffffff
// 00539101  7605                 jbe 0x539108
// 00539103  e8f8e6edff           call 0x417800
// 00539108  51                   push ecx
// 00539109  57                   push edi
// 0053910a  e8b1e90200           call 0x567ac0
// 0053910f  894604               mov dword ptr [esi + 4], eax
// 00539112  894608               mov dword ptr [esi + 8], eax
// 00539115  8d04f8               lea eax, [eax + edi*8]
// 00539118  89460c               mov dword ptr [esi + 0xc], eax
// 0053911b  8b4308               mov eax, dword ptr [ebx + 8]
// 0053911e  83c408               add esp, 8
// 00539121  394304               cmp dword ptr [ebx + 4], eax
// 00539124  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0053912b  8945ec               mov dword ptr [ebp - 0x14], eax
// 0053912e  7606                 jbe 0x539136
// 00539130  ff15d8e67700         call dword ptr [0x77e6d8]
// 00539136  8b7b04               mov edi, dword ptr [ebx + 4]
// 00539139  3b7b08               cmp edi, dword ptr [ebx + 8]
// 0053913c  7606                 jbe 0x539144
// 0053913e  ff15d8e67700         call dword ptr [0x77e6d8]
// 00539144  8b4604               mov eax, dword ptr [esi + 4]
// 00539147  c6450800             mov byte ptr [ebp + 8], 0
// 0053914b  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053914e  8b5508               mov edx, dword ptr [ebp + 8]
// 00539151  51                   push ecx
// 00539152  52                   push edx
// 00539153  56                   push esi
// 00539154  50                   push eax
// 00539155  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00539158  50                   push eax
// 00539159  57                   push edi
// 0053915a  e8f1e4ffff           call 0x537650
// 0053915f  83c418               add esp, 0x18
// 00539162  894608               mov dword ptr [esi + 8], eax
// 00539165  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00539168  5f                   pop edi
// 00539169  8bc6                 mov eax, esi
// 0053916b  5e                   pop esi
// 0053916c  64890d00000000       mov dword ptr fs:[0], ecx
// 00539173  5b                   pop ebx
// 00539174  8be5                 mov esp, ebp
// 00539176  5d                   pop ebp
// 00539177  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
