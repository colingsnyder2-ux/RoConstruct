// from server: 100% by auto
// roc 2007-03 006080b0  unit: seg_00600000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006080b0
//
// 006080b0  8b4104               mov eax, dword ptr [ecx + 4]
// 006080b3  56                   push esi
// 006080b4  8b7004               mov esi, dword ptr [eax + 4]
// 006080b7  807e3500             cmp byte ptr [esi + 0x35], 0
// 006080bb  57                   push edi
// 006080bc  8bf8                 mov edi, eax
// 006080be  7531                 jne 0x6080f1
// 006080c0  53                   push ebx
// 006080c1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006080c5  55                   push ebp
// 006080c6  8b2de0e67700         mov ebp, dword ptr [0x77e6e0]
// 006080cc  8d642400             lea esp, [esp]
// 006080d0  8d460c               lea eax, [esi + 0xc]
// 006080d3  53                   push ebx
// 006080d4  50                   push eax
// 006080d5  ffd5                 call ebp
// 006080d7  83c408               add esp, 8
// 006080da  84c0                 test al, al
// 006080dc  7405                 je 0x6080e3
// 006080de  8b7608               mov esi, dword ptr [esi + 8]
// 006080e1  eb04                 jmp 0x6080e7
// 006080e3  8bfe                 mov edi, esi
// 006080e5  8b36                 mov esi, dword ptr [esi]
// 006080e7  807e3500             cmp byte ptr [esi + 0x35], 0
// 006080eb  74e3                 je 0x6080d0
// 006080ed  5d                   pop ebp
// 006080ee  8bc7                 mov eax, edi
// 006080f0  5b                   pop ebx
// 006080f1  5f                   pop edi
// 006080f2  5e                   pop esi
// 006080f3  c20400               ret 4
// standard library map_str<pod12> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
