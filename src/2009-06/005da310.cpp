// from server: 100% by auto
// roc 2009-06 005da310  unit: RBX::ContentProvider::HashApprovalDictionary::VValue::?$sp_counted_impl_p  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005da310
//
// 005da310  6a40                 push 0x40
// 005da312  e821e71300           call 0x718a38
// 005da317  83c404               add esp, 4
// 005da31a  85c0                 test eax, eax
// 005da31c  7406                 je 0x5da324
// 005da31e  c70000000000         mov dword ptr [eax], 0
// 005da324  8d4804               lea ecx, [eax + 4]
// 005da327  85c9                 test ecx, ecx
// 005da329  7406                 je 0x5da331
// 005da32b  c70100000000         mov dword ptr [ecx], 0
// 005da331  8d4808               lea ecx, [eax + 8]
// 005da334  85c9                 test ecx, ecx
// 005da336  7406                 je 0x5da33e
// 005da338  c70100000000         mov dword ptr [ecx], 0
// 005da33e  c6403c01             mov byte ptr [eax + 0x3c], 1
// 005da342  c6403d00             mov byte ptr [eax + 0x3d], 0
// 005da346  c3                   ret 
// standard library set<pod48> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
