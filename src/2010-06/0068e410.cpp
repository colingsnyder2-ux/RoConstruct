// from server: 100% by auto
// roc 2010-06 0068e410  unit: RBX::InstanceLocksmith  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0068e410
//
// 0068e410  6aff                 push -1
// 0068e412  6858a29900           push 0x99a258
// 0068e417  64a100000000         mov eax, dword ptr fs:[0]
// 0068e41d  50                   push eax
// 0068e41e  64892500000000       mov dword ptr fs:[0], esp
// 0068e425  51                   push ecx
// 0068e426  56                   push esi
// 0068e427  8bf1                 mov esi, ecx
// 0068e429  6a04                 push 4
// 0068e42b  89742408             mov dword ptr [esp + 8], esi
// 0068e42f  e86c951100           call 0x7a79a0
// 0068e434  83c404               add esp, 4
// 0068e437  85c0                 test eax, eax
// 0068e439  7404                 je 0x68e43f
// 0068e43b  8930                 mov dword ptr [eax], esi
// 0068e43d  eb02                 jmp 0x68e441
// 0068e43f  33c0                 xor eax, eax
// 0068e441  8906                 mov dword ptr [esi], eax
// 0068e443  8bce                 mov ecx, esi
// 0068e445  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0068e44d  e8cef6ffff           call 0x68db20
// 0068e452  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0068e456  894618               mov dword ptr [esi + 0x18], eax
// 0068e459  c6402901             mov byte ptr [eax + 0x29], 1
// 0068e45d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0068e460  894004               mov dword ptr [eax + 4], eax
// 0068e463  8b4618               mov eax, dword ptr [esi + 0x18]
// 0068e466  8900                 mov dword ptr [eax], eax
// 0068e468  8b4618               mov eax, dword ptr [esi + 0x18]
// 0068e46b  894008               mov dword ptr [eax + 8], eax
// 0068e46e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0068e475  8bc6                 mov eax, esi
// 0068e477  5e                   pop esi
// 0068e478  64890d00000000       mov dword ptr fs:[0], ecx
// 0068e47f  83c410               add esp, 0x10
// 0068e482  c20800               ret 8
// standard library set<string> (function ??0?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
