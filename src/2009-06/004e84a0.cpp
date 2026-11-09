// from server: 100% by auto
// roc 2009-06 004e84a0  unit: RBX::JointsService  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e84a0
//
// 004e84a0  6aff                 push -1
// 004e84a2  6878ef8600           push 0x86ef78
// 004e84a7  64a100000000         mov eax, dword ptr fs:[0]
// 004e84ad  50                   push eax
// 004e84ae  64892500000000       mov dword ptr fs:[0], esp
// 004e84b5  51                   push ecx
// 004e84b6  56                   push esi
// 004e84b7  8bf1                 mov esi, ecx
// 004e84b9  6a04                 push 4
// 004e84bb  89742408             mov dword ptr [esp + 8], esi
// 004e84bf  e874052300           call 0x718a38
// 004e84c4  83c404               add esp, 4
// 004e84c7  85c0                 test eax, eax
// 004e84c9  7404                 je 0x4e84cf
// 004e84cb  8930                 mov dword ptr [eax], esi
// 004e84cd  eb02                 jmp 0x4e84d1
// 004e84cf  33c0                 xor eax, eax
// 004e84d1  8906                 mov dword ptr [esi], eax
// 004e84d3  8bce                 mov ecx, esi
// 004e84d5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004e84dd  e84e3b1100           call 0x5fc030
// 004e84e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004e84e6  894618               mov dword ptr [esi + 0x18], eax
// 004e84e9  c6401901             mov byte ptr [eax + 0x19], 1
// 004e84ed  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e84f0  894004               mov dword ptr [eax + 4], eax
// 004e84f3  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e84f6  8900                 mov dword ptr [eax], eax
// 004e84f8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e84fb  894008               mov dword ptr [eax + 8], eax
// 004e84fe  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004e8505  8bc6                 mov eax, esi
// 004e8507  5e                   pop esi
// 004e8508  64890d00000000       mov dword ptr fs:[0], ecx
// 004e850f  83c410               add esp, 0x10
// 004e8512  c20800               ret 8
// standard library set<double> (function ??0?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAE@ABU?$less@N@1@ABV?$allocator@N@1@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
