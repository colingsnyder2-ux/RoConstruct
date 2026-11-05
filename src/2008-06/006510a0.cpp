// from server: 100% by auto
// roc 2008-06 006510a0  unit: RBX::ScoreHud  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006510a0
//
// 006510a0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 006510a3  56                   push esi
// 006510a4  8b7004               mov esi, dword ptr [eax + 4]
// 006510a7  807e4900             cmp byte ptr [esi + 0x49], 0
// 006510ab  57                   push edi
// 006510ac  8bf8                 mov edi, eax
// 006510ae  7531                 jne 0x6510e1
// 006510b0  53                   push ebx
// 006510b1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006510b5  55                   push ebp
// 006510b6  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 006510bc  8d642400             lea esp, [esp]
// 006510c0  8d460c               lea eax, [esi + 0xc]
// 006510c3  53                   push ebx
// 006510c4  50                   push eax
// 006510c5  ffd5                 call ebp
// 006510c7  83c408               add esp, 8
// 006510ca  84c0                 test al, al
// 006510cc  7405                 je 0x6510d3
// 006510ce  8b7608               mov esi, dword ptr [esi + 8]
// 006510d1  eb04                 jmp 0x6510d7
// 006510d3  8bfe                 mov edi, esi
// 006510d5  8b36                 mov esi, dword ptr [esi]
// 006510d7  807e4900             cmp byte ptr [esi + 0x49], 0
// 006510db  74e3                 je 0x6510c0
// 006510dd  5d                   pop ebp
// 006510de  8bc7                 mov eax, edi
// 006510e0  5b                   pop ebx
// 006510e1  5f                   pop edi
// 006510e2  5e                   pop esi
// 006510e3  c20400               ret 4
// standard library map_str<pod32> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
