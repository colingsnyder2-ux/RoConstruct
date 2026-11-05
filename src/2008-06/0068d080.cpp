// from server: 100% by auto
// roc 2008-06 0068d080  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d080
//
// 0068d080  8b442404             mov eax, dword ptr [esp + 4]
// 0068d084  8b08                 mov ecx, dword ptr [eax]
// 0068d086  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0068d08a  750e                 jne 0x68d09a
// 0068d08c  8d642400             lea esp, [esp]
// 0068d090  8bc1                 mov eax, ecx
// 0068d092  8b08                 mov ecx, dword ptr [eax]
// 0068d094  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0068d098  74f6                 je 0x68d090
// 0068d09a  c3                   ret 
// standard library set<pod32> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
