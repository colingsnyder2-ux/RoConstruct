// from server: 100% by auto
// roc 2007-08 00542c10  unit: RBX::VInstance::?$SignalDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00542c10
//
// 00542c10  8b442404             mov eax, dword ptr [esp + 4]
// 00542c14  8b4808               mov ecx, dword ptr [eax + 8]
// 00542c17  80791500             cmp byte ptr [ecx + 0x15], 0
// 00542c1b  750e                 jne 0x542c2b
// 00542c1d  8d4900               lea ecx, [ecx]
// 00542c20  8bc1                 mov eax, ecx
// 00542c22  8b4808               mov ecx, dword ptr [eax + 8]
// 00542c25  80791500             cmp byte ptr [ecx + 0x15], 0
// 00542c29  74f5                 je 0x542c20
// 00542c2b  c3                   ret 
// standard library set<pod8> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
