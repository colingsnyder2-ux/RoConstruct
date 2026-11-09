// from server: 100% by auto
// roc 2012-06 008773b0  unit: DummyJob  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008773b0
//
// 008773b0  8b442404             mov eax, dword ptr [esp + 4]
// 008773b4  8b4808               mov ecx, dword ptr [eax + 8]
// 008773b7  80790e00             cmp byte ptr [ecx + 0xe], 0
// 008773bb  750e                 jne 0x8773cb
// 008773bd  8d4900               lea ecx, [ecx]
// 008773c0  8bc1                 mov eax, ecx
// 008773c2  8b4808               mov ecx, dword ptr [eax + 8]
// 008773c5  80790e00             cmp byte ptr [ecx + 0xe], 0
// 008773c9  74f5                 je 0x8773c0
// 008773cb  c3                   ret 
// standard library set<char> (function ?_Max@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
