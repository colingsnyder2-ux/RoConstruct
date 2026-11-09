// from server: 100% by auto
// roc 2009-06 006e2670  unit: RBX::ScoreHud  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2670
//
// 006e2670  6aff                 push -1
// 006e2672  6878ef8600           push 0x86ef78
// 006e2677  64a100000000         mov eax, dword ptr fs:[0]
// 006e267d  50                   push eax
// 006e267e  64892500000000       mov dword ptr fs:[0], esp
// 006e2685  51                   push ecx
// 006e2686  56                   push esi
// 006e2687  8bf1                 mov esi, ecx
// 006e2689  6a04                 push 4
// 006e268b  89742408             mov dword ptr [esp + 8], esi
// 006e268f  e8a4630300           call 0x718a38
// 006e2694  83c404               add esp, 4
// 006e2697  85c0                 test eax, eax
// 006e2699  7404                 je 0x6e269f
// 006e269b  8930                 mov dword ptr [eax], esi
// 006e269d  eb02                 jmp 0x6e26a1
// 006e269f  33c0                 xor eax, eax
// 006e26a1  8906                 mov dword ptr [esi], eax
// 006e26a3  8bce                 mov ecx, esi
// 006e26a5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006e26ad  e82e64e3ff           call 0x518ae0
// 006e26b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006e26b6  894618               mov dword ptr [esi + 0x18], eax
// 006e26b9  c6402901             mov byte ptr [eax + 0x29], 1
// 006e26bd  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e26c0  894004               mov dword ptr [eax + 4], eax
// 006e26c3  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e26c6  8900                 mov dword ptr [eax], eax
// 006e26c8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e26cb  894008               mov dword ptr [eax + 8], eax
// 006e26ce  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006e26d5  8bc6                 mov eax, esi
// 006e26d7  5e                   pop esi
// 006e26d8  64890d00000000       mov dword ptr fs:[0], ecx
// 006e26df  83c410               add esp, 0x10
// 006e26e2  c20800               ret 8
// standard library set<string> (function ??0?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
