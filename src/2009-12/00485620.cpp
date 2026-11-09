// from server: 100% by auto
// roc 2009-12 00485620  unit: Ogre::GfxClustererPart  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00485620
//
// 00485620  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00485623  56                   push esi
// 00485624  8b7004               mov esi, dword ptr [eax + 4]
// 00485627  807e4500             cmp byte ptr [esi + 0x45], 0
// 0048562b  57                   push edi
// 0048562c  8bf8                 mov edi, eax
// 0048562e  7531                 jne 0x485661
// 00485630  53                   push ebx
// 00485631  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00485635  55                   push ebp
// 00485636  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 0048563c  8d642400             lea esp, [esp]
// 00485640  8d460c               lea eax, [esi + 0xc]
// 00485643  53                   push ebx
// 00485644  50                   push eax
// 00485645  ffd5                 call ebp
// 00485647  83c408               add esp, 8
// 0048564a  84c0                 test al, al
// 0048564c  7405                 je 0x485653
// 0048564e  8b7608               mov esi, dword ptr [esi + 8]
// 00485651  eb04                 jmp 0x485657
// 00485653  8bfe                 mov edi, esi
// 00485655  8b36                 mov esi, dword ptr [esi]
// 00485657  807e4500             cmp byte ptr [esi + 0x45], 0
// 0048565b  74e3                 je 0x485640
// 0048565d  5d                   pop ebp
// 0048565e  8bc7                 mov eax, edi
// 00485660  5b                   pop ebx
// 00485661  5f                   pop edi
// 00485662  5e                   pop esi
// 00485663  c20400               ret 4
// standard library map_str<string> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
