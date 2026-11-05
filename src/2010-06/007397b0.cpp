// from server: 100% by auto
// roc 2010-06 007397b0  unit: seg_00730000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007397b0
//
// 007397b0  8b442404             mov eax, dword ptr [esp + 4]
// 007397b4  8b4808               mov ecx, dword ptr [eax + 8]
// 007397b7  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 007397bb  750e                 jne 0x7397cb
// 007397bd  8d4900               lea ecx, [ecx]
// 007397c0  8bc1                 mov eax, ecx
// 007397c2  8b4808               mov ecx, dword ptr [eax + 8]
// 007397c5  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 007397c9  74f5                 je 0x7397c0
// 007397cb  c3                   ret 
// standard library set<pod32> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
