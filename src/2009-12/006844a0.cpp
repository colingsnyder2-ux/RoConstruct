// from server: 100% by auto
// roc 2009-12 006844a0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006844a0
//
// 006844a0  6aff                 push -1
// 006844a2  68d8c59300           push 0x93c5d8
// 006844a7  64a100000000         mov eax, dword ptr fs:[0]
// 006844ad  50                   push eax
// 006844ae  64892500000000       mov dword ptr fs:[0], esp
// 006844b5  51                   push ecx
// 006844b6  56                   push esi
// 006844b7  8bf1                 mov esi, ecx
// 006844b9  6a04                 push 4
// 006844bb  89742408             mov dword ptr [esp + 8], esi
// 006844bf  e89cf31600           call 0x7f3860
// 006844c4  83c404               add esp, 4
// 006844c7  85c0                 test eax, eax
// 006844c9  7404                 je 0x6844cf
// 006844cb  8930                 mov dword ptr [eax], esi
// 006844cd  eb02                 jmp 0x6844d1
// 006844cf  33c0                 xor eax, eax
// 006844d1  8906                 mov dword ptr [esi], eax
// 006844d3  8bce                 mov ecx, esi
// 006844d5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006844dd  e84e221400           call 0x7c6730
// 006844e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006844e6  894618               mov dword ptr [esi + 0x18], eax
// 006844e9  c6404901             mov byte ptr [eax + 0x49], 1
// 006844ed  8b4618               mov eax, dword ptr [esi + 0x18]
// 006844f0  894004               mov dword ptr [eax + 4], eax
// 006844f3  8b4618               mov eax, dword ptr [esi + 0x18]
// 006844f6  8900                 mov dword ptr [eax], eax
// 006844f8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006844fb  894008               mov dword ptr [eax + 8], eax
// 006844fe  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00684505  8bc6                 mov eax, esi
// 00684507  5e                   pop esi
// 00684508  64890d00000000       mov dword ptr fs:[0], ecx
// 0068450f  83c410               add esp, 0x10
// 00684512  c20800               ret 8
// standard library map_str<pod32> (function ??0?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@1@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
