// from server: 100% by auto
// roc 2010-06 0065b250  unit: RBX::KeyframeSequence  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065b250
//
// 0065b250  8b442404             mov eax, dword ptr [esp + 4]
// 0065b254  8b08                 mov ecx, dword ptr [eax]
// 0065b256  80793100             cmp byte ptr [ecx + 0x31], 0
// 0065b25a  750e                 jne 0x65b26a
// 0065b25c  8d642400             lea esp, [esp]
// 0065b260  8bc1                 mov eax, ecx
// 0065b262  8b08                 mov ecx, dword ptr [eax]
// 0065b264  80793100             cmp byte ptr [ecx + 0x31], 0
// 0065b268  74f6                 je 0x65b260
// 0065b26a  c3                   ret 
// standard library set<pod36> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
