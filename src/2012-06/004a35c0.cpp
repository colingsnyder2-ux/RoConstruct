// from server: 100% by auto
// roc 2012-06 004a35c0  unit: CRobloxScriptReviewPaneView  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a35c0
//
// 004a35c0  8b442404             mov eax, dword ptr [esp + 4]
// 004a35c4  8b4808               mov ecx, dword ptr [eax + 8]
// 004a35c7  80793100             cmp byte ptr [ecx + 0x31], 0
// 004a35cb  750e                 jne 0x4a35db
// 004a35cd  8d4900               lea ecx, [ecx]
// 004a35d0  8bc1                 mov eax, ecx
// 004a35d2  8b4808               mov ecx, dword ptr [eax + 8]
// 004a35d5  80793100             cmp byte ptr [ecx + 0x31], 0
// 004a35d9  74f5                 je 0x4a35d0
// 004a35db  c3                   ret 
// standard library set<pod36> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
