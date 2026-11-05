// from server: 100% by auto
// roc 2009-06 00476e90  unit: Ogre::RbxMeshLoader  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00476e90
//
// 00476e90  53                   push ebx
// 00476e91  56                   push esi
// 00476e92  57                   push edi
// 00476e93  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00476e97  807f2900             cmp byte ptr [edi + 0x29], 0
// 00476e9b  8bd9                 mov ebx, ecx
// 00476e9d  8bf7                 mov esi, edi
// 00476e9f  7527                 jne 0x476ec8
// 00476ea1  8b4608               mov eax, dword ptr [esi + 8]
// 00476ea4  50                   push eax
// 00476ea5  8bcb                 mov ecx, ebx
// 00476ea7  e8e4ffffff           call 0x476e90
// 00476eac  8b36                 mov esi, dword ptr [esi]
// 00476eae  8d4f0c               lea ecx, [edi + 0xc]
// 00476eb1  ff15c4e48900         call dword ptr [0x89e4c4]
// 00476eb7  57                   push edi
// 00476eb8  e8751b2a00           call 0x718a32
// 00476ebd  83c404               add esp, 4
// 00476ec0  807e2900             cmp byte ptr [esi + 0x29], 0
// 00476ec4  8bfe                 mov edi, esi
// 00476ec6  74d9                 je 0x476ea1
// 00476ec8  5f                   pop edi
// 00476ec9  5e                   pop esi
// 00476eca  5b                   pop ebx
// 00476ecb  c20400               ret 4
// standard library set<string> (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
