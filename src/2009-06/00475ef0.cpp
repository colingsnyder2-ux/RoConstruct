// from server: 100% by auto
// roc 2009-06 00475ef0  unit: Ogre::RbxMeshLoader  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00475ef0
//
// 00475ef0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00475ef3  56                   push esi
// 00475ef4  8b7004               mov esi, dword ptr [eax + 4]
// 00475ef7  807e4500             cmp byte ptr [esi + 0x45], 0
// 00475efb  57                   push edi
// 00475efc  8bf8                 mov edi, eax
// 00475efe  7531                 jne 0x475f31
// 00475f00  53                   push ebx
// 00475f01  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00475f05  55                   push ebp
// 00475f06  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 00475f0c  8d642400             lea esp, [esp]
// 00475f10  8d460c               lea eax, [esi + 0xc]
// 00475f13  53                   push ebx
// 00475f14  50                   push eax
// 00475f15  ffd5                 call ebp
// 00475f17  83c408               add esp, 8
// 00475f1a  84c0                 test al, al
// 00475f1c  7405                 je 0x475f23
// 00475f1e  8b7608               mov esi, dword ptr [esi + 8]
// 00475f21  eb04                 jmp 0x475f27
// 00475f23  8bfe                 mov edi, esi
// 00475f25  8b36                 mov esi, dword ptr [esi]
// 00475f27  807e4500             cmp byte ptr [esi + 0x45], 0
// 00475f2b  74e3                 je 0x475f10
// 00475f2d  5d                   pop ebp
// 00475f2e  8bc7                 mov eax, edi
// 00475f30  5b                   pop ebx
// 00475f31  5f                   pop edi
// 00475f32  5e                   pop esi
// 00475f33  c20400               ret 4
// standard library map_str<string> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
