// from server: 100% by auto
// roc 2009-12 00486da0  unit: Ogre::GfxClustererPart  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00486da0
//
// 00486da0  53                   push ebx
// 00486da1  56                   push esi
// 00486da2  57                   push edi
// 00486da3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00486da7  807f2900             cmp byte ptr [edi + 0x29], 0
// 00486dab  8bd9                 mov ebx, ecx
// 00486dad  8bf7                 mov esi, edi
// 00486daf  7527                 jne 0x486dd8
// 00486db1  8b4608               mov eax, dword ptr [esi + 8]
// 00486db4  50                   push eax
// 00486db5  8bcb                 mov ecx, ebx
// 00486db7  e8e4ffffff           call 0x486da0
// 00486dbc  8b36                 mov esi, dword ptr [esi]
// 00486dbe  8d4f0c               lea ecx, [edi + 0xc]
// 00486dc1  ff15e4b69800         call dword ptr [0x98b6e4]
// 00486dc7  57                   push edi
// 00486dc8  e88dca3600           call 0x7f385a
// 00486dcd  83c404               add esp, 4
// 00486dd0  807e2900             cmp byte ptr [esi + 0x29], 0
// 00486dd4  8bfe                 mov edi, esi
// 00486dd6  74d9                 je 0x486db1
// 00486dd8  5f                   pop edi
// 00486dd9  5e                   pop esi
// 00486dda  5b                   pop ebx
// 00486ddb  c20400               ret 4
// standard library set<string> (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
