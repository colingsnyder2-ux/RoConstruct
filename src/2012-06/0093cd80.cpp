// from server: 100% by auto
// roc 2012-06 0093cd80  unit: RBX::ChatLine  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0093cd80
//
// 0093cd80  6a40                 push 0x40
// 0093cd82  e893530400           call 0x98211a
// 0093cd87  83c404               add esp, 4
// 0093cd8a  85c0                 test eax, eax
// 0093cd8c  7406                 je 0x93cd94
// 0093cd8e  c70000000000         mov dword ptr [eax], 0
// 0093cd94  8d4804               lea ecx, [eax + 4]
// 0093cd97  85c9                 test ecx, ecx
// 0093cd99  7406                 je 0x93cda1
// 0093cd9b  c70100000000         mov dword ptr [ecx], 0
// 0093cda1  8d4808               lea ecx, [eax + 8]
// 0093cda4  85c9                 test ecx, ecx
// 0093cda6  7406                 je 0x93cdae
// 0093cda8  c70100000000         mov dword ptr [ecx], 0
// 0093cdae  c6403c01             mov byte ptr [eax + 0x3c], 1
// 0093cdb2  c6403d00             mov byte ptr [eax + 0x3d], 0
// 0093cdb6  c3                   ret 
// standard library set<pod48> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
