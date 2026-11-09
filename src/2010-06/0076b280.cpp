// from server: 100% by auto
// roc 2010-06 0076b280  unit: RBX::ImageButton  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076b280
//
// 0076b280  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0076b283  56                   push esi
// 0076b284  8b7004               mov esi, dword ptr [eax + 4]
// 0076b287  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 0076b28b  57                   push edi
// 0076b28c  8bf8                 mov edi, eax
// 0076b28e  7531                 jne 0x76b2c1
// 0076b290  53                   push ebx
// 0076b291  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0076b295  55                   push ebp
// 0076b296  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 0076b29c  8d642400             lea esp, [esp]
// 0076b2a0  8d460c               lea eax, [esi + 0xc]
// 0076b2a3  53                   push ebx
// 0076b2a4  50                   push eax
// 0076b2a5  ffd5                 call ebp
// 0076b2a7  83c408               add esp, 8
// 0076b2aa  84c0                 test al, al
// 0076b2ac  7405                 je 0x76b2b3
// 0076b2ae  8b7608               mov esi, dword ptr [esi + 8]
// 0076b2b1  eb04                 jmp 0x76b2b7
// 0076b2b3  8bfe                 mov edi, esi
// 0076b2b5  8b36                 mov esi, dword ptr [esi]
// 0076b2b7  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 0076b2bb  74e3                 je 0x76b2a0
// 0076b2bd  5d                   pop ebp
// 0076b2be  8bc7                 mov eax, edi
// 0076b2c0  5b                   pop ebx
// 0076b2c1  5f                   pop edi
// 0076b2c2  5e                   pop esi
// 0076b2c3  c20400               ret 4
// standard library map_str<pod36> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod36>
struct E { int v[9]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
