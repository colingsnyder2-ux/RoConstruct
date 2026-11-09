// from server: 100% by auto
// roc 2012-06 00455700  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00455700
//
// 00455700  8b442404             mov eax, dword ptr [esp + 4]
// 00455704  8b4808               mov ecx, dword ptr [eax + 8]
// 00455707  80792100             cmp byte ptr [ecx + 0x21], 0
// 0045570b  750e                 jne 0x45571b
// 0045570d  8d4900               lea ecx, [ecx]
// 00455710  8bc1                 mov eax, ecx
// 00455712  8b4808               mov ecx, dword ptr [eax + 8]
// 00455715  80792100             cmp byte ptr [ecx + 0x21], 0
// 00455719  74f5                 je 0x455710
// 0045571b  c3                   ret 
// standard library set<pod20> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
