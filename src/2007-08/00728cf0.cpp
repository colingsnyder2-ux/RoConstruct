// from server: 100% by auto
// roc 2007-08 00728cf0  unit: boost::signals::detail::Ubasic_connection::?$sp_counted_impl_p  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00728cf0
//
// 00728cf0  6a28                 push 0x28
// 00728cf2  e8ff71f0ff           call 0x62fef6
// 00728cf7  83c404               add esp, 4
// 00728cfa  85c0                 test eax, eax
// 00728cfc  7406                 je 0x728d04
// 00728cfe  c70000000000         mov dword ptr [eax], 0
// 00728d04  8d4804               lea ecx, [eax + 4]
// 00728d07  85c9                 test ecx, ecx
// 00728d09  7406                 je 0x728d11
// 00728d0b  c70100000000         mov dword ptr [ecx], 0
// 00728d11  8d4808               lea ecx, [eax + 8]
// 00728d14  85c9                 test ecx, ecx
// 00728d16  7406                 je 0x728d1e
// 00728d18  c70100000000         mov dword ptr [ecx], 0
// 00728d1e  c6402401             mov byte ptr [eax + 0x24], 1
// 00728d22  c6402500             mov byte ptr [eax + 0x25], 0
// 00728d26  c3                   ret 
// standard library set<pod24> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
