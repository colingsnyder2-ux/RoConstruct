// from server: 100% by auto
// roc 2008-06 005892b0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005892b0
//
// 005892b0  6aff                 push -1
// 005892b2  68e8727d00           push 0x7d72e8
// 005892b7  64a100000000         mov eax, dword ptr fs:[0]
// 005892bd  50                   push eax
// 005892be  64892500000000       mov dword ptr fs:[0], esp
// 005892c5  51                   push ecx
// 005892c6  56                   push esi
// 005892c7  8bf1                 mov esi, ecx
// 005892c9  6a04                 push 4
// 005892cb  89742408             mov dword ptr [esp + 8], esi
// 005892cf  e84c761100           call 0x6a0920
// 005892d4  83c404               add esp, 4
// 005892d7  85c0                 test eax, eax
// 005892d9  7404                 je 0x5892df
// 005892db  8930                 mov dword ptr [eax], esi
// 005892dd  eb02                 jmp 0x5892e1
// 005892df  33c0                 xor eax, eax
// 005892e1  8906                 mov dword ptr [esi], eax
// 005892e3  8bce                 mov ecx, esi
// 005892e5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005892ed  e8dee3ffff           call 0x5876d0
// 005892f2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005892f6  894618               mov dword ptr [esi + 0x18], eax
// 005892f9  c6404901             mov byte ptr [eax + 0x49], 1
// 005892fd  8b4618               mov eax, dword ptr [esi + 0x18]
// 00589300  894004               mov dword ptr [eax + 4], eax
// 00589303  8b4618               mov eax, dword ptr [esi + 0x18]
// 00589306  8900                 mov dword ptr [eax], eax
// 00589308  8b4618               mov eax, dword ptr [esi + 0x18]
// 0058930b  894008               mov dword ptr [eax + 8], eax
// 0058930e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00589315  8bc6                 mov eax, esi
// 00589317  5e                   pop esi
// 00589318  64890d00000000       mov dword ptr fs:[0], ecx
// 0058931f  83c410               add esp, 0x10
// 00589322  c20800               ret 8
// standard library map_str<pod32> (function ??0?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@1@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
