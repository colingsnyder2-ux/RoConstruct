// from server: 100% by auto
// roc 2009-06 005d9a60  unit: RBX::MD5HasherImpl  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d9a60
//
// 005d9a60  8b4118               mov eax, dword ptr [ecx + 0x18]
// 005d9a63  56                   push esi
// 005d9a64  8b7004               mov esi, dword ptr [eax + 4]
// 005d9a67  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 005d9a6b  57                   push edi
// 005d9a6c  8bf8                 mov edi, eax
// 005d9a6e  7531                 jne 0x5d9aa1
// 005d9a70  53                   push ebx
// 005d9a71  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005d9a75  55                   push ebp
// 005d9a76  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 005d9a7c  8d642400             lea esp, [esp]
// 005d9a80  8d460c               lea eax, [esi + 0xc]
// 005d9a83  53                   push ebx
// 005d9a84  50                   push eax
// 005d9a85  ffd5                 call ebp
// 005d9a87  83c408               add esp, 8
// 005d9a8a  84c0                 test al, al
// 005d9a8c  7405                 je 0x5d9a93
// 005d9a8e  8b7608               mov esi, dword ptr [esi + 8]
// 005d9a91  eb04                 jmp 0x5d9a97
// 005d9a93  8bfe                 mov edi, esi
// 005d9a95  8b36                 mov esi, dword ptr [esi]
// 005d9a97  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 005d9a9b  74e3                 je 0x5d9a80
// 005d9a9d  5d                   pop ebp
// 005d9a9e  8bc7                 mov eax, edi
// 005d9aa0  5b                   pop ebx
// 005d9aa1  5f                   pop edi
// 005d9aa2  5e                   pop esi
// 005d9aa3  c20400               ret 4
// standard library map_str<pod20> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
