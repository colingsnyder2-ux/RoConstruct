// from server: 100% by auto
// roc 2010-06 005f2610  unit: TextXmlParser  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005f2610
//
// 005f2610  8b442404             mov eax, dword ptr [esp + 4]
// 005f2614  8b4808               mov ecx, dword ptr [eax + 8]
// 005f2617  80791900             cmp byte ptr [ecx + 0x19], 0
// 005f261b  750e                 jne 0x5f262b
// 005f261d  8d4900               lea ecx, [ecx]
// 005f2620  8bc1                 mov eax, ecx
// 005f2622  8b4808               mov ecx, dword ptr [eax + 8]
// 005f2625  80791900             cmp byte ptr [ecx + 0x19], 0
// 005f2629  74f5                 je 0x5f2620
// 005f262b  c3                   ret 
// standard library set<double> (function ?_Max@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
