// from server: 100% by auto
// roc 2009-06 006e2180  unit: RBX::ScoreHud  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2180
//
// 006e2180  8b4118               mov eax, dword ptr [ecx + 0x18]
// 006e2183  56                   push esi
// 006e2184  8b7004               mov esi, dword ptr [eax + 4]
// 006e2187  807e4900             cmp byte ptr [esi + 0x49], 0
// 006e218b  57                   push edi
// 006e218c  8bf8                 mov edi, eax
// 006e218e  7531                 jne 0x6e21c1
// 006e2190  53                   push ebx
// 006e2191  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006e2195  55                   push ebp
// 006e2196  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 006e219c  8d642400             lea esp, [esp]
// 006e21a0  8d460c               lea eax, [esi + 0xc]
// 006e21a3  53                   push ebx
// 006e21a4  50                   push eax
// 006e21a5  ffd5                 call ebp
// 006e21a7  83c408               add esp, 8
// 006e21aa  84c0                 test al, al
// 006e21ac  7405                 je 0x6e21b3
// 006e21ae  8b7608               mov esi, dword ptr [esi + 8]
// 006e21b1  eb04                 jmp 0x6e21b7
// 006e21b3  8bfe                 mov edi, esi
// 006e21b5  8b36                 mov esi, dword ptr [esi]
// 006e21b7  807e4900             cmp byte ptr [esi + 0x49], 0
// 006e21bb  74e3                 je 0x6e21a0
// 006e21bd  5d                   pop ebp
// 006e21be  8bc7                 mov eax, edi
// 006e21c0  5b                   pop ebx
// 006e21c1  5f                   pop edi
// 006e21c2  5e                   pop esi
// 006e21c3  c20400               ret 4
// standard library map_str<pod32> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
