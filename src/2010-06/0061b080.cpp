// from server: 100% by auto
// roc 2010-06 0061b080  unit: RBX::Accoutrement  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061b080
//
// 0061b080  8b442404             mov eax, dword ptr [esp + 4]
// 0061b084  8b4808               mov ecx, dword ptr [eax + 8]
// 0061b087  80792100             cmp byte ptr [ecx + 0x21], 0
// 0061b08b  750e                 jne 0x61b09b
// 0061b08d  8d4900               lea ecx, [ecx]
// 0061b090  8bc1                 mov eax, ecx
// 0061b092  8b4808               mov ecx, dword ptr [eax + 8]
// 0061b095  80792100             cmp byte ptr [ecx + 0x21], 0
// 0061b099  74f5                 je 0x61b090
// 0061b09b  c3                   ret 
// standard library set<pod20> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
