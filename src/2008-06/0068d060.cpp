// from server: 100% by auto
// roc 2008-06 0068d060  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d060
//
// 0068d060  8b442404             mov eax, dword ptr [esp + 4]
// 0068d064  8b4808               mov ecx, dword ptr [eax + 8]
// 0068d067  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0068d06b  750e                 jne 0x68d07b
// 0068d06d  8d4900               lea ecx, [ecx]
// 0068d070  8bc1                 mov eax, ecx
// 0068d072  8b4808               mov ecx, dword ptr [eax + 8]
// 0068d075  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0068d079  74f5                 je 0x68d070
// 0068d07b  c3                   ret 
// standard library set<pod32> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
