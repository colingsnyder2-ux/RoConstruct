// from server: 100% by auto
// roc 2009-06 0048bc10  unit: Ogre::RbxManualTextureLoader  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048bc10
//
// 0048bc10  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0048bc13  56                   push esi
// 0048bc14  8b7004               mov esi, dword ptr [eax + 4]
// 0048bc17  807e6900             cmp byte ptr [esi + 0x69], 0
// 0048bc1b  57                   push edi
// 0048bc1c  8bf8                 mov edi, eax
// 0048bc1e  7531                 jne 0x48bc51
// 0048bc20  53                   push ebx
// 0048bc21  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0048bc25  55                   push ebp
// 0048bc26  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 0048bc2c  8d642400             lea esp, [esp]
// 0048bc30  8d460c               lea eax, [esi + 0xc]
// 0048bc33  53                   push ebx
// 0048bc34  50                   push eax
// 0048bc35  ffd5                 call ebp
// 0048bc37  83c408               add esp, 8
// 0048bc3a  84c0                 test al, al
// 0048bc3c  7405                 je 0x48bc43
// 0048bc3e  8b7608               mov esi, dword ptr [esi + 8]
// 0048bc41  eb04                 jmp 0x48bc47
// 0048bc43  8bfe                 mov edi, esi
// 0048bc45  8b36                 mov esi, dword ptr [esi]
// 0048bc47  807e6900             cmp byte ptr [esi + 0x69], 0
// 0048bc4b  74e3                 je 0x48bc30
// 0048bc4d  5d                   pop ebp
// 0048bc4e  8bc7                 mov eax, edi
// 0048bc50  5b                   pop ebx
// 0048bc51  5f                   pop edi
// 0048bc52  5e                   pop esi
// 0048bc53  c20400               ret 4
// standard library map_str<pod64> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
