// from server: 100% by auto
// roc 2009-12 0047eef0  unit: Ogre::VRbxFont::?$SharedPtr  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047eef0
//
// 0047eef0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0047eef3  56                   push esi
// 0047eef4  8b7004               mov esi, dword ptr [eax + 4]
// 0047eef7  807e3900             cmp byte ptr [esi + 0x39], 0
// 0047eefb  57                   push edi
// 0047eefc  8bf8                 mov edi, eax
// 0047eefe  7531                 jne 0x47ef31
// 0047ef00  53                   push ebx
// 0047ef01  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0047ef05  55                   push ebp
// 0047ef06  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 0047ef0c  8d642400             lea esp, [esp]
// 0047ef10  8d460c               lea eax, [esi + 0xc]
// 0047ef13  53                   push ebx
// 0047ef14  50                   push eax
// 0047ef15  ffd5                 call ebp
// 0047ef17  83c408               add esp, 8
// 0047ef1a  84c0                 test al, al
// 0047ef1c  7405                 je 0x47ef23
// 0047ef1e  8b7608               mov esi, dword ptr [esi + 8]
// 0047ef21  eb04                 jmp 0x47ef27
// 0047ef23  8bfe                 mov edi, esi
// 0047ef25  8b36                 mov esi, dword ptr [esi]
// 0047ef27  807e3900             cmp byte ptr [esi + 0x39], 0
// 0047ef2b  74e3                 je 0x47ef10
// 0047ef2d  5d                   pop ebp
// 0047ef2e  8bc7                 mov eax, edi
// 0047ef30  5b                   pop ebx
// 0047ef31  5f                   pop edi
// 0047ef32  5e                   pop esi
// 0047ef33  c20400               ret 4
// standard library map_str<pod16> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
