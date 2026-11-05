// from server: 100% by auto
// roc 2008-06 0068fff0  unit: Ogre::RbxSceneManagerFactory  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068fff0
//
// 0068fff0  53                   push ebx
// 0068fff1  56                   push esi
// 0068fff2  57                   push edi
// 0068fff3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0068fff7  807f0e00             cmp byte ptr [edi + 0xe], 0
// 0068fffb  8bd9                 mov ebx, ecx
// 0068fffd  8bf7                 mov esi, edi
// 0068ffff  751e                 jne 0x69001f
// 00690001  8b4608               mov eax, dword ptr [esi + 8]
// 00690004  50                   push eax
// 00690005  8bcb                 mov ecx, ebx
// 00690007  e8e4ffffff           call 0x68fff0
// 0069000c  8b36                 mov esi, dword ptr [esi]
// 0069000e  57                   push edi
// 0069000f  e866060100           call 0x6a067a
// 00690014  83c404               add esp, 4
// 00690017  807e0e00             cmp byte ptr [esi + 0xe], 0
// 0069001b  8bfe                 mov edi, esi
// 0069001d  74e2                 je 0x690001
// 0069001f  5f                   pop edi
// 00690020  5e                   pop esi
// 00690021  5b                   pop ebx
// 00690022  c20400               ret 4
// standard library set<char> (function ?_Erase@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
