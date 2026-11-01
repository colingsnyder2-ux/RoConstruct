// from server: 100% by auto
// roc 2009-12 005325a0  unit: G3D::Ray  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005325a0
//
// 005325a0  8b442404             mov eax, dword ptr [esp + 4]
// 005325a4  8b4808               mov ecx, dword ptr [eax + 8]
// 005325a7  80791500             cmp byte ptr [ecx + 0x15], 0
// 005325ab  750e                 jne 0x5325bb
// 005325ad  8d4900               lea ecx, [ecx]
// 005325b0  8bc1                 mov eax, ecx
// 005325b2  8b4808               mov ecx, dword ptr [eax + 8]
// 005325b5  80791500             cmp byte ptr [ecx + 0x15], 0
// 005325b9  74f5                 je 0x5325b0
// 005325bb  c3                   ret 
// standard library set<pod8> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
