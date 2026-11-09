// from server: 100% by auto
// roc 2009-12 0068ae10  unit: TextXmlParser  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068ae10
//
// 0068ae10  8b442404             mov eax, dword ptr [esp + 4]
// 0068ae14  8b4808               mov ecx, dword ptr [eax + 8]
// 0068ae17  80793100             cmp byte ptr [ecx + 0x31], 0
// 0068ae1b  750e                 jne 0x68ae2b
// 0068ae1d  8d4900               lea ecx, [ecx]
// 0068ae20  8bc1                 mov eax, ecx
// 0068ae22  8b4808               mov ecx, dword ptr [eax + 8]
// 0068ae25  80793100             cmp byte ptr [ecx + 0x31], 0
// 0068ae29  74f5                 je 0x68ae20
// 0068ae2b  c3                   ret 
// standard library set<pod36> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
