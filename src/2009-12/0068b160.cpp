// from server: 100% by auto
// roc 2009-12 0068b160  unit: TextXmlParser  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068b160
//
// 0068b160  6aff                 push -1
// 0068b162  68d8c59300           push 0x93c5d8
// 0068b167  64a100000000         mov eax, dword ptr fs:[0]
// 0068b16d  50                   push eax
// 0068b16e  64892500000000       mov dword ptr fs:[0], esp
// 0068b175  51                   push ecx
// 0068b176  56                   push esi
// 0068b177  8bf1                 mov esi, ecx
// 0068b179  6a04                 push 4
// 0068b17b  89742408             mov dword ptr [esp + 8], esi
// 0068b17f  e8dc861600           call 0x7f3860
// 0068b184  83c404               add esp, 4
// 0068b187  85c0                 test eax, eax
// 0068b189  7404                 je 0x68b18f
// 0068b18b  8930                 mov dword ptr [eax], esi
// 0068b18d  eb02                 jmp 0x68b191
// 0068b18f  33c0                 xor eax, eax
// 0068b191  8906                 mov dword ptr [esi], eax
// 0068b193  8bce                 mov ecx, esi
// 0068b195  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0068b19d  e82e89daff           call 0x433ad0
// 0068b1a2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0068b1a6  894618               mov dword ptr [esi + 0x18], eax
// 0068b1a9  c6401901             mov byte ptr [eax + 0x19], 1
// 0068b1ad  8b4618               mov eax, dword ptr [esi + 0x18]
// 0068b1b0  894004               mov dword ptr [eax + 4], eax
// 0068b1b3  8b4618               mov eax, dword ptr [esi + 0x18]
// 0068b1b6  8900                 mov dword ptr [eax], eax
// 0068b1b8  8b4618               mov eax, dword ptr [esi + 0x18]
// 0068b1bb  894008               mov dword ptr [eax + 8], eax
// 0068b1be  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0068b1c5  8bc6                 mov eax, esi
// 0068b1c7  5e                   pop esi
// 0068b1c8  64890d00000000       mov dword ptr fs:[0], ecx
// 0068b1cf  83c410               add esp, 0x10
// 0068b1d2  c20800               ret 8
// standard library set<double> (function ??0?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAE@ABU?$less@N@1@ABV?$allocator@N@1@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
