// from server: 92% by atomic.potato
// roc 2010-06 0067ac10  unit: RBX::VPseudoPlayer::?$BoundFuncDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0067ac10
//
// 0067ac10  8b442404             mov eax, dword ptr [esp + 4]
// 0067ac14  8b4808               mov ecx, dword ptr [eax + 8]
// 0067ac17  80793100             cmp byte ptr [ecx + 0x71], 0
// 0067ac1b  750e                 jne 0x67aacb
// 0067ac1d  8d4900               lea ecx, [ecx]
// 0067ac20  8bc1                 mov eax, ecx
// 0067ac22  8b4808               mov ecx, dword ptr [eax + 8]
// 0067ac25  80793100             cmp byte ptr [ecx + 0x71], 0
// 0067ac29  74f5                 je 0x67aac0
// 0067ac2b  c3                   ret 
// standard library set<pod36> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;