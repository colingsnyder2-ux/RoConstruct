// from server: 100% by auto
// roc 2009-06 006fca90  unit: Ogre::VRbxFont::?$SharedPtr  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fca90
//
// 006fca90  8b4118               mov eax, dword ptr [ecx + 0x18]
// 006fca93  56                   push esi
// 006fca94  8b7004               mov esi, dword ptr [eax + 4]
// 006fca97  807e3500             cmp byte ptr [esi + 0x35], 0
// 006fca9b  57                   push edi
// 006fca9c  8bf8                 mov edi, eax
// 006fca9e  7531                 jne 0x6fcad1
// 006fcaa0  53                   push ebx
// 006fcaa1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006fcaa5  55                   push ebp
// 006fcaa6  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 006fcaac  8d642400             lea esp, [esp]
// 006fcab0  8d460c               lea eax, [esi + 0xc]
// 006fcab3  53                   push ebx
// 006fcab4  50                   push eax
// 006fcab5  ffd5                 call ebp
// 006fcab7  83c408               add esp, 8
// 006fcaba  84c0                 test al, al
// 006fcabc  7405                 je 0x6fcac3
// 006fcabe  8b7608               mov esi, dword ptr [esi + 8]
// 006fcac1  eb04                 jmp 0x6fcac7
// 006fcac3  8bfe                 mov edi, esi
// 006fcac5  8b36                 mov esi, dword ptr [esi]
// 006fcac7  807e3500             cmp byte ptr [esi + 0x35], 0
// 006fcacb  74e3                 je 0x6fcab0
// 006fcacd  5d                   pop ebp
// 006fcace  8bc7                 mov eax, edi
// 006fcad0  5b                   pop ebx
// 006fcad1  5f                   pop edi
// 006fcad2  5e                   pop esi
// 006fcad3  c20400               ret 4
// standard library map_str<pod12> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
