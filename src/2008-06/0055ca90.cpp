// from server: 100% by auto
// roc 2008-06 0055ca90  unit: RBX::MD5HasherImpl  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055ca90
//
// 0055ca90  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0055ca93  56                   push esi
// 0055ca94  8b7004               mov esi, dword ptr [eax + 4]
// 0055ca97  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 0055ca9b  57                   push edi
// 0055ca9c  8bf8                 mov edi, eax
// 0055ca9e  7531                 jne 0x55cad1
// 0055caa0  53                   push ebx
// 0055caa1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0055caa5  55                   push ebp
// 0055caa6  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 0055caac  8d642400             lea esp, [esp]
// 0055cab0  8d460c               lea eax, [esi + 0xc]
// 0055cab3  53                   push ebx
// 0055cab4  50                   push eax
// 0055cab5  ffd5                 call ebp
// 0055cab7  83c408               add esp, 8
// 0055caba  84c0                 test al, al
// 0055cabc  7405                 je 0x55cac3
// 0055cabe  8b7608               mov esi, dword ptr [esi + 8]
// 0055cac1  eb04                 jmp 0x55cac7
// 0055cac3  8bfe                 mov edi, esi
// 0055cac5  8b36                 mov esi, dword ptr [esi]
// 0055cac7  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 0055cacb  74e3                 je 0x55cab0
// 0055cacd  5d                   pop ebp
// 0055cace  8bc7                 mov eax, edi
// 0055cad0  5b                   pop ebx
// 0055cad1  5f                   pop edi
// 0055cad2  5e                   pop esi
// 0055cad3  c20400               ret 4
// standard library map_str<pod20> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
