// from server: 100% by auto
// roc 2012-06 005caeb0  unit: Ogre::istreamDataStream  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005caeb0
//
// 005caeb0  8b442404             mov eax, dword ptr [esp + 4]
// 005caeb4  8b4808               mov ecx, dword ptr [eax + 8]
// 005caeb7  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005caebb  750e                 jne 0x5caecb
// 005caebd  8d4900               lea ecx, [ecx]
// 005caec0  8bc1                 mov eax, ecx
// 005caec2  8b4808               mov ecx, dword ptr [eax + 8]
// 005caec5  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005caec9  74f5                 je 0x5caec0
// 005caecb  c3                   ret 
// standard library set<pod32> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
