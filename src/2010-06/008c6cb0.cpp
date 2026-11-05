// from server: 100% by auto
// roc 2010-06 008c6cb0  unit: Ogre::VRbxFont::?$SharedPtr  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6cb0
//
// 008c6cb0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 008c6cb3  56                   push esi
// 008c6cb4  8b7004               mov esi, dword ptr [eax + 4]
// 008c6cb7  807e3900             cmp byte ptr [esi + 0x39], 0
// 008c6cbb  57                   push edi
// 008c6cbc  8bf8                 mov edi, eax
// 008c6cbe  7531                 jne 0x8c6cf1
// 008c6cc0  53                   push ebx
// 008c6cc1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008c6cc5  55                   push ebp
// 008c6cc6  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 008c6ccc  8d642400             lea esp, [esp]
// 008c6cd0  8d460c               lea eax, [esi + 0xc]
// 008c6cd3  53                   push ebx
// 008c6cd4  50                   push eax
// 008c6cd5  ffd5                 call ebp
// 008c6cd7  83c408               add esp, 8
// 008c6cda  84c0                 test al, al
// 008c6cdc  7405                 je 0x8c6ce3
// 008c6cde  8b7608               mov esi, dword ptr [esi + 8]
// 008c6ce1  eb04                 jmp 0x8c6ce7
// 008c6ce3  8bfe                 mov edi, esi
// 008c6ce5  8b36                 mov esi, dword ptr [esi]
// 008c6ce7  807e3900             cmp byte ptr [esi + 0x39], 0
// 008c6ceb  74e3                 je 0x8c6cd0
// 008c6ced  5d                   pop ebp
// 008c6cee  8bc7                 mov eax, edi
// 008c6cf0  5b                   pop ebx
// 008c6cf1  5f                   pop edi
// 008c6cf2  5e                   pop esi
// 008c6cf3  c20400               ret 4
// standard library map_str<pod16> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
