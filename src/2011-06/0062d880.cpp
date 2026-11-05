// from server: 100% by auto
// roc 2011-06 0062d880  unit: RBX::VStarterPackService::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0062d880
//
// 0062d880  6a18                 push 0x18
// 0062d882  e8d7c71d00           call 0x80a05e
// 0062d887  83c404               add esp, 4
// 0062d88a  85c0                 test eax, eax
// 0062d88c  7406                 je 0x62d894
// 0062d88e  c70000000000         mov dword ptr [eax], 0
// 0062d894  8d4804               lea ecx, [eax + 4]
// 0062d897  85c9                 test ecx, ecx
// 0062d899  7406                 je 0x62d8a1
// 0062d89b  c70100000000         mov dword ptr [ecx], 0
// 0062d8a1  8d4808               lea ecx, [eax + 8]
// 0062d8a4  85c9                 test ecx, ecx
// 0062d8a6  7406                 je 0x62d8ae
// 0062d8a8  c70100000000         mov dword ptr [ecx], 0
// 0062d8ae  c6401401             mov byte ptr [eax + 0x14], 1
// 0062d8b2  c6401500             mov byte ptr [eax + 0x15], 0
// 0062d8b6  c3                   ret 
// standard library set<pod8> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
