// from server: 100% by auto
// roc 2008-06 00589190  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00589190
//
// 00589190  6aff                 push -1
// 00589192  68e8727d00           push 0x7d72e8
// 00589197  64a100000000         mov eax, dword ptr fs:[0]
// 0058919d  50                   push eax
// 0058919e  64892500000000       mov dword ptr fs:[0], esp
// 005891a5  51                   push ecx
// 005891a6  56                   push esi
// 005891a7  8bf1                 mov esi, ecx
// 005891a9  6a04                 push 4
// 005891ab  89742408             mov dword ptr [esp + 8], esi
// 005891af  e86c771100           call 0x6a0920
// 005891b4  83c404               add esp, 4
// 005891b7  85c0                 test eax, eax
// 005891b9  7404                 je 0x5891bf
// 005891bb  8930                 mov dword ptr [eax], esi
// 005891bd  eb02                 jmp 0x5891c1
// 005891bf  33c0                 xor eax, eax
// 005891c1  8906                 mov dword ptr [esi], eax
// 005891c3  8bce                 mov ecx, esi
// 005891c5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005891cd  e85e870000           call 0x591930
// 005891d2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005891d6  894618               mov dword ptr [esi + 0x18], eax
// 005891d9  c6401901             mov byte ptr [eax + 0x19], 1
// 005891dd  8b4618               mov eax, dword ptr [esi + 0x18]
// 005891e0  894004               mov dword ptr [eax + 4], eax
// 005891e3  8b4618               mov eax, dword ptr [esi + 0x18]
// 005891e6  8900                 mov dword ptr [eax], eax
// 005891e8  8b4618               mov eax, dword ptr [esi + 0x18]
// 005891eb  894008               mov dword ptr [eax + 8], eax
// 005891ee  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005891f5  8bc6                 mov eax, esi
// 005891f7  5e                   pop esi
// 005891f8  64890d00000000       mov dword ptr fs:[0], ecx
// 005891ff  83c410               add esp, 0x10
// 00589202  c20800               ret 8
// standard library set<double> (function ??0?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAE@ABU?$less@N@1@ABV?$allocator@N@1@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
