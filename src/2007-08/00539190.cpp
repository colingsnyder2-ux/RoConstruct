// from server: 100% by auto
// roc 2007-08 00539190  unit: RBX::VScriptContext::?$FactoryProduct  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00539190
//
// 00539190  55                   push ebp
// 00539191  8bec                 mov ebp, esp
// 00539193  6aff                 push -1
// 00539195  68d00b7500           push 0x750bd0
// 0053919a  64a100000000         mov eax, dword ptr fs:[0]
// 005391a0  50                   push eax
// 005391a1  64892500000000       mov dword ptr fs:[0], esp
// 005391a8  83ec0c               sub esp, 0xc
// 005391ab  53                   push ebx
// 005391ac  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005391af  8b4304               mov eax, dword ptr [ebx + 4]
// 005391b2  56                   push esi
// 005391b3  8bf1                 mov esi, ecx
// 005391b5  33c9                 xor ecx, ecx
// 005391b7  3bc1                 cmp eax, ecx
// 005391b9  57                   push edi
// 005391ba  8965f0               mov dword ptr [ebp - 0x10], esp
// 005391bd  8975e8               mov dword ptr [ebp - 0x18], esi
// 005391c0  7504                 jne 0x5391c6
// 005391c2  33ff                 xor edi, edi
// 005391c4  eb08                 jmp 0x5391ce
// 005391c6  8b7b08               mov edi, dword ptr [ebx + 8]
// 005391c9  2bf8                 sub edi, eax
// 005391cb  c1ff03               sar edi, 3
// 005391ce  3bf9                 cmp edi, ecx
// 005391d0  894e04               mov dword ptr [esi + 4], ecx
// 005391d3  894e08               mov dword ptr [esi + 8], ecx
// 005391d6  894e0c               mov dword ptr [esi + 0xc], ecx
// 005391d9  746a                 je 0x539245
// 005391db  81ffffffff1f         cmp edi, 0x1fffffff
// 005391e1  7605                 jbe 0x5391e8
// 005391e3  e8483b0900           call 0x5ccd30
// 005391e8  51                   push ecx
// 005391e9  57                   push edi
// 005391ea  e8d1e80200           call 0x567ac0
// 005391ef  894604               mov dword ptr [esi + 4], eax
// 005391f2  894608               mov dword ptr [esi + 8], eax
// 005391f5  8d04f8               lea eax, [eax + edi*8]
// 005391f8  89460c               mov dword ptr [esi + 0xc], eax
// 005391fb  8b4308               mov eax, dword ptr [ebx + 8]
// 005391fe  83c408               add esp, 8
// 00539201  394304               cmp dword ptr [ebx + 4], eax
// 00539204  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0053920b  8945ec               mov dword ptr [ebp - 0x14], eax
// 0053920e  7606                 jbe 0x539216
// 00539210  ff15d8e67700         call dword ptr [0x77e6d8]
// 00539216  8b7b04               mov edi, dword ptr [ebx + 4]
// 00539219  3b7b08               cmp edi, dword ptr [ebx + 8]
// 0053921c  7606                 jbe 0x539224
// 0053921e  ff15d8e67700         call dword ptr [0x77e6d8]
// 00539224  8b4604               mov eax, dword ptr [esi + 4]
// 00539227  c6450800             mov byte ptr [ebp + 8], 0
// 0053922b  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053922e  8b5508               mov edx, dword ptr [ebp + 8]
// 00539231  51                   push ecx
// 00539232  52                   push edx
// 00539233  56                   push esi
// 00539234  50                   push eax
// 00539235  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00539238  50                   push eax
// 00539239  57                   push edi
// 0053923a  e8c148edff           call 0x40db00
// 0053923f  83c418               add esp, 0x18
// 00539242  894608               mov dword ptr [esi + 8], eax
// 00539245  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00539248  5f                   pop edi
// 00539249  8bc6                 mov eax, esi
// 0053924b  5e                   pop esi
// 0053924c  64890d00000000       mov dword ptr fs:[0], ecx
// 00539253  5b                   pop ebx
// 00539254  8be5                 mov esp, ebp
// 00539256  5d                   pop ebp
// 00539257  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
