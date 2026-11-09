// from server: 100% by auto
// roc 2010-06 0076f930  unit: RBX::ScoreHud  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076f930
//
// 0076f930  6aff                 push -1
// 0076f932  6858a29900           push 0x99a258
// 0076f937  64a100000000         mov eax, dword ptr fs:[0]
// 0076f93d  50                   push eax
// 0076f93e  64892500000000       mov dword ptr fs:[0], esp
// 0076f945  51                   push ecx
// 0076f946  56                   push esi
// 0076f947  8bf1                 mov esi, ecx
// 0076f949  6a04                 push 4
// 0076f94b  89742408             mov dword ptr [esp + 8], esi
// 0076f94f  e84c800300           call 0x7a79a0
// 0076f954  83c404               add esp, 4
// 0076f957  85c0                 test eax, eax
// 0076f959  7404                 je 0x76f95f
// 0076f95b  8930                 mov dword ptr [eax], esi
// 0076f95d  eb02                 jmp 0x76f961
// 0076f95f  33c0                 xor eax, eax
// 0076f961  8906                 mov dword ptr [esi], eax
// 0076f963  8bce                 mov ecx, esi
// 0076f965  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0076f96d  e8fefcffff           call 0x76f670
// 0076f972  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0076f976  894618               mov dword ptr [esi + 0x18], eax
// 0076f979  c6404901             mov byte ptr [eax + 0x49], 1
// 0076f97d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076f980  894004               mov dword ptr [eax + 4], eax
// 0076f983  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076f986  8900                 mov dword ptr [eax], eax
// 0076f988  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076f98b  894008               mov dword ptr [eax + 8], eax
// 0076f98e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0076f995  8bc6                 mov eax, esi
// 0076f997  5e                   pop esi
// 0076f998  64890d00000000       mov dword ptr fs:[0], ecx
// 0076f99f  83c410               add esp, 0x10
// 0076f9a2  c20800               ret 8
// standard library map_str<pod32> (function ??0?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@1@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
