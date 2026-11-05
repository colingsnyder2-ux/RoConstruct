// from server: 100% by auto
// roc 2009-06 00637940  unit: RBX::VScriptContext::?$FactoryProduct  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00637940
//
// 00637940  55                   push ebp
// 00637941  8bec                 mov ebp, esp
// 00637943  6aff                 push -1
// 00637945  68989d8600           push 0x869d98
// 0063794a  64a100000000         mov eax, dword ptr fs:[0]
// 00637950  50                   push eax
// 00637951  64892500000000       mov dword ptr fs:[0], esp
// 00637958  83ec0c               sub esp, 0xc
// 0063795b  53                   push ebx
// 0063795c  56                   push esi
// 0063795d  57                   push edi
// 0063795e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00637961  8bf1                 mov esi, ecx
// 00637963  6a04                 push 4
// 00637965  8975e8               mov dword ptr [ebp - 0x18], esi
// 00637968  e8cb100e00           call 0x718a38
// 0063796d  33c9                 xor ecx, ecx
// 0063796f  83c404               add esp, 4
// 00637972  3bc1                 cmp eax, ecx
// 00637974  7404                 je 0x63797a
// 00637976  8930                 mov dword ptr [eax], esi
// 00637978  eb02                 jmp 0x63797c
// 0063797a  33c0                 xor eax, eax
// 0063797c  8906                 mov dword ptr [esi], eax
// 0063797e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00637981  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 00637984  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 00637987  894dfc               mov dword ptr [ebp - 4], ecx
// 0063798a  c1ff03               sar edi, 3
// 0063798d  894e0c               mov dword ptr [esi + 0xc], ecx
// 00637990  894e10               mov dword ptr [esi + 0x10], ecx
// 00637993  894e14               mov dword ptr [esi + 0x14], ecx
// 00637996  3bf9                 cmp edi, ecx
// 00637998  746a                 je 0x637a04
// 0063799a  81ffffffff1f         cmp edi, 0x1fffffff
// 006379a0  7605                 jbe 0x6379a7
// 006379a2  e8b989e5ff           call 0x490360
// 006379a7  51                   push ecx
// 006379a8  57                   push edi
// 006379a9  e842d5e4ff           call 0x484ef0
// 006379ae  89460c               mov dword ptr [esi + 0xc], eax
// 006379b1  894610               mov dword ptr [esi + 0x10], eax
// 006379b4  8d04f8               lea eax, [eax + edi*8]
// 006379b7  894614               mov dword ptr [esi + 0x14], eax
// 006379ba  8b4310               mov eax, dword ptr [ebx + 0x10]
// 006379bd  83c408               add esp, 8
// 006379c0  c645fc01             mov byte ptr [ebp - 4], 1
// 006379c4  8945ec               mov dword ptr [ebp - 0x14], eax
// 006379c7  39430c               cmp dword ptr [ebx + 0xc], eax
// 006379ca  7606                 jbe 0x6379d2
// 006379cc  ff15ace98900         call dword ptr [0x89e9ac]
// 006379d2  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 006379d5  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 006379d8  7606                 jbe 0x6379e0
// 006379da  ff15ace98900         call dword ptr [0x89e9ac]
// 006379e0  8b460c               mov eax, dword ptr [esi + 0xc]
// 006379e3  c6450800             mov byte ptr [ebp + 8], 0
// 006379e7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006379ea  8b5508               mov edx, dword ptr [ebp + 8]
// 006379ed  51                   push ecx
// 006379ee  52                   push edx
// 006379ef  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 006379f2  8d4e08               lea ecx, [esi + 8]
// 006379f5  51                   push ecx
// 006379f6  50                   push eax
// 006379f7  52                   push edx
// 006379f8  57                   push edi
// 006379f9  e802aedfff           call 0x432800
// 006379fe  83c418               add esp, 0x18
// 00637a01  894610               mov dword ptr [esi + 0x10], eax
// 00637a04  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00637a07  5f                   pop edi
// 00637a08  8bc6                 mov eax, esi
// 00637a0a  5e                   pop esi
// 00637a0b  64890d00000000       mov dword ptr fs:[0], ecx
// 00637a12  5b                   pop ebx
// 00637a13  8be5                 mov esp, ebp
// 00637a15  5d                   pop ebp
// 00637a16  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
