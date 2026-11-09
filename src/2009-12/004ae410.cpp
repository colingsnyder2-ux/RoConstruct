// from server: 100% by auto
// roc 2009-12 004ae410  unit: Ogre::RbxManualTextureLoader  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ae410
//
// 004ae410  8b4118               mov eax, dword ptr [ecx + 0x18]
// 004ae413  56                   push esi
// 004ae414  8b7004               mov esi, dword ptr [eax + 4]
// 004ae417  807e6900             cmp byte ptr [esi + 0x69], 0
// 004ae41b  57                   push edi
// 004ae41c  8bf8                 mov edi, eax
// 004ae41e  7531                 jne 0x4ae451
// 004ae420  53                   push ebx
// 004ae421  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004ae425  55                   push ebp
// 004ae426  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 004ae42c  8d642400             lea esp, [esp]
// 004ae430  8d460c               lea eax, [esi + 0xc]
// 004ae433  53                   push ebx
// 004ae434  50                   push eax
// 004ae435  ffd5                 call ebp
// 004ae437  83c408               add esp, 8
// 004ae43a  84c0                 test al, al
// 004ae43c  7405                 je 0x4ae443
// 004ae43e  8b7608               mov esi, dword ptr [esi + 8]
// 004ae441  eb04                 jmp 0x4ae447
// 004ae443  8bfe                 mov edi, esi
// 004ae445  8b36                 mov esi, dword ptr [esi]
// 004ae447  807e6900             cmp byte ptr [esi + 0x69], 0
// 004ae44b  74e3                 je 0x4ae430
// 004ae44d  5d                   pop ebp
// 004ae44e  8bc7                 mov eax, edi
// 004ae450  5b                   pop ebx
// 004ae451  5f                   pop edi
// 004ae452  5e                   pop esi
// 004ae453  c20400               ret 4
// standard library map_str<pod64> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
