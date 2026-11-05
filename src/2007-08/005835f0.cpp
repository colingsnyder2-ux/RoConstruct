// from server: 100% by auto
// roc 2007-08 005835f0  unit: RBX::VHat::?$FactoryProduct  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005835f0
//
// 005835f0  53                   push ebx
// 005835f1  56                   push esi
// 005835f2  57                   push edi
// 005835f3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005835f7  807f2100             cmp byte ptr [edi + 0x21], 0
// 005835fb  8bd9                 mov ebx, ecx
// 005835fd  8bf7                 mov esi, edi
// 005835ff  751e                 jne 0x58361f
// 00583601  8b4608               mov eax, dword ptr [esi + 8]
// 00583604  50                   push eax
// 00583605  8bcb                 mov ecx, ebx
// 00583607  e8e4ffffff           call 0x5835f0
// 0058360c  8b36                 mov esi, dword ptr [esi]
// 0058360e  57                   push edi
// 0058360f  e84ec60a00           call 0x62fc62
// 00583614  83c404               add esp, 4
// 00583617  807e2100             cmp byte ptr [esi + 0x21], 0
// 0058361b  8bfe                 mov edi, esi
// 0058361d  74e2                 je 0x583601
// 0058361f  5f                   pop edi
// 00583620  5e                   pop esi
// 00583621  5b                   pop ebx
// 00583622  c20400               ret 4
// standard library set<pod20> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
