// from server: 100% by auto
// roc 2009-06 004cf4f0  unit: XVCrashReporter::XV?$mf1::V?$bind_t::?$thread_data  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004cf4f0
//
// 004cf4f0  8b442404             mov eax, dword ptr [esp + 4]
// 004cf4f4  8b4808               mov ecx, dword ptr [eax + 8]
// 004cf4f7  80791500             cmp byte ptr [ecx + 0x15], 0
// 004cf4fb  750e                 jne 0x4cf50b
// 004cf4fd  8d4900               lea ecx, [ecx]
// 004cf500  8bc1                 mov eax, ecx
// 004cf502  8b4808               mov ecx, dword ptr [eax + 8]
// 004cf505  80791500             cmp byte ptr [ecx + 0x15], 0
// 004cf509  74f5                 je 0x4cf500
// 004cf50b  c3                   ret 
// standard library set<pod8> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
