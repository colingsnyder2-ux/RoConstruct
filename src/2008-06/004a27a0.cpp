// from server: 100% by auto
// roc 2008-06 004a27a0  unit: RBX::Network::VServer::?$FactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a27a0
//
// 004a27a0  53                   push ebx
// 004a27a1  56                   push esi
// 004a27a2  57                   push edi
// 004a27a3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a27a7  807f2900             cmp byte ptr [edi + 0x29], 0
// 004a27ab  8bd9                 mov ebx, ecx
// 004a27ad  8bf7                 mov esi, edi
// 004a27af  7527                 jne 0x4a27d8
// 004a27b1  8b4608               mov eax, dword ptr [esi + 8]
// 004a27b4  50                   push eax
// 004a27b5  8bcb                 mov ecx, ebx
// 004a27b7  e8e4ffffff           call 0x4a27a0
// 004a27bc  8b36                 mov esi, dword ptr [esi]
// 004a27be  8d4f0c               lea ecx, [edi + 0xc]
// 004a27c1  ff1568248000         call dword ptr [0x802468]
// 004a27c7  57                   push edi
// 004a27c8  e8adde1f00           call 0x6a067a
// 004a27cd  83c404               add esp, 4
// 004a27d0  807e2900             cmp byte ptr [esi + 0x29], 0
// 004a27d4  8bfe                 mov edi, esi
// 004a27d6  74d9                 je 0x4a27b1
// 004a27d8  5f                   pop edi
// 004a27d9  5e                   pop esi
// 004a27da  5b                   pop ebx
// 004a27db  c20400               ret 4
// standard library set<string> (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
