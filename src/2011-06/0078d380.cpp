// from server: 100% by auto
// roc 2011-06 0078d380  unit: RBX::UniversalTool  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078d380
//
// 0078d380  6a14                 push 0x14
// 0078d382  e8d7cc0700           call 0x80a05e
// 0078d387  83c404               add esp, 4
// 0078d38a  85c0                 test eax, eax
// 0078d38c  7406                 je 0x78d394
// 0078d38e  c70000000000         mov dword ptr [eax], 0
// 0078d394  8d4804               lea ecx, [eax + 4]
// 0078d397  85c9                 test ecx, ecx
// 0078d399  7406                 je 0x78d3a1
// 0078d39b  c70100000000         mov dword ptr [ecx], 0
// 0078d3a1  8d4808               lea ecx, [eax + 8]
// 0078d3a4  85c9                 test ecx, ecx
// 0078d3a6  7406                 je 0x78d3ae
// 0078d3a8  c70100000000         mov dword ptr [ecx], 0
// 0078d3ae  c6401001             mov byte ptr [eax + 0x10], 1
// 0078d3b2  c6401100             mov byte ptr [eax + 0x11], 0
// 0078d3b6  c3                   ret 
// standard library set<ptr> (function ?_Buynode@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
