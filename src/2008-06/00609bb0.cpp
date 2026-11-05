// from server: 100% by auto
// roc 2008-06 00609bb0  unit: RBX::Controller::W4ControllerType::?$EnumDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00609bb0
//
// 00609bb0  8b442404             mov eax, dword ptr [esp + 4]
// 00609bb4  8b4808               mov ecx, dword ptr [eax + 8]
// 00609bb7  80791500             cmp byte ptr [ecx + 0x15], 0
// 00609bbb  750e                 jne 0x609bcb
// 00609bbd  8d4900               lea ecx, [ecx]
// 00609bc0  8bc1                 mov eax, ecx
// 00609bc2  8b4808               mov ecx, dword ptr [eax + 8]
// 00609bc5  80791500             cmp byte ptr [ecx + 0x15], 0
// 00609bc9  74f5                 je 0x609bc0
// 00609bcb  c3                   ret 
// standard library set<pod8> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
