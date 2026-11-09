// from server: 100% by auto
// roc 2008-06 0066fed0  unit: Ogre::VRbxFont::?$SharedPtr  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066fed0
//
// 0066fed0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0066fed3  56                   push esi
// 0066fed4  8b7004               mov esi, dword ptr [eax + 4]
// 0066fed7  807e3500             cmp byte ptr [esi + 0x35], 0
// 0066fedb  57                   push edi
// 0066fedc  8bf8                 mov edi, eax
// 0066fede  7531                 jne 0x66ff11
// 0066fee0  53                   push ebx
// 0066fee1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0066fee5  55                   push ebp
// 0066fee6  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 0066feec  8d642400             lea esp, [esp]
// 0066fef0  8d460c               lea eax, [esi + 0xc]
// 0066fef3  53                   push ebx
// 0066fef4  50                   push eax
// 0066fef5  ffd5                 call ebp
// 0066fef7  83c408               add esp, 8
// 0066fefa  84c0                 test al, al
// 0066fefc  7405                 je 0x66ff03
// 0066fefe  8b7608               mov esi, dword ptr [esi + 8]
// 0066ff01  eb04                 jmp 0x66ff07
// 0066ff03  8bfe                 mov edi, esi
// 0066ff05  8b36                 mov esi, dword ptr [esi]
// 0066ff07  807e3500             cmp byte ptr [esi + 0x35], 0
// 0066ff0b  74e3                 je 0x66fef0
// 0066ff0d  5d                   pop ebp
// 0066ff0e  8bc7                 mov eax, edi
// 0066ff10  5b                   pop ebx
// 0066ff11  5f                   pop edi
// 0066ff12  5e                   pop esi
// 0066ff13  c20400               ret 4
// standard library map_str<pod12> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
