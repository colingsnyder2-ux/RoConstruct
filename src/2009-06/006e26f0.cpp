// from server: 100% by auto
// roc 2009-06 006e26f0  unit: RBX::ScoreHud  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e26f0
//
// 006e26f0  6aff                 push -1
// 006e26f2  6878ef8600           push 0x86ef78
// 006e26f7  64a100000000         mov eax, dword ptr fs:[0]
// 006e26fd  50                   push eax
// 006e26fe  64892500000000       mov dword ptr fs:[0], esp
// 006e2705  51                   push ecx
// 006e2706  56                   push esi
// 006e2707  8bf1                 mov esi, ecx
// 006e2709  6a04                 push 4
// 006e270b  89742408             mov dword ptr [esp + 8], esi
// 006e270f  e824630300           call 0x718a38
// 006e2714  83c404               add esp, 4
// 006e2717  85c0                 test eax, eax
// 006e2719  7404                 je 0x6e271f
// 006e271b  8930                 mov dword ptr [eax], esi
// 006e271d  eb02                 jmp 0x6e2721
// 006e271f  33c0                 xor eax, eax
// 006e2721  8906                 mov dword ptr [esi], eax
// 006e2723  8bce                 mov ecx, esi
// 006e2725  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006e272d  e83efcffff           call 0x6e2370
// 006e2732  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006e2736  894618               mov dword ptr [esi + 0x18], eax
// 006e2739  c6404901             mov byte ptr [eax + 0x49], 1
// 006e273d  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e2740  894004               mov dword ptr [eax + 4], eax
// 006e2743  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e2746  8900                 mov dword ptr [eax], eax
// 006e2748  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e274b  894008               mov dword ptr [eax + 8], eax
// 006e274e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006e2755  8bc6                 mov eax, esi
// 006e2757  5e                   pop esi
// 006e2758  64890d00000000       mov dword ptr fs:[0], ecx
// 006e275f  83c410               add esp, 0x10
// 006e2762  c20800               ret 8
// standard library map_str<pod32> (function ??0?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@1@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
