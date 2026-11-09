// from server: 100% by auto
// roc 2009-12 00631dc0  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00631dc0
//
// 00631dc0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00631dc3  56                   push esi
// 00631dc4  8b7004               mov esi, dword ptr [eax + 4]
// 00631dc7  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00631dcb  57                   push edi
// 00631dcc  8bf8                 mov edi, eax
// 00631dce  7531                 jne 0x631e01
// 00631dd0  53                   push ebx
// 00631dd1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00631dd5  55                   push ebp
// 00631dd6  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 00631ddc  8d642400             lea esp, [esp]
// 00631de0  8d460c               lea eax, [esi + 0xc]
// 00631de3  53                   push ebx
// 00631de4  50                   push eax
// 00631de5  ffd5                 call ebp
// 00631de7  83c408               add esp, 8
// 00631dea  84c0                 test al, al
// 00631dec  7405                 je 0x631df3
// 00631dee  8b7608               mov esi, dword ptr [esi + 8]
// 00631df1  eb04                 jmp 0x631df7
// 00631df3  8bfe                 mov edi, esi
// 00631df5  8b36                 mov esi, dword ptr [esi]
// 00631df7  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00631dfb  74e3                 je 0x631de0
// 00631dfd  5d                   pop ebp
// 00631dfe  8bc7                 mov eax, edi
// 00631e00  5b                   pop ebx
// 00631e01  5f                   pop edi
// 00631e02  5e                   pop esi
// 00631e03  c20400               ret 4
// standard library map_str<ptr> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
